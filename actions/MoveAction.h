//
// Created by david on 06. 02. 2021..
//

#ifndef CHESS_MOVEACTION_H
#define CHESS_MOVEACTION_H


#include <vector>
#include <memory>

#include "Action.h"
#include "../piece/Piece.h"

class MoveAction : public Action
{
private:
	std::vector<std::shared_ptr<Piece>> currentPieces;
	std::vector<std::shared_ptr<Piece>> previousPieces;

	Pieces *chessPieces;

public:
	MoveAction(const std::shared_ptr<Pieces> &currentPieces, const std::shared_ptr<Pieces> &previousPieces);

	void executeDo() override;

	void executeUndo() override;
};


#endif //CHESS_MOVEACTION_H
