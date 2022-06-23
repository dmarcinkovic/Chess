//
// Created by david on 05. 01. 2020..
//

#ifndef CHESS_PIECEFACTORY_H
#define CHESS_PIECEFACTORY_H

#include <memory>
#include "Piece.h"

/**
 * Enum that represents types of pieces.
 *
 * @author David
 */
enum class PieceType
{
	King, Queen, Bishop, Rook, Pawn, Knight
};

/**
 * Main class in factory design pattern. It contains one public method that
 * creates new piece according to PieceType.
 *
 * @author David
 */
class PieceFactory
{
public:

	/**
	 * Method that returns new piece according to PieceType.
	 *
	 * @param type PieceType.
	 * @param x X position of piece.
	 * @param y Y position of piece-
	 * @param pieceColor Piece color. White or black.
	 * @return New chess piece.
	 */
	static std::shared_ptr<Piece> getPiece(PieceType type, int x, int y, const PieceColor &pieceColor);
};


#endif //CHESS_PIECEFACTORY_H
