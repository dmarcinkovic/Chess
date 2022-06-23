//
// Created by david on 06. 02. 2021..
//

#ifndef CHESS_MOVEACTION_H
#define CHESS_MOVEACTION_H


#include <vector>
#include <memory>

#include "Action.h"
#include "Piece.h"

class MoveAction : public Action
{
private:
	std::vector<std::shared_ptr<Piece>> currentPieces;
	std::vector<std::shared_ptr<Piece>> previousPieces;

	class Pieces *chessPieces;

public:
	MoveAction(const std::shared_ptr<class Pieces> &currentPieces, const std::shared_ptr<class Pieces> &previousPieces);

	void executeDo() override;

	void executeUndo() override;
};


#endif //CHESS_MOVEACTION_H
