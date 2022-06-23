//
// Created by david on 23.06.22..
//

#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <vector>
#include <memory>

#include "Piece.h"

/**
 * Composite class that is used to manage all pieces.
 *
 * @author David
 */
class Pieces : public Piece
{
private:
	std::vector<std::shared_ptr<Piece>> pieces;

	std::vector<class ICheckObserver *> observers;

	/**
	 * Friend class. It has access to all private members of this class.
	 */
	friend class CheckObserver;

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

	/**
	 * Method used to get all available squares from current position.
	 */
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
	 * the player whose turn it is to move is in check and has no
	 * legal move.
	 *
	 * @return True if checkmate occurs on the board.
	 */
	bool isCheckmate();

	/**
	 * Update game state. Updates chess pieces positions.
	 */
	void update();

	/**
	 * Getter for pieces
	 *
	 * @return Chess pieces
	 */
	const std::vector<std::shared_ptr<Piece>> &getPieces() const;

	/**
	 * Setter for pieces
	 *
	 * @param newPieces New pieces
	 */
	void setPieces(std::vector<std::shared_ptr<Piece>> newPieces);
};

#endif //CHESS_PIECES_H
