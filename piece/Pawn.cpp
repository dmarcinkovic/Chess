//
// Created by david on 02. 01. 2020..
//

#include "Pawn.h"

Pawn::Pawn(int x, int y, PieceColor color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{5 * width / 6, color == PieceColor::WHITE ?
                                      0 : height / 2, width / 6, height / 2};
}

void Pawn::getAvailableMoves()
{
    moves.clear();
    moves.emplace_back(std::make_pair(destRect.x, destRect.y));

    if (!Board::flipped)
    {
        addSquares(PieceColor::WHITE);
    } else
    {
        addSquares(PieceColor::BLACK);
    }
}

void Pawn::addSquares(const char *chessSquare, int sign)
{
    addSquareIfNotOccupied(std::make_pair(destRect.x,
                                          destRect.y + sign * Board::height));

    if (destRect.y == Board::getPosition(chessSquare).second)
    {
        addSquareIfNotOccupied(std::make_pair(destRect.x,
                                              destRect.y + sign * 2 * Board::height));
    }
}

void Pawn::addSquares(const PieceColor &piecesDown)
{
    addTakingMove(piecesDown);
    if (color == piecesDown)
    {
        addSquares("a2", -1);
    } else
    {
        addSquares("a7", 1);
    }
}

void Pawn::addTakingMove(const PieceColor &piecesDown)
{
    if (piecesDown == color)
    {
        addTakingMove(-1);
    } else
    {
        addTakingMove(1);
    }
}

void Pawn::addTakingMove(int sign)
{
    auto position1 = std::make_pair(destRect.x - Board::width, destRect.y + sign * Board::height);
    auto position2 = std::make_pair(destRect.x + Board::width, destRect.y + sign * Board::height);

    addSquareIfOccupied(position1);
    addSquareIfOccupied(position2);
}
