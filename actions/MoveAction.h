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
	std::vector<std::shared_ptr<Piece>> pieces;
	Pieces *chessPieces;

public:
	explicit MoveAction(const std::shared_ptr<Pieces> &pieces);

	void executeDo() override;

	void executeUndo() override;
};


#endif //CHESS_MOVEACTION_H
