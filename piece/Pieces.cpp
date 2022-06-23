//
// Created by david on 23.06.22..
//

#include "Pieces.h"
#include "../factory/PieceFactory.h"
#include "../factory/Util.h"
#include "King.h"

Pieces::Pieces()
{
	pieces.reserve(32);

	addPieces();
}

void Pieces::draw() const
{
	for (auto const &piece: pieces)
	{
		if (piece->mark)
		{
			piece->markAvailableMoves();
		}
	}

	for (auto const &piece: pieces)
	{
		piece->draw();
	}
}

std::shared_ptr<Piece> *Pieces::getPiece(int x, int y)
{
	for (auto &piece: pieces)
	{
		if (piece->destRect.x < x && piece->destRect.x + piece->destRect.w > x
			&& piece->destRect.y < y && piece->destRect.y + piece->destRect.h > y)
		{
			return &piece;
		}
	}

	return nullptr;
}

constexpr void Pieces::addPieces()
{
	addWhitePieces();
	addBlackPieces();
}

void Pieces::getAvailableMoves()
{
	for (auto const &piece: pieces)
	{
		piece->getAvailableMoves();
	}
}

constexpr void Pieces::addWhitePieces()
{
	for (auto const &square: ChessSquares::getWhitePieces())
	{
		auto [x, y] = Board::getPosition(square);
		PieceType type = ChessSquares::getPieceType(square);
		pieces.emplace_back(PieceFactory::getPiece(type, x, y, PieceColor::WHITE));

		Board::occupied[std::make_pair(x, y)] = pieces.back();
	}
}

constexpr void Pieces::addBlackPieces()
{
	for (auto const &square: ChessSquares::getBlackPieces())
	{
		auto [x, y] = Board::getPosition(square);
		PieceType type = ChessSquares::getPieceType(square);
		pieces.emplace_back(PieceFactory::getPiece(type, x, y, PieceColor::BLACK));

		Board::occupied[std::make_pair(x, y)] = pieces.back();
	}
}

void Pieces::takePiece(const std::pair<int, int> &position)
{
	std::shared_ptr<Piece> piece{Board::occupied[position]};
	if (piece)
	{
		Board::occupied[piece->getPosition()] = nullptr;
		auto iterator = std::find(pieces.begin(), pieces.end(), piece);
		pieces.erase(iterator);
	}
}

bool Pieces::isCheck()
{
	for (auto const &piece: pieces)
	{
		if (piece->color != Game::turn)
		{
			continue;
		}

		for (auto const &square: piece->moves)
		{
			if (dynamic_cast<King *>(Board::occupied[square].get()))
			{
				return true;
			}
		}
	}

	return false;
}

bool Pieces::isStalemate()
{
	int totalNumberOfAvailableMoves = 0;

	for (auto const &piece: pieces)
	{
		totalNumberOfAvailableMoves += static_cast<int>(piece->moves.size());
	}

	return totalNumberOfAvailableMoves > 0;
}

bool Pieces::isCheckmate()
{
	return isStalemate() && isCheck();
}

void Pieces::addObserver(ICheckObserver *observer)
{
	observers.emplace_back(observer);
}

void Pieces::notifyAll(Pieces *pieces1)
{
	std::for_each(observers.begin(), observers.end(), [&](ICheckObserver *observer) {
		observer->update(pieces1);
	});
}

void Pieces::update()
{
	for (auto &piece: pieces)
	{
		if (piece->getPieceColor() != Game::turn)
		{
			std::unordered_set<std::pair<int, int>, PairHash> result{};
			std::pair<int, int> position = {piece->destRect.x, piece->destRect.y};

			Board::occupied[position] = nullptr;
			for (auto &move: piece->moves)
			{
				piece->setPosition(move.first, move.second);
				Board::occupied[move] = piece;

				if (!isCheck())
				{
					result.insert(move);
				}

				Board::occupied[move] = nullptr;
				piece->setPosition(position.first + +piece->destRect.w / 2,
								   position.second + +piece->destRect.h / 2);
			}
			Board::occupied[position] = piece;

			piece->moves = std::move(result);
		}
	}
}

const std::vector<std::shared_ptr<Piece>> &Pieces::getPieces() const
{
	return pieces;
}

void Pieces::setPieces(std::vector<std::shared_ptr<Piece>> newPieces)
{
	pieces = std::move(newPieces);
}