//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <SDL2/SDL.h>
#include <memory>

#include "board/Board.h"
#include "piece/Piece.h"
#include "event/EventManager.h"

/**
 * Predeclaration of pieces class.
 */
class Pieces;

class EventManager;

class Board;

enum class PieceColor;

/**
 * Main class. This class creates game loop.
 *
 * @author David
 */
class Game
{
private:
    SDL_Window *window;
    SDL_Event event{};
    bool running;

    std::unique_ptr<Board> board;
    std::shared_ptr<Pieces> pieces;

    std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>();

public:
    static SDL_Renderer *renderer;

    /**
     * Player turn.
     */
    static PieceColor turn;

    /**
     * Width and height of the window.
     */
    static int width, height;

    /**
     * Game constructor. It creates new window.
     *
     * @param title Title of the window.
     * @param w Width of the window.
     * @param h Height of the window.
     */
    Game(const char *title, int w, int h);

    /**
     * Destructor. It is used to destroy window.
     */
    ~Game();

    /**
     * Method used to handle events.
     */
    void handleEvents();

    /**
     * Returns true if game if running, otherwise returns false.
     *
     * @return True if game if running, otherwise returns false.
     */
    [[nodiscard]] bool isRunning() const;

    /**
     * Method used to draw all objects of the game once every frame.
     */
    void draw();
};


#endif //CHESS_GAME_H
