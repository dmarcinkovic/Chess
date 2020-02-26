//
// Created by david on 31. 01. 2020..
//

#include "EventManager.h"

void EventManager::mousePressed(const std::shared_ptr<Piece> &pressedPiece, const SDL_Event &event)
{
    if (pressedPiece && Game::turn == pressedPiece->getPieceColor())
    {
        piece = pressedPiece;
        piece->setMarkMoves(true);
        piece->updateMove();
        Board::occupied[Board::getAlignedPosition(event.button.x, event.button.y)] = nullptr;
    }
}

void EventManager::mouseReleased(const SDL_Event &event, Pieces *pieces)
{
    if (liftedPiece)
    {
        liftedPiece = false;

        if (!piece->isCorrectMove(event.button.x, event.button.y))
        {
            piece->returnMove();
            Board::occupied[piece->getPosition()] = piece;
        } else
        {
            piece->alignPiece(event.button.x, event.button.y);
            pieces->takePiece(piece->getPosition());

            Board::occupied[piece->getPosition()] = piece;

            pieces->getAvailableMoves();
            switchTurn();
        }
    }

    if (piece) piece->setMarkMoves(false);

    piece = nullptr;
}

void EventManager::mouseMoved(const SDL_Event &event)
{
    if (piece)
    {
        liftedPiece = true;
        piece->setPosition(event.button.x, event.button.y);
    }
}

void EventManager::switchTurn()
{
    Game::turn = Game::turn == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
}
