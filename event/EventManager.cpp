//
// Created by david on 31. 01. 2020..
//

#include "EventManager.h"
#include "../piece/King.h"
#include "../undo/UndoManager.h"

void EventManager::mousePressed(const std::shared_ptr<Piece> *pressedPiece, const SDL_Event &event)
{
	if (pressedPiece && Game::turn == (*pressedPiece)->getPieceColor())
	{
		piece = *pressedPiece;
		piece->setMarkMoves(true);
		piece->updateMove();

		Board::occupied[Board::getAlignedPosition(event.button.x, event.button.y)] = nullptr;
	}
}

void EventManager::mouseReleased(const SDL_Event &event, const std::shared_ptr<Pieces> &pieces)
{
	if (liftedPiece)
	{
		liftedPiece = false;

		if (!piece->isCorrectMove(event.button.x, event.button.y))
		{
			incorrectMove();
		} else
		{
			correctMove(event, pieces);
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

void EventManager::correctMove(const SDL_Event &event, const std::shared_ptr<Pieces> &pieces)
{
	piece->alignPiece(event.button.x, event.button.y);
	pieces->takePiece(piece->getPosition());
	Board::occupied[piece->getPosition()] = piece;
	pieces->getAvailableMoves();

	castle();
	handleCheck(pieces.get());

	switchTurn();
	saveState(pieces);
}

void EventManager::incorrectMove()
{
	piece->returnMove();
	Board::occupied[piece->getPosition()] = piece;
}

void EventManager::handleCheck(Pieces *pieces)
{
	if (pieces->isCheck())
	{
		pieces->notifyAll(pieces);
	}
}

void EventManager::castle()
{
	King *king = dynamic_cast<King *>(piece.get());

	if (king && king->isCastleMove())
	{
		king->castle();
	}
}

void EventManager::undo()
{
	UndoManager::getInstance().undo();
}

void EventManager::redo()
{
	UndoManager::getInstance().redo();
}

void EventManager::saveState(const std::shared_ptr<Pieces> &pieces)
{
	UndoManager::getInstance().push(MoveAction(pieces));
}
