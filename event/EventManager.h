//
// Created by david on 31. 01. 2020..
//

#ifndef CHESS_EVENTMANAGER_H
#define CHESS_EVENTMANAGER_H

#include <memory>

#include "../piece/Piece.h"
#include "../actions/State.h"

class Piece;

class Pieces;

class State;

/**
 * Class that is used to handle mouse events.
 *
 * @author David
 */
class EventManager
{
private:
    bool liftedPiece{};

    std::shared_ptr<Piece> piece;

    State *state;

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
    void correctMove(const SDL_Event &event, Pieces *pieces);

    /**
     * Method called when user made invalid move.
     */
    void incorrectMove();

    /**
     *  Method that checks if king is under attack.
     *  If king is under attack, it checks if user
     *  moved the king or cover the king.
     */
    static void handleCheck(Pieces *pieces);

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
    void saveState(Pieces *pieces);

public:

	/**
	 * Constructor that creates initial state.
	 */
	EventManager();

	/**
	 * Destructor that deletes stored state.
	 */
	~EventManager();

    /**
     * Mouse pressed event.
     *
     * @param pressedPiece Pressed piece.
     * @param event Reference to event.
     */
    void mousePressed(const std::shared_ptr<Piece> *pressedPiece, const SDL_Event &event);

    /**
     * Mouse released event.
     *
     * @param event Reference to event.
     * @param pieces Pointer to pieces class.
     */
    void mouseReleased(const SDL_Event &event, Pieces *pieces);

    /**
     * Mouse moved event.
     *
     * @param event Reference to event.
     */
    void mouseMoved(const SDL_Event &event);

    /**
     * Function that is called when the left arrow is pressed.
     * Cancels the last move played.
     *
     * @param pieces Pieces that are currently on the board.
     */
    void undo(const std::shared_ptr<Pieces> &pieces);

    /**
     * Function that is caled when the right arrow is pressed.
     * Cancels redo action.
     *
     * @param pieces Pieces that are current on the board.
     */
    void redo(const std::shared_ptr<Pieces> &pieces);

};


#endif //CHESS_EVENTMANAGER_H
