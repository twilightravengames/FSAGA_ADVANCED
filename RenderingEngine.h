/*
 * RenderingEngine.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef RENDERINGENGINE_H_
#define RENDERINGENGINE_H_

#include "allegroincludes.h"
#include "Camera.h"
#include "GameMapState.h"

namespace fsaga_oop {

class RenderingEngine {
	int max_map_width;
	int max_map_height;
	int screen_width;
	int screen_height;
	int screen_origin_x;
	int screen_origin_y;


public:
	RenderingEngine() : max_map_width(1280), max_map_height(960), screen_width(640), screen_height(480),
	screen_origin_x(0), screen_origin_y(0) {};

	void init_objects(Game_Map_State *game_map_ptr);

	virtual ~RenderingEngine();

	void render(Game_Map_State *game_map_ptr); //renders the initial scene
    void update_render(Game_Map_State *game_map_ptr); //performs an update rendering

	//clear clears a bitmap to the CLEAR_COLOR constant
	//blitter performs the page flip operation+++
	void clear(ALLEGRO_BITMAP *bitmap);
	void blitter(Camera *camera_ptr);

	///individual rendering functions for layers
	void render_terrain_bitmap(Game_Map_State *game_map_ptr);




	//

	Camera getCopyofCamera() {
		return camera;
	}

	Camera * getCameraPointer() {
		return &camera;
	}

	ALLEGRO_DISPLAY * getDisplayPointer() {
		return display;
	}

	void setDisplayPointer(ALLEGRO_DISPLAY *d) {
		display = d;
	}

	ALLEGRO_BITMAP * getMapBufferPointer() {
		return map_buffer;
	}

	void setMapBufferPointer(ALLEGRO_BITMAP *b) {
		map_buffer = b;
	}

	int getMaxMapWidth() {
		return this->max_map_width;
	}

	int getMaxMapHeight() {
		return this->max_map_height;
	}

	int getScreenWidth() {
		return this->screen_width;
	}

	int getScreenHeight() {
		return this->screen_height;
	}

	int getScreenOriginX() {
		return this->screen_origin_x;
	}

	int getScreenOriginY() {
		return this->screen_origin_y;
	}

private:

	//Private Allegro Specific Variables

	ALLEGRO_DISPLAY *display;

	//the semi-permanent memory map containing
	//the entire map image data for the current map
	//the corresponding grid in the map state
	//corresponds with this buffer, divided into
	//logical iosmetric square units
	ALLEGRO_BITMAP *map_buffer;



	Camera camera; 		//A camera object for scrolling
							//and view control


};

} /* namespace fsaga_oop */
#endif /* RENDERINGENGINE_H_ */
