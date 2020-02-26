//
// Created by david on 31. 01. 2020..
//

#ifndef CHESS_EVENTMANAGER_H
#define CHESS_EVENTMANAGER_H

#include <memory>
#include "../piece/Piece.h"

/**
 * Predeclaration of Piece class.
 */
class Piece;

class Pieces;

/**
 * Class that is used to handle mouse events.
 *
 * @author David
 */
class EventManager
{
private:
    bool liftedPiece;

    std::shared_ptr<Piece> piece;

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

public:

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

};


#endif //CHESS_EVENTMANAGER_H
