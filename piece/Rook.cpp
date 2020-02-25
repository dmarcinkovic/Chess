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

}
