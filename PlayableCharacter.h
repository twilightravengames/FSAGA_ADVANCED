/*
 * PlayableCharacter.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef PLAYABLECHARACTER_H_
#define PLAYABLECHARACTER_H_

#include "Sprite.h"

namespace fsaga_oop {

//A playable character is a sprite
//inherits from Sprite Class, which inherits from TextureInterface
//but contains player data as well
class PlayableCharacter: public fsaga_oop::Sprite {
public:
	PlayableCharacter();

	//INHERITS FROM SPRITE
	//intiate movement for the sprite in direction direction
	//and with velocity velocity
	//void move(int direction, int velocity);

	//standard render function called by renderer
	//void render();

	//standard update function called by main game loop
	//polls sprite for updates to itself
	//typically passes control on to animations (animatedImages)
	//updates animation's timing/current frame and position
	//void update();

	//INHERITS FROM TEXTURE_INTERFACE
	//position on screen (in pixels)
	//int x_screen_position
	//int y_screen_position

	virtual ~PlayableCharacter();
};

} /* namespace fsaga_oop */
#endif /* PLAYABLECHARACTER_H_ */
