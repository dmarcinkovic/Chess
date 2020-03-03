//
// Created by david on 02. 01. 2020..
//

#include "King.h"
#include "Rook.h"

King::King(int x, int y, const PieceColor &color)
        : Piece(x, y, color), moved(false)
{
    srcRect = SDL_Rect{0, color == PieceColor::WHITE ?
                          0 : height / 2, width / 6, height / 2};
}

void King::getAvailableMoves()
{
    moves.clear();

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;

            auto position = std::make_pair(destRect.x + i * Board::width,
                                           destRect.y + j * Board::height);
            addSquareIfOccupied(position);
            addSquareIfNotOccupied(position);
        }
    }

    addCastleMove();
}

void King::addCastleMove()
{
    addCastleMove(3, 'b', 'a', 'c');
    addCastleMove(2, 'f', 'h', 'g');
}

std::pair<int, int> King::getSquare(char col)
{
    std::string square = std::string(1, col) + (color == PieceColor::WHITE ? "1" : "8");
    return Board::getPosition(square.c_str());
}

bool King::checkSquaresInBetween(int numberOfSquares, char col)
{
    for (int i = 0; i < numberOfSquares; i++)
    {
        if (Board::occupied[getSquare((char) ((int) col + i))])
        {
            return false;
        }
    }

    return true;
}

void King::checkKingAndRook(char rookPosition, char newKingPosition)
{
    if (dynamic_cast<Rook *>(Board::occupied[getSquare(rookPosition)].get()) &&
        dynamic_cast<King *>(Board::occupied[getSquare('e')].get()))
    {
        moves.insert(getSquare(newKingPosition));
    }
}

void King::addCastleMove(int numberOfSquares, char col, char rookPosition, char newKingPosition)
{
    if (checkSquaresInBetween(numberOfSquares, col))
    {
        checkKingAndRook(rookPosition, newKingPosition);
    }
}

