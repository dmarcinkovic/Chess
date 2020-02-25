//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

/**
 * Represents chess king.
 *
 * @author David
 */
class King : public Piece
{
public:

    /**
     * Creates new king piece.
     *
     * @param x X position of chess king.
     * @param y Y position of chess king.
     * @param color Piece color.
     */
    King(int x, int y, PieceColor color);

    void getAvailableMoves() override;
};


#endif //CHESS_KING_H
