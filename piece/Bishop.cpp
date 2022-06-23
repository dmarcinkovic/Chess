//
// Created by david on 02. 01. 2020..
//

#include "Bishop.h"

Bishop::Bishop(int x, int y, const PieceColor &color) : Piece(x, y, color)
{
	srcRect = SDL_Rect{width / 3, color == PieceColor::WHITE ?
								  0 : height / 2, width / 6, height / 2};
}

void Bishop::getAvailableMoves()
{
	moves.clear();

	bool direction[] = {true, true, true, true};
	constexpr int indices1[] = {-1, -1, 1, 1};
	constexpr int indices2[] = {1, -1, 1, -1};

	insertMoves(direction, indices1, indices2, 4);
}

