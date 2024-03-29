//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <SDL2/SDL.h>
#include <memory>

#include "Piece.h"

/**
 * Main class. This class creates game loop.
 *
 * @author David
 */
class Game
{
private:
	static SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event{};

	bool running;
	bool keyPressed{};

	std::unique_ptr<class Board> board;
	std::shared_ptr<class Pieces> pieces;

	std::unique_ptr<class EventManager> eventManager{};
	std::unique_ptr<class ICheckObserver> checkObserver;

public:
	/**
	 * Player turn.
	 */
	static PieceColor turn;

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

	/**
	 * Method that returns pointer to SDL Window.
	 *
	 * @return Pointer to SDL Window.
	 */
	static SDL_Window *getWindow();

private:

	/**
	 * Handle key pressed events.
	 */
	void handleKeyEvents();
};


#endif //CHESS_GAME_H
