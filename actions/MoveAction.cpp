//
// Created by david on 06. 02. 2021..
//

#include "MoveAction.h"
#include "../piece/Pieces.h"

MoveAction::MoveAction(const std::shared_ptr<Pieces> &currentPieces, const std::shared_ptr<Pieces> &previousPieces)
		: chessPieces(currentPieces.get()), currentPieces(currentPieces->getPieces()),
		  previousPieces(previousPieces->getPieces())
{

}

void MoveAction::executeDo()
{
	std::cout << "Execute do\n";
	chessPieces->setPieces(currentPieces);
}

void MoveAction::executeUndo()
{
	std::cout << "previous and current same? : " << (currentPieces == previousPieces) << '\n';
	auto piece1 = chessPieces->getPieces();
	std::cout << "Execute undo\n";
	chessPieces->setPieces(previousPieces);
	auto piece2 = chessPieces->getPieces();
	std::cout << "Same ?: " << (piece1 == piece2);
}
