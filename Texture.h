/*
 * Texture.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "interfaces/TextureInterface.h"
#include "StillImage.h"

namespace fsaga_oop {

class Texture: public fsaga_oop::TextureInterface {
public:
	Texture();

	//standard render function called by renderer
	void render();

	//INHERITS FROM TEXTURE_INTERFACE
	//position on screen (in pixels)
	//int x_screen_position
	//int y_screen_position

	virtual ~Texture();

private:

	//still bitmap wrapper class representing the texture
	StillImage still_image;
};

} /* namespace fsaga_oop */
#endif /* TEXTURE_H_ */
