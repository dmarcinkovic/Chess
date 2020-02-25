//
// Created by david on 02. 01. 2020..
//

#include "Knight.h"

Knight::Knight(int x, int y, PieceColor color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{width / 2, color == PieceColor::WHITE ?
                                  0 : height / 2, width / 6, height / 2};
}

void Knight::getAvailableMoves()
{
    constexpr std::array<int, 8> indices1 = {-2, 2, -2, 2, -1, 1, -1, 1};
    constexpr std::array<int, 8> indices2 = {1, 1, -1, -1, 2, 2, -2, -2};

    moves.clear();
    moves.insert(std::make_pair(destRect.x, destRect.y));

    for (int i = 0; i < indices1.size(); i++)
    {
        auto position = std::make_pair(destRect.x + indices1[i] * Board::width,
                                       destRect.y + indices2[i] * Board::height);

        addSquareIfNotOccupied(position);
        addSquareIfOccupied(position);
    }
}
