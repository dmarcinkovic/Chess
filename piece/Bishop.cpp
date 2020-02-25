//
// Created by david on 02. 01. 2020..
//

#include <iostream>
#include "Bishop.h"

Bishop::Bishop(int x, int y, PieceColor color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{width / 3, color == PieceColor::WHITE ?
                                  0 : height / 2, width / 6, height / 2};
}

void Bishop::getAvailableMoves()
{
    moves.clear();

    bool direction[] = {true, true, true, true};
    constexpr const int indices1[] = {-1, -1, 1, 1};
    constexpr const int indices2[] = {1, -1, 1, -1};

    moves.insert(std::make_pair(destRect.x, destRect.y));
    insertMoves(direction, indices1, indices2, 4);
}
