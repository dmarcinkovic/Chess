//
// Created by david on 01. 01. 2020..
//

#ifndef CHESS_TEXTURE_H
#define CHESS_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>

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
	 * @param data Image data.
	 * @param size Image data size.
	 * @param width Variable in which width of the image will be stored.
	 * @param height Variable in which height of the image will be stored.
	 * @return Loaded texture.
	 */
	static SDL_Texture *loadTexture(std::uint8_t *data, unsigned int size, int &width, int &height);
};


#endif //CHESS_TEXTURE_H
