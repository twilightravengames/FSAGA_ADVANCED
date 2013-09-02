/*
 * Sprite.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <vector>
#include "interfaces/TextureInterface.h"
#include "AnimatedImage.h"

using namespace std;

namespace fsaga_oop {

class Sprite: public fsaga_oop::TextureInterface {
public:
	Sprite();

	//intiate movement for the sprite in direction direction
	//and with velocity velocity
	void move(int direction, int velocity);

	//standard render function called by renderer
	void render();

	//called by the update renderer
	//if the character has moved, will repaint the background
	//replacing the image where the character had overlapped on the tile
	//using the swap_layer_temp image
	//if the character has not moved but is in animation
	//will redraw the character using the animation
	//if no changes have been made (no animation or movement)
	//then update_render does nothing
	void update_render();

	//standard update function called by main game loop
	//polls sprite for updates to itself
	//typically passes control on to animations (animatedImages)
	//updates animation's timing/current frame and position
	//if the sprite has moved will record the new block of bitmap
	//into the swap layer bitmap member variable for use by
	//update_render
	void update();

	//INHERITS FROM TEXTURE_INTERFACE
	//position on screen (in pixels)
	//int x_screen_position
	//int y_screen_position


	virtual ~Sprite();
private:
	//a vector of animations. Each animatedImages object
	//holds an animation possible for the sprite
	boolean isVisible; //if isVisible is true, then the sprite should be drawn
					   //and the image may be partially visible (check isPartiallyVisible flag)
					   //this flag is set by the clipping routine.
					   //if isVisible is false, then the classes render() method
					   //method does not paint the sprite

	boolean isPartiallyVisible; //if isPartiallyVisible is true, then the sprite is partially off screen
								//but still visible and therefore still drawn to the
								//mapBuffer by its render method
								//if both isVisible and isPartiallyVisible are false
								//the sprite is off screen and not drawn by its renderer
								//This flag is set by the clipping routine

	ALLEGRO_BITMAP *swapLayerTemp; //this image represents the data that is present at the
								   //location the sprite is about to move to or already at
								   //so that when the sprite is moved, this can be written
								   //back to the image in the map_buffer instead of re-rendering
								   //the entire map_buffer;

	vector<AnimatedImage> animatedImages;

	TimerClass timer;	//a timer used to create even flowing
						//character movement
};

} /* namespace fsaga_oop */
#endif /* SPRITE_H_ */
