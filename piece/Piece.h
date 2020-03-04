//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <SDL2/SDL.h>
#include <unordered_set>
#include <functional>

#include "../texture/Texture.h"
#include "../Game.h"
#include "../pair/PairHash.h"
#include "CheckObserver.h"

/**
 * Enum that represents piece color.
 *
 * @author David
 */
enum class PieceColor
{
    WHITE,
    BLACK
};

/**
 * Represents abstraction of chess piece.
 *
 * @author David
 */
class Piece
{
private:

    /**
     * Method used to add taking move to set of available
     * moves. For example, lets say that white gave check with
     * his bishop on b5. Then this method checks if it is possible
     * to take that bishop.
     *
     * @param attackingPiece Piece that is causing check.
     * @param newMoves Set of new available moves for this piece.
     */
    void addTakingMove(Piece *attackingPiece, std::unordered_set<std::pair<int, int>, PairHash> &newMoves);

protected:
    static int width, height;

    static SDL_Texture *piece;
    SDL_Rect srcRect{}, destRect{}, prevDestRect{};

    PieceColor color;

    bool mark{};
    std::unordered_set<std::pair<int, int>, PairHash> moves;

    /**
     * Mark all available squares for this piece.
     */
    void markAvailableMoves() const;

    /**
     * Helper method to insert available moves.
     *
     * @param direction Boolean array that is used to check occupied squares.
     * @param indices1 X coordinates.
     * @param indices2 Y coordinates.
     * @param size Size of arrays.
     */
    void insertMoves(bool *direction, const int *indices1, const int *indices2, int size);

    /**
     * Method that adds square as an available square if it is not occupied.
     *
     * @param position Position of chess square.
     */
    void addSquareIfNotOccupied(const std::pair<int, int> &position);

    /**
    * Method to add square to list of available squares if is occupied
    * by piece of opposite color.
    *
    * @param position Position of chess square to be added.
    */
    void addSquareIfOccupied(const std::pair<int, int> &position);

    /**
     * Method finds common moves of this piece and attacking piece.
     *
     * @param attackingPiece Piece that is causing check.
     */
    void findIntersection(Piece *attackingPiece);

public:

    /**
     * Creates new chess piece.
     *
     * @param x X position of chess piece.
     * @param y Y position of chess piece.
     * @param color Piece color. Black or white.
     */
    Piece(int x, int y, const PieceColor &color);

    /**
     * Default constructor.
     */
    Piece() = default;

    /**
     * Method used to draw piece to the screen.
     */
    virtual void draw() const;

    /**
     * Method used to get all available squares from current position.
     *
     */
    virtual void getAvailableMoves() = 0;

    /**
     * Method used to find available squares for all pieces when
     * check has occurred on the board.
     *
     * @param attackingPiece Piece that is causing check.
     */
    virtual void getAvailableMovesCheck(Piece *attackingPiece);

    /**
     * Returns piece color.
     *
     * @return  Piece color.
     */
    virtual PieceColor getPieceColor() const;

    /**
     * Default destructor.
     */
    virtual ~Piece() = default;

    /**
     * Set new position of this piece.
     *
     * @param x New x position.
     * @param y  New y position.
     */
    void setPosition(int x, int y);

    /**
     * Method that is used to align piece to the square on the
     * board when piece is dropped.
     *
     * @param x Current x position of piece.
     * @param y Current y position of piece.
     */
    void alignPiece(int x, int y);

    /**
     * If given argument mark1 is true, available squares
     * will be marked, otherwise not.
     *
     * @param mark1 If true, available squares will be marked, otherwise not.
     */
    void setMarkMoves(bool mark1);

    /**
     * Checks if current move is correct.
     *
     * @param x Current x position of the piece.
     * @param y Current y position of the piece.
     * @return True if move is correct.
     */
    bool isCorrectMove(int x, int y) const;

    /**
     * Method used to return to previous move.
     */
    void returnMove();

    /**
     * Update previous piece position.
     */
    void updateMove();

    /**
     * Returns current position of the piece.
     *
     * @return Current piece position.
     */
    std::pair<int, int> getPosition() const;

    /**
     * Allow Pieces class access to all members of this class.
     */
    friend class Pieces;
};

class ICheckObserver;

/**
 * Composite class that is used to manage all pieces.
 *
 * @author David
 */
class Pieces : public Piece
{
private:
    std::vector<std::shared_ptr<Piece>> pieces;

    std::vector<ICheckObserver *> observers;

    std::vector<Piece *> pieceAttackKing;

    /**
     * Method to add pieces to the board.
     */
    inline constexpr void addPieces();

    /**
     * Method to add white pieces to the board.
     */
    inline constexpr void addWhitePieces();

    /**
     * Method to add black piece to the board.
     */
    inline constexpr void addBlackPieces();

public:

    /**
     * Adds all pieces to the screen.
     */
    Pieces();

    /**
     * Used to draw all pieces.
     */
    void draw() const override;

    /**
     * Method that returns piece that has position closest
     * to given x and y coordinates.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @return Returns piece under x and y coordinate.
     */
    std::shared_ptr<Piece> *getPiece(int x, int y);

    void getAvailableMoves() override;

    /**
     * Method checks if current move is taking move.
     * If so, it deletes taken piece from list of pieces.
     *
     * @param position Current piece position.
     */
    void takePiece(const std::pair<int, int> &position);

    /**
     * Subscribe to an interested observer to listen to check event.
     *
     * @param observer An event listener.
     */
    void addObserver(ICheckObserver *observer);

    /**
     *  Notify all interested observers that event has occurred.
     *
     * @param pieces1 Pointer to all pieces.
     */
    void notifyAll(Pieces *pieces1);

    /**
     * Method checks if king is under attack.
     *
     * @return True if king is under attack. Otherwise returns
     * false.
     */
    bool isCheck();

    /**
     * Method checks if stalemate occurs on the board.
     * Stalemate is a situation in the game of chess where the
     * player whose turn it is to move is not in check but has
     * no legal move.
     *
     * @return True if stalemate occurs on the board.
     */
    bool isStalemate();

    /**
     * Method checks if checkmate occurs on the board.
     * Checkmate is a situation in the game of chess where
     * the player whose turn it is to move is in check and has
     * legal move.
     *
     * @return True if checkmate occurs on the board.
     */
    bool isCheckmate();

    /**
     * Friend class. It has access to all private members of this class.
     */
    friend class CheckObserver;

};


#endif //CHESS_PIECE_H
