//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include <memory>

#include "../Game.h"

#include "../piece/Piece.h"
#include "../pair/PairHash.h"

class Piece;

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
    static std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>, PairHash> occupied;

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

    /**
     * Method checks is the given square is white or black.
     *
     * @param squarePos Position of the square.
     * @return True if the square is white, otherwise returns false.
     */
    static bool isWhiteSquare(const std::pair<int, int> &squarePos);
};


#endif //CHESS_BOARD_H
