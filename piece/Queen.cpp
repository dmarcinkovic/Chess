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

}
