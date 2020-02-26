//
// Created by david on 02. 01. 2020..
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"

/**
 * Represents chess queen.
 *
 * @author David
 */
class Queen : public Piece
{
private:

    /**
     * Method used to add diagonal moves
     * for queen.
     */
    void getDiagonalAvailableMoves();

    /**
     * Method used to add horizontal and vertical available
     * moves for queen.
     */
    void getHorizontalAvailableMoves();

public:

    /**
     * Creates new queen piece.
     *
     * @param x X position of chess queen.
     * @param y Y position of chess queen.
     * @param color Piece color.
     */
    Queen(int x, int y, const PieceColor &color);

    void getAvailableMoves() override;
};


#endif //CHESS_QUEEN_H
