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

}
