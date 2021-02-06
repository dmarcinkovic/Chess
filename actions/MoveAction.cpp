//
// Created by david on 06. 02. 2021..
//

#include "MoveAction.h"

MoveAction::MoveAction(const std::shared_ptr<Pieces> &pieces)
	: chessPieces(pieces.get()), pieces(pieces->getPieces())
{

}

void MoveAction::executeDo()
{

}

void MoveAction::executeUndo()
{

}
