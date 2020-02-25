//
// Created by david on 05. 01. 2020..
//

#ifndef CHESS_UTIL_H
#define CHESS_UTIL_H


#include "PieceFactory.h"

/**
 * Class that contains three static methods that are used
 * to create pieces.
 *
 * @author David
 */
struct ChessSquares
{

    /**
     * Method that returns new array which contains
     * squares on which white pieces are placed at the start of
     * the game.
     *
     * @return Array of strings representing squares for white pieces.
     */
    static constexpr std::array<const char *, 16> getWhitePieces()
    {
        return std::array<const char *, 16>{"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
                                            "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"};
    }

    /**
     * Method that returns new array which contains
     * squares on which black piece are placed at the start
     * of the game.
     *
     * @return Array of strings representing squares for black pieces.
     */
    static constexpr std::array<const char *, 16> getBlackPieces()
    {
        return std::array<const char *, 16>{"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
                                            "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"};
    }

    /**
     * Method that returns PieceType according to the starting
     * position on the board.
     *
     * @param square Position on the board.
     * @return PiieceType according to the starting position on the board.
     */
    static constexpr PieceType getPieceType(const char *square)
    {
        if (square[1] == '2' || square[1] == '7')
            return PieceType::Pawn;

        switch (square[0])
        {
            case 'a':
            case 'h':
                return PieceType::Rook;
            case 'b':
            case 'g':
                return PieceType::Knight;
            case 'c':
            case 'f':
                return PieceType::Bishop;
            case 'd' :
                return PieceType::Queen;
            default:
                return PieceType::King;
        }
    }
};


#endif //CHESS_UTIL_H
