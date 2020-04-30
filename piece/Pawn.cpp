//
// Created by david on 02. 01. 2020..
//

#include "Pawn.h"

Pawn::Pawn(int x, int y, const PieceColor &color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{5 * width / 6, color == PieceColor::WHITE ?
                                      0 : height / 2, width / 6, height / 2};
}

void Pawn::getAvailableMoves()
{
    moves.clear();

    !Board::flipped ? addSquares(PieceColor::WHITE) : addSquares(PieceColor::BLACK);
}

void Pawn::addSquares(const char *chessSquare, int sign)
{
    auto position = std::make_pair(destRect.x, destRect.y + sign * Board::height);
    addSquareIfNotOccupied(position);

    if (destRect.y == Board::getPosition(chessSquare).second && !Board::occupied[position])
    {
        addSquareIfNotOccupied(std::make_pair(destRect.x,
                                              destRect.y + sign * 2 * Board::height));
    }
}

void Pawn::addSquares(const PieceColor &piecesDown)
{
    piecesDown == color ? addTakingMove(-1) : addTakingMove(1);

    color == piecesDown ? addSquares("a2", -1) : addSquares("a7", 1);
}

void Pawn::addTakingMove(int sign)
{
    auto position1 = std::make_pair(destRect.x - Board::width, destRect.y + sign * Board::height);
    auto position2 = std::make_pair(destRect.x + Board::width, destRect.y + sign * Board::height);

    addSquareIfOccupied(position1);
    addSquareIfOccupied(position2);
}