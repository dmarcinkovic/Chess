//
// Created by david on 01. 01. 2020..
//

#include "Piece.h"
#include "Texture.h"
#include "Game.h"
#include "pieces.png.h"

int Piece::width, Piece::height;
SDL_Texture *Piece::piece;

Piece::Piece(int x, int y, const PieceColor &color)
		: color(color)
{
	if (piece == nullptr)
	{
		piece = Texture::loadTexture(pieces_png, pieces_png_len, width, height);
	}

	destRect = SDL_Rect{x, y, Board::width, Board::height};
	prevDestRect = destRect;
}

void Piece::draw() const
{
	SDL_RenderCopy(SDL_GetRenderer(Game::getWindow()), piece, &srcRect, &destRect);
}

void Piece::setPosition(int x, int y)
{
	destRect.x = x - destRect.w / 2;
	destRect.y = y - destRect.h / 2;
}

void Piece::alignPiece(int x, int y)
{
	auto result = Board::getAlignedPosition(x, y);

	destRect.x = result.first;
	destRect.y = result.second;
}

void Piece::markAvailableMoves() const
{
	SDL_Renderer *renderer = SDL_GetRenderer(Game::getWindow());

	for (auto &position: moves)
	{
		SDL_Rect rect{position.first, position.second, Board::width, Board::height};

		int r = Board::isWhiteSquare(position) ? 255 : 200;
		SDL_SetRenderDrawColor(renderer, r, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Piece::setMarkMoves(bool mark1)
{
	mark = mark1;
}

PieceColor Piece::getPieceColor() const
{
	return color;
}

void Piece::insertMoves(bool *direction, const int *indices1, const int *indices2, int size)
{
	for (int i = 1; i < Board::numberOfSquares; ++i)
	{
		int w = i * Board::width;
		int h = i * Board::height;

		for (int j = 0; j < size; ++j)
		{
			auto position = std::make_pair(destRect.x + indices1[j] * w, destRect.y + indices2[j] * h);
			if (!direction[j] || !Board::isInsideBoard(position))
			{
				continue;
			}

			auto p = Board::occupied[position];
			if (p == nullptr)
			{
				moves.insert(position);
			} else if (p->getPieceColor() != color)
			{
				moves.insert(position);
				direction[j] = false;
			} else
			{
				direction[j] = false;
			}
		}
	}
}

void Piece::addSquareIfNotOccupied(const std::pair<int, int> &position)
{
	if (Board::occupied[position] == nullptr && Board::isInsideBoard(position))
	{
		moves.insert(position);
	}
}

void Piece::addSquareIfOccupied(const std::pair<int, int> &position)
{
	auto p = Board::occupied[position];
	if (p && p->getPieceColor() != color)
	{
		moves.insert(position);
	}
}

bool Piece::isCorrectMove(int x, int y) const
{
	return moves.contains(Board::getAlignedPosition(x, y));
}

void Piece::returnMove()
{
	destRect = prevDestRect;
}

std::pair<int, int> Piece::getPosition() const
{
	return std::make_pair(destRect.x, destRect.y);
}

void Piece::updateMove()
{
	prevDestRect = destRect;
}