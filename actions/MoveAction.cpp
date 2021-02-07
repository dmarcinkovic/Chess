//
// Created by david on 06. 02. 2021..
//

#include "MoveAction.h"

MoveAction::MoveAction(const std::shared_ptr<Pieces> &currentPieces, const std::shared_ptr<Pieces> &previousPieces)
		: chessPieces(currentPieces.get()), currentPieces(currentPieces->getPieces()),
		  previousPieces(previousPieces->getPieces())
{

}

void MoveAction::executeDo()
{

}

void MoveAction::executeUndo()
{
	
}
