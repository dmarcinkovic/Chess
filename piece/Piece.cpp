//
// Created by david on 01. 01. 2020..
//

#include "Piece.h"
#include "../factory/Util.h"
#include "King.h"

int Piece::width, Piece::height;
SDL_Texture *Piece::piece;

Piece::Piece(int x, int y, const PieceColor &color)
        : color(color)
{
    if (piece == nullptr)
    {
        piece = Texture::loadTexture("resources/pieces.png", width, height);
    }

    destRect = SDL_Rect{x, y, Board::width, Board::height};
    prevDestRect = destRect;
}

void Piece::draw() const
{
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

void Piece::insertMoves(bool *direction, const int *indices1, const int *indices2, int size)
{
    for (int i = 1; i < Board::numberOfSquares; i++)
    {
        int w = i * Board::width;
        int h = i * Board::height;

        for (int j = 0; j < size; j++)
        {
            auto position = std::make_pair(destRect.x + indices1[j] * w, destRect.y + indices2[j] * h);
            if (!direction[j] || !Board::isInsideBoard(position))
            {
                continue;
            }

            auto p = Board::occupied[position];
            if (p == nullptr)
            {
                moves.insert(position);
            } else if (p->getPieceColor() != color)
            {
                moves.insert(position);
                direction[j] = false;
            } else
            {
                direction[j] = false;
            }
        }
    }
}

void Piece::addSquareIfNotOccupied(const std::pair<int, int> &position)
{
    if (Board::occupied[position] == nullptr && Board::isInsideBoard(position))
    {
        moves.insert(position);
    }
}

void Piece::addSquareIfOccupied(const std::pair<int, int> &position)
{
    auto p = Board::occupied[position];
    if (p && p->getPieceColor() != color)
    {
        moves.insert(position);
    }
}

bool Piece::isCorrectMove(int x, int y) const
{
    return moves.contains(Board::getAlignedPosition(x, y));
}

void Piece::returnMove()
{
    destRect = prevDestRect;
}

std::pair<int, int> Piece::getPosition() const
{
    return std::make_pair(destRect.x, destRect.y);
}

void Piece::updateMove()
{
    prevDestRect = destRect;
}

void Piece::findIntersection(Piece *attackingPiece)
{
    std::unordered_set<std::pair<int, int>, PairHash> newMoves{};

    for (auto const &move : attackingPiece->moves)
    {
        for (auto const &currentMove : moves)
        {
            if (move == currentMove)
            {
                newMoves.insert(move);
            }
        }
    }

    addTakingMove(attackingPiece, newMoves);
    moves = newMoves;
}

void Piece::addTakingMove(Piece *attackingPiece, std::unordered_set<std::pair<int, int>, PairHash> &newMoves)
{
    for (auto const &move : moves)
    {
        if (move == std::make_pair(attackingPiece->destRect.x, attackingPiece->destRect.y))
        {
            newMoves.insert(move);
            break;
        }
    }
}

void Piece::getAvailableMovesCheck(Piece *attackingPiece)
{
    findIntersection(attackingPiece);
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
        if (piece->mark) piece->markAvailableMoves();
    }

    for (auto &piece : pieces)
    {
        piece->draw();
    }
}

std::shared_ptr<Piece> *Pieces::getPiece(int x, int y)
{
    for (auto &piece: pieces)
    {
        if (piece->destRect.x < x && piece->destRect.x + piece->destRect.w > x
            && piece->destRect.y < y && piece->destRect.y + piece->destRect.h > y)
        {
            return &piece;
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
        Board::occupied[std::make_pair(x, y)] = pieces.back();
    }
}

constexpr void Pieces::addBlackPieces()
{
    for (auto &square : ChessSquares::getBlackPieces())
    {
        auto[x, y] = Board::getPosition(square);
        pieces.emplace_back(PieceFactory::getPiece(
                ChessSquares::getPieceType(square), x, y, PieceColor::BLACK));
        Board::occupied[std::make_pair(x, y)] = pieces.back();
    }
}

void Pieces::takePiece(const std::pair<int, int> &position)
{
    std::shared_ptr<Piece> piece{Board::occupied[position]};
    if (piece)
    {
        Board::occupied[piece->getPosition()] = nullptr;
        auto iterator = std::find(pieces.begin(), pieces.end(), piece);
        pieces.erase(iterator);
    }
}

bool Pieces::isCheck()
{
    pieceAttackKing.clear();

    for (auto &piece: pieces)
    {
        if (piece->color != Game::turn) continue;
        for (auto &square : piece->moves)
        {
            if (dynamic_cast<King *>(Board::occupied[square].get()))
            {
                pieceAttackKing.emplace_back(piece.get());
            }
        }
    }

    return !pieceAttackKing.empty();
}

bool Pieces::isStalemate()
{
    // TODO implement
    return false;
}

bool Pieces::isCheckmate()
{
    // TODO implement
    return false;
}

void Pieces::addObserver(ICheckObserver *observer)
{
    observers.emplace_back(observer);
}

void Pieces::notifyAll(Pieces *pieces1)
{
    std::for_each(observers.begin(), observers.end(), [&](ICheckObserver *observer) {
        observer->update(pieces1);
    });
}

