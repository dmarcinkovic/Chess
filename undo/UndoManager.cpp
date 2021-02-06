//
// Created by david on 06. 02. 2021..
//

#include "UndoManager.h"

UndoManager UndoManager::getInstance()
{
	static UndoManager instance;

	return instance;
}

void UndoManager::undo()
{
	if (undoStack.empty())
	{
		return;
	}

	auto action = undoStack.top();
	undoStack.pop();

	redoStack.push(action);
	action.executeUndo();
}

void UndoManager::redo()
{
	if (redoStack.empty())
	{
		return;
	}

	auto action = redoStack.top();
	redoStack.pop();

	undoStack.push(action);
	action.executeDo();
}

void UndoManager::push(MoveAction moveAction)
{
	if (!redoStack.empty())
	{
		redoStack.pop();
	}

	undoStack.push(std::move(moveAction));
}

