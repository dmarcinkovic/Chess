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

    /**
     * Method used to add castle move.
     */
    void addCastleMove();

    /**
     * Method returns square according to given column and
     * piece color.
     *
     * @param col Column of the square.
     * @return Position of the given square.
     */
    std::pair<int, int> getSquare(char col);

    /**
     * Method used to check if squares between rook and
     * king are occupied or not.
     *
     * @param numberOfSquares Number of squares in between rook and king.
     * @param col Column of the square.
     * @return True if all squares between rook and king are not occupied.
     */
    bool checkSquaresInBetween(int numberOfSquares, char col);

    /**
     * Method used to check if king and rook are at they starting positions.
     *
     * @param rookPosition Column of the rook. For big castle it is 'a' and
     *                      for small castle is 'h'.
     * @param newKingPosition Column of the new king position. For big castle it
     *                      is 'c' and for small is 'g'.
     */
    void checkKingAndRook(char rookPosition, char newKingPosition);

    /**
     * Method used to add castle.
     *
     * @param numberOfSquares Number of squares in between rook and king.
     * @param col Starting column of the squares in between rook and king.
     * @param rookPosition Rook position. 'h' for small castle and 'a' for big castle.
     * @param newKingPosition New king position. For big castle it is 'c' and for small is 'g'.
     */
    void addCastleMove(int numberOfSquares, char col, char rookPosition, char newKingPosition);

    /**
     * Helper method to perform castle. Moves rook from current position
     * to new position.
     *
     * @param rookPosition Current rook position.
     * @param newRookPosition New rook position.
     */
    void castle(char rookPosition, char newRookPosition);

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

    /**
     * Checks if current move is castle move.
     *
     * @return True if current move is castle move.
     */
    bool isCastleMove() const;

    /**
     * Method performs castle.
     */
    void castle();
};


#endif //CHESS_KING_H
