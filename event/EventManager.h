//
// Created by david on 31. 01. 2020..
//

#ifndef CHESS_EVENTMANAGER_H
#define CHESS_EVENTMANAGER_H

#include <memory>
#include <SDL2/SDL.h>

/**
 * Class that is used to handle mouse events.
 *
 * @author David
 */
class EventManager
{
private:
	bool liftedPiece{};

	std::shared_ptr<class Piece> piece;
	std::shared_ptr<class Pieces> previousPieces{};

	/**
	 * Method used to switch turn.
	 */
	static void switchTurn();

	/**
	 * Method that is executed when user makes correct move.
	 *
	 * @param event Mouse event.
	 * @param pieces Pointer to pieces class.
	 */
	void correctMove(const SDL_Event &event, const std::shared_ptr<class Pieces> &pieces);

	/**
	 * Method called when user made invalid move.
	 */
	void incorrectMove();

	/**
	 *  Method that checks if king is under attack.
	 *  If king is under attack, it checks if user
	 *  moved the king or cover the king.
	 */
	static void handleCheck(class Pieces *pieces);

	/**
	 * Method checks if current move is castle move.
	 * If so, then it performs castle.
	 */
	void castle();

	/**
	 * Method used to save the current game state.
	 *
	 * @param pieces Current game state
	 */
	void saveState(const std::shared_ptr<class Pieces> &pieces);

public:
	/**
	 * Constructor.
	 *
	 * @param pieces Initial state of pieces
	 */
	explicit EventManager(std::shared_ptr<class Pieces> pieces);

	/**
	 * Mouse pressed event.
	 *
	 * @param pressedPiece Pressed piece.
	 * @param event Reference to event.
	 */
	void mousePressed(const std::shared_ptr<class Piece> *pressedPiece, const SDL_Event &event);

	/**
	 * Mouse released event.
	 *
	 * @param event Reference to event.
	 * @param pieces Pointer to pieces class.
	 */
	void mouseReleased(const SDL_Event &event, const std::shared_ptr<class Pieces> &pieces);

	/**
	 * Mouse moved event.
	 *
	 * @param event Reference to event.
	 */
	void mouseMoved(const SDL_Event &event);

	/**
	 * Function that is called when the left arrow is pressed.
	 * Cancels the last move played.
	 */
	static void undo();

	/**
	 * Function that is called when the right arrow is pressed.
	 * Cancels redo action.
	 */
	static void redo();

};


#endif //CHESS_EVENTMANAGER_H
