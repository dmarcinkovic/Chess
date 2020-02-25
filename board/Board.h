//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include "../Game.h"

#include "../piece/Piece.h"

class Piece;

/**
 * Class that contains hash function for std::pair.
 *
 * @author David
 */
struct PairHash
{

    /**
     * Hash function for std::pair.
     *
     * @tparam T1 First template parameter.
     * @tparam T2 Second template parameter.
     * @param pair Pair to get hash.
     * @return Hash of given std::pair.
     */
    template<typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

/**
 * Represents chess board.
 *
 * @author David
 */
class Board
{
private:
    SDL_Texture *board{};
    SDL_Rect srcRect{}, destRect{};
    double angle = 0;

    static int paddingX, paddingY;

public:

    /**
     * Bool indicating that board is flipped.
     */
    static bool flipped;

    /**
     * Number of chess squares.
     */
    static int numberOfSquares;

    /**
     * Width of one chess square.
     */
    static int width;

    /**
     * Height of one chess square.
     */
    static int height;

    /**
     * Map that stores all pieces.
     */
    static std::unordered_map<std::pair<int, int>, Piece *, PairHash> occupied;

    /**
     * Initialize board.

     * @param w Width of the board.
     * @param h Height of the board.
     */
    Board(int w, int h);

    /**
     * Board destructor. Used to destroy board texture.
     */
    ~Board();

    /**
     * Method used to draw board to the screen.
     */
    void draw() const;

    /**
     * Method used to flip the board.
     */
    void flip();

    /**
     * Static method used to return x and y position of chess square.
     *
     * @param chessSquare String representing chess square. For example: a1, a2.
     * @return std::pair representing x and y coordinate of chess square.
     */
    static std::pair<int, int> getPosition(const char *chessSquare);

    /**
     * Method checks if given x and y coordinates are inside board.
     *
     * @param position Position to check if is inside board.
     * @return True if given location if inside board.
     */
    static bool isInsideBoard(const std::pair<int, int> &position);

    /**
     * Method returns aligned position of chess square for
     * given x and y coordinates.
     *
     * @param x X position.
     * @param y Y position.
     * @return Aligned position of chess square for given position.
     */
    static std::pair<int, int> getAlignedPosition(int x, int y);
};


#endif //CHESS_BOARD_H
