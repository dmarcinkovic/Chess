//
// Created by david on 05. 01. 2020..
//

#include "PieceFactory.h"
#include "../piece/King.h"
#include "../piece/Queen.h"
#include "../piece/Bishop.h"
#include "../piece/Rook.h"
#include "../piece/Pawn.h"
#include "../piece/Knight.h"

std::unique_ptr<Piece> PieceFactory::getPiece(PieceType type, int x, int y, const PieceColor &color)
{
    switch (type)
    {
        case PieceType::King:
            return std::move(std::make_unique<King>(x, y, color));
        case PieceType::Queen:
            return std::move(std::make_unique<Queen>(x, y, color));
        case PieceType::Bishop:
            return std::move(std::make_unique<Bishop>(x, y, color));
        case PieceType::Rook:
            return std::move(std::make_unique<Rook>(x, y, color));
        case PieceType::Pawn:
            return std::move(std::make_unique<Pawn>(x, y, color));
        case PieceType::Knight:
            return std::move(std::make_unique<Knight>(x, y, color));
        default:
            return std::move(std::make_unique<King>(x, y, color));
    }
}
