//
// Created by david on 01. 01. 2020..
//

#include "Texture.h"
#include "Game.h"

SDL_Texture *Texture::loadTexture(std::uint8_t *data, unsigned int size, int &width, int &height)
{
	SDL_RWops *rw = SDL_RWFromMem(data, static_cast<int>(size));
	SDL_Surface *surface = IMG_Load_RW(rw, 1);

	width = surface->w;
	height = surface->h;

	SDL_Renderer *renderer = SDL_GetRenderer(Game::getWindow());
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	return texture;
}
