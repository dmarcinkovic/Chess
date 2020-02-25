//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_TEXTURE_H
#define CHESS_TEXTURE_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * Used to load texture from image.
 *
 * @author David
 */
class Texture
{
public:

    /**
     * Static method that is used to load texture from image.
     *
     * @param path Path of the image.
     * @param width Variable in which width of the image will be stored.
     * @param height Variable in which height of the image will be stored.
     * @return Loaded texture.
     */
    static SDL_Texture *loadTexture(const char *path, int &width, int &height);
};


#endif //CHESS_TEXTURE_H
