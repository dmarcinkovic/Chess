//
// Created by david on 06. 02. 2021..
//

#ifndef CHESS_ACTION_H
#define CHESS_ACTION_H

class Action
{
public:
	virtual void executeDo() = 0;

	virtual void executeUndo() = 0;
};


#endif //CHESS_ACTION_H
