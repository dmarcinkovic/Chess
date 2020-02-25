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
private:

    /**
     * Method that adds square as an available square if it is not occupied.
     *
     * @param y Y position of chess square.
     */
    void addSquareIfNotOccupied(int y);

    /**
     * Method used to add available chess squares for pawn
     * depending on position on board (down on up).
     *
     * @param chessSquare Starting position on the board. (Second or seventh row).
     * @param sign -1 if piece is on seventh row. 1 if piece is on second row.
     */
    void addSquares(const char *chessSquare, int sign);

    /**
     * Add available squares depending on the piece color.
     *
     * @param piecesDown Piece that is down. White if board is not flipped.
     */
    void addSquares(const PieceColor &piecesDown);

    /**
     * Add available taking moves to list of all available moves.
     *
     * @param piecesDown Color of pieces that are down. White if board is not flipped.
     */
    void addTakingMove(const PieceColor &piecesDown);

    /**
     * Add taking move according to position on the board.
     * -1 if piece is down (by default white pieces). Otherwise sign is 1.
     *
     * @param sign Position on the board. -1 if pieces are down. Otherwise it is 1.
     */
    void addTakingMove(int sign);

    /**
     * Method to add square to list of available squares if is occupied
     * by piece of opposite color.
     *
     * @param position Position of chess square to be added.
     */
    void addSquareIfOccupied(const std::pair<int, int> &position);

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
