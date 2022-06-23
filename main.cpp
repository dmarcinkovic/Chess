#include <chrono>
#include <iostream>

#include "Game.h"

int main()
{
	constexpr unsigned int FPS = 60;
	constexpr unsigned int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	unsigned int frameTime;

	auto start = std::chrono::high_resolution_clock::now();
	Game game("Chess", 800, 800);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Time to load game: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
			  << "\n";

	while (game.isRunning())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.draw();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return 0;
}
