//
// Created by david on 02. 01. 2020..
//

#include "Rook.h"

Rook::Rook(int x, int y, PieceColor color) : Piece(x, y, color)
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

    moves.emplace_back(std::make_pair(destRect.x, destRect.y));
    for (int i = 1; i < Board::numberOfSquares; i++)
    {
        int w = i * Board::width;
        int h = i * Board::height;

        insertMoves(direction, indices1, indices2, 4, w, h);
    }
}
