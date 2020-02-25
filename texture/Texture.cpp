//
// Created by david on 01. 01. 2020..
//

#include "Texture.h"
#include "../Game.h"

SDL_Texture *Texture::loadTexture(const char *path, int &width, int &height)
{
    SDL_Surface *surface = IMG_Load(path);

    width = surface->w;
    height = surface->h;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);

    return texture;
}
