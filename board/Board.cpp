//
// Created by david on 01. 01. 2020..
//

#include "Board.h"

int Board::width;
int Board::height;
int Board::paddingX;
int Board::paddingY;
int Board::numberOfSquares = 8;

bool Board::flipped = false;

std::unordered_map<std::pair<int, int>, Piece*, PairHash> Board::occupied;

Board::Board(int w, int h)
{
    board = Texture::loadTexture("resources/board.jpg", srcRect.w, srcRect.h);

    destRect = SDL_Rect{0, 0, w, h};
    width = static_cast<int>(0.1163 * Game::width);
    height = static_cast<int>(0.1163 * Game::height);

    paddingX = static_cast<int>(0.035 * Game::width);
    paddingY = static_cast<int>(0.035 * Game::height);
}

Board::~Board()
{
    SDL_DestroyTexture(board);
}

void Board::draw() const
{
    SDL_RenderCopyEx(Game::renderer, board, &srcRect,
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
    std::pair<int, int> alignedPosition = std::make_pair(
            static_cast<int>(std::floor((x - paddingX) / width) * width + paddingX),
            static_cast<int>(std::floor((y - paddingY) / height) * height + paddingY));

    return alignedPosition;
}
