//
// Created by david on 06. 02. 2021..
//

#ifndef CHESS_UNDOMANAGER_H
#define CHESS_UNDOMANAGER_H


#include <stack>
#include "../actions/MoveAction.h"

class UndoManager
{
private:
	std::stack<MoveAction> undoStack;
	std::stack<MoveAction> redoStack;

public:
	static UndoManager &getInstance();

	void undo();

	void redo();

	void push(MoveAction moveAction);

private:
	UndoManager() = default;
};


#endif //CHESS_UNDOMANAGER_H
