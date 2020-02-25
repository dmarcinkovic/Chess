//
// Created by david on 02. 01. 2020..
//

#include "Queen.h"

Queen::Queen(int x, int y, PieceColor color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{width / 6, color == PieceColor::WHITE ?
                                  0 : height / 2, width / 6, height / 2};
}

void Queen::getAvailableMoves()
{
    moves.clear();
    moves.emplace_back(std::make_pair(destRect.x, destRect.y));

    getDiagonalAvailableMoves();
    getHorizontalAvailableMoves();
}

void Queen::getDiagonalAvailableMoves()
{
    bool direction[] = {true, true, true, true};
    constexpr const int indices1[] = {-1, -1, 1, 1};
    constexpr const int indices2[] = {1, -1, 1, -1};

    insertMoves(direction, indices1, indices2, 4);
}

void Queen::getHorizontalAvailableMoves()
{
    bool direction[] = {true, true, true, true};
    constexpr const int indices1[] = {0, 0, 1, -1};
    constexpr const int indices2[] = {1, -1, 0, 0};
    insertMoves(direction, indices1, indices2, 4);
}
