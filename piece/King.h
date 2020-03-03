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
private:

    void addCastleMove();

    std::pair<int, int> getSquare(char col);

    bool checkSquaresInBetween(int numberOfSquares, char col);

    void checkKingAndRook(char rookPosition, char newKingPosition);

    void addCastleMove(int numberOfSquares, char col, char rookPosition, char newKingPosition);

public:

    /**
     * Creates new king piece.
     *
     * @param x X position of chess king.
     * @param y Y position of chess king.
     * @param color Piece color.
     */
    King(int x, int y, const PieceColor &color);

    void getAvailableMoves() override;
};


#endif //CHESS_KING_H
