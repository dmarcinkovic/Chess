//
// Created by david on 01. 01. 2020..
//

#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "EventManager.h"
#include "CheckObserver.h"

PieceColor Game::turn = PieceColor::WHITE;
SDL_Window *Game::window;

Game::Game(const char *title, int w, int h)
		: running{true}, checkObserver(std::make_unique<CheckObserver>())
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED_MASK,
							  SDL_WINDOWPOS_CENTERED_MASK, w, h, false);

	renderer = SDL_CreateRenderer(window, -1, false);

	board = std::make_unique<Board>(w, h);

	pieces = std::make_shared<Pieces>();
	pieces->getAvailableMoves();
	pieces->addObserver(checkObserver.get());

	eventManager = std::make_unique<EventManager>(pieces);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
}

void Game::handleEvents()
{
	while (SDL_PollEvent(&event) != 0 && event.type == SDL_MOUSEMOTION);

	switch (event.type)
	{
		case SDL_QUIT :
			running = false;
			break;
		case SDL_MOUSEBUTTONDOWN :
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				eventManager->mousePressed(pieces->getPiece(event.button.x, event.button.y), event);
			}
			break;
		case SDL_MOUSEBUTTONUP :
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				eventManager->mouseReleased(event, pieces);
			}
			break;
		case SDL_MOUSEMOTION :
			eventManager->mouseMoved(event);
			break;
		case SDL_KEYDOWN :
			keyPressed = true;
			break;
		case SDL_KEYUP :
			if (keyPressed)
			{
				handleKeyEvents();
			}
			break;
		default:
			break;
	}
}

bool Game::isRunning() const
{
	return running;
}

void Game::draw()
{
	SDL_RenderClear(renderer);

	board->draw();
	pieces->draw();

	SDL_RenderPresent(renderer);
}

SDL_Window *Game::getWindow()
{
	return window;
}

void Game::handleKeyEvents()
{
	if (event.key.keysym.sym == SDLK_f)
	{
		board->flip();
	} else if (event.key.keysym.sym == SDLK_LEFT)
	{
		eventManager->undo();
	} else if (event.key.keysym.sym == SDLK_RIGHT)
	{
		eventManager->redo();
	}
	keyPressed = false;
}
