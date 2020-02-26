//
// Created by david on 02. 01. 2020..
//

#include "Rook.h"

Rook::Rook(int x, int y, const PieceColor &color) : Piece(x, y, color)
{
    srcRect = SDL_Rect{2 * width / 3, color == PieceColor::WHITE ?
                                      0 : height / 2, width / 6, height / 2};
}

void Rook::getAvailableMoves()
{
    moves.clear();

    bool direction[] = {true, true, true, true};
    constexpr const int indices1[] = {0, 0, 1, -1};
    constexpr const int indices2[] = {1, -1, 0, 0};

    insertMoves(direction, indices1, indices2, 4);
}
