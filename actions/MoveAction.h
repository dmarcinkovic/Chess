//
// Created by david on 06. 02. 2021..
//

#ifndef CHESS_MOVEACTION_H
#define CHESS_MOVEACTION_H


#include "Action.h"

class MoveAction : public Action
{
public:
	void executeDo() override;

	void executeUndo() override;
};


#endif //CHESS_MOVEACTION_H
