//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

/**
 * Represents chess rook.
 *
 * @author David
 */
class Rook : public Piece
{
public:

    /**
     * Creates new knight piece.
     *
     * @param x X position of chess rook.
     * @param y Y position of chess rook.
     * @param color Piece color.
     */
    Rook(int x, int y, PieceColor color);

    void getAvailableMoves() override;
};


#endif //CHESS_ROOK_H
