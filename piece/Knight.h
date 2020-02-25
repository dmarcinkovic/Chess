//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

/**
 * Represents chess knight.
 *
 * @author David
 */
class Knight : public Piece
{
public:

    /**
     * Creates new knight piece.
     *
     * @param x X position of knight.
     * @param y Y position of knight.
     * @param color Piece color.
     */
    Knight(int x, int y, PieceColor color);

    void getAvailableMoves() override;
};


#endif //CHESS_KNIGHT_H
