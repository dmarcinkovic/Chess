//
// Created by david on 05. 01. 2020..
//

#include "PieceFactory.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"

std::shared_ptr<Piece> PieceFactory::getPiece(PieceType type, int x, int y, const PieceColor &color)
{
	switch (type)
	{
		case PieceType::King:
			return std::make_shared<King>(x, y, color);
		case PieceType::Queen:
			return std::make_shared<Queen>(x, y, color);
		case PieceType::Bishop:
			return std::make_shared<Bishop>(x, y, color);
		case PieceType::Rook:
			return std::make_shared<Rook>(x, y, color);
		case PieceType::Pawn:
			return std::make_shared<Pawn>(x, y, color);
		case PieceType::Knight:
			return std::make_shared<Knight>(x, y, color);
		default:
			return std::make_shared<King>(x, y, color);
	}
}
