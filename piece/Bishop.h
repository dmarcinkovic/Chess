//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

/**
 * Represents chess bishop.
 *
 * @author David
 */
class Bishop : public Piece
{

public:

    /**
     * Creates new knight piece.
     *
     * @param x X position of bishop.
     * @param y Y position of bishop.
     * @param color Piece color.
     */
    Bishop(int x, int y, PieceColor color);

    void getAvailableMoves() override;
};


#endif //CHESS_BISHOP_H
