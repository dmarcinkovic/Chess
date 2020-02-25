//
// Created by david on 01. 01. 2020..
//

#include "Piece.h"
#include "../factory/Util.h"

int Piece::width, Piece::height;
SDL_Texture *Piece::piece;

Piece::Piece(int x, int y, PieceColor color)
        : color(color)
{
    if (piece == nullptr)
    {
        piece = Texture::loadTexture("resources/pieces.png", width, height);
    }

    destRect = SDL_Rect{x, y, Board::width, Board::height};
}

void Piece::draw() const
{
    if (mark) markAvailableMoves();
    SDL_RenderCopy(Game::renderer, piece, &srcRect, &destRect);
}

void Piece::setPosition(int x, int y)
{
    destRect.x = x - destRect.w / 2;
    destRect.y = y - destRect.h / 2;
}

void Piece::alignPiece(int x, int y)
{
    auto result = Board::getAlignedPosition(x, y);

    destRect.x = result.first;
    destRect.y = result.second;
}

void Piece::markAvailableMoves() const
{
    for (auto &position : moves)
    {
        SDL_Rect rect{position.first, position.second, Board::width, Board::height};
        SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(Game::renderer, &rect);
    }
}

void Piece::setMarkMoves(bool mark1)
{
    mark = mark1;
}

PieceColor Piece::getPieceColor() const
{
    return color;
}

void Piece::insertMoves(bool *direction, const int *indices1, const int *indices2, int size, int w, int h)
{
    for (int j = 0; j < size; j++)
    {
        auto position = std::make_pair(destRect.x + indices1[j] * w, destRect.y + indices2[j] * h);
        if (!direction[j] || !Board::isInsideBoard(position))
        {
            continue;
        }

        Piece *p = Board::occupied[position];
        if (p == nullptr)
        {
            moves.emplace_back(position);
        } else if (p->getPieceColor() != color)
        {
            moves.emplace_back(position);
            direction[j] = false;
        } else
        {
            direction[j] = false;
        }
    }
}


Pieces::Pieces()
{
    pieces.reserve(32);

    addPieces();
}

void Pieces::draw() const
{
    for (auto &piece : pieces)
    {
        piece->draw();
    }
}

Piece *Pieces::getPiece(int x, int y)
{
    for (auto &piece: pieces)
    {
        if (piece->destRect.x < x && piece->destRect.x + piece->destRect.w > x
            && piece->destRect.y < y && piece->destRect.y + piece->destRect.h > y)
        {
            return piece.get();
        }
    }

    return nullptr;
}

constexpr void Pieces::addPieces()
{
    addWhitePieces();
    addBlackPieces();
}

void Pieces::getAvailableMoves()
{
    for (auto &piece : pieces)
    {
        piece->getAvailableMoves();
    }
}

constexpr void Pieces::addWhitePieces()
{
    for (auto &square : ChessSquares::getWhitePieces())
    {
        auto[x, y] = Board::getPosition(square);
        pieces.emplace_back(PieceFactory::getPiece(
                ChessSquares::getPieceType(square), x, y, PieceColor::WHITE));
        Board::occupied[std::make_pair(x, y)] = pieces.back().get();
    }
}

constexpr void Pieces::addBlackPieces()
{
    for (auto &square : ChessSquares::getBlackPieces())
    {
        auto[x, y] = Board::getPosition(square);
        pieces.emplace_back(PieceFactory::getPiece(
                ChessSquares::getPieceType(square), x, y, PieceColor::BLACK));
        Board::occupied[std::make_pair(x, y)] = pieces.back().get();
    }
}

