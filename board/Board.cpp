//
// Created by david on 01. 01. 2020..
//

#include "Board.h"
#include "Texture.h"
#include "Game.h"
#include "Piece.h"
#include "board.jpg.h"

int Board::width;
int Board::height;
int Board::paddingX;
int Board::paddingY;
int Board::numberOfSquares = 8;

bool Board::flipped = false;

std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>, PairHash> Board::occupied;

Board::Board(int w, int h)
{
	int windowWidth, windowHeight;
	SDL_GetWindowSize(Game::getWindow(), &windowWidth, &windowHeight);

	board = Texture::loadTexture(board_jpg, board_jpg_len, srcRect.w, srcRect.h);

	destRect = SDL_Rect{0, 0, w, h};
	width = static_cast<int>(0.1163 * windowWidth);
	height = static_cast<int>(0.1163 * windowHeight);

	paddingX = static_cast<int>(0.035 * windowWidth);
	paddingY = static_cast<int>(0.035 * windowHeight);
}

Board::~Board()
{
	SDL_DestroyTexture(board);
}

void Board::draw() const
{
	SDL_Renderer *renderer = SDL_GetRenderer(Game::getWindow());

	SDL_RenderCopyEx(renderer, board, &srcRect,
					 &destRect, angle, nullptr, SDL_FLIP_NONE);
}

void Board::flip()
{
	if (angle == 0)
	{
		angle = 180;
		flipped = true;
	} else
	{
		angle = 0;
		flipped = false;
	}
}

std::pair<int, int> Board::getPosition(const char *chessSquare)
{
	int x = paddingX + (chessSquare[0] - 'a') * width;
	int y = paddingY + (numberOfSquares - (chessSquare[1] - '0')) * height;

	return {x, y};
}

bool Board::isInsideBoard(const std::pair<int, int> &position)
{
	int x = position.first;
	int y = position.second;

	return x >= paddingX && x <= paddingX + (numberOfSquares - 1) * width
		   && y >= paddingY && y <= paddingY + (numberOfSquares - 1) * height;
}

std::pair<int, int> Board::getAlignedPosition(int x, int y)
{
	return std::make_pair(
			static_cast<int>(std::floor((x - paddingX) / width) * width + paddingX),
			static_cast<int>(std::floor((y - paddingY) / height) * height + paddingY));
}

bool Board::isWhiteSquare(const std::pair<int, int> &squarePos)
{
	int row = static_cast<int>((squarePos.second - paddingY) / height);
	int col = static_cast<int>((squarePos.first - paddingX) / width);

	return row % 2 == 0 && col % 2 == 0 || row % 2 == 1 && col % 2 == 1;
}
