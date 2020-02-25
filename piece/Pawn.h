//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

/**
 * Represents chess pawn.
 *
 * @author David
 */
class Pawn : public Piece
{
public:

    /**
     * Creates new pawn piece.
     *
     * @param x X position of chess pawn.
     * @param y Y position of chess pawn.
     * @param color Piece color.
     */
    Pawn(int x, int y, PieceColor color);

    void getAvailableMoves() override;
};


#endif //CHESS_PAWN_H
