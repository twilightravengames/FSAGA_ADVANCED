/*
 * RenderingEngine.cpp
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

//color macro constants


#include "RenderingEngine.h"
#include "GameMapState.h"
#include "allegro_colors.h"
#include "Game.h"
#include "Matrix.h"

namespace fsaga_oop {


RenderingEngine::~RenderingEngine() {
	// TODO Auto-generated destructor stub

}

//must be called before rendering starts,
//but after game_ptr is valid
//used to initialize camera
void RenderingEngine::init_objects(Game_Map_State *game_map_ptr) {



	camera.setToIdentity();


	 //for more information see gp2x wiz example in the allegro manual
	 //al_rotate_transform(&t, frames*0.1f); //frames is used to continually rotate primitive object
	//al_translate_transform(&t, this->W/2, H/2); //used to move the rendered primitives

	 //!al_translate_transform(&t, 300, 0);

	 //!al_use_transform(&t);



	 camera.useTransform();

	 //note camera rotations are in radians
	 //camera.rotateAroundX(game_map_ptr->getTwoHalfTerrainReference(), 250);

	 //camera.useTransform();

}

void RenderingEngine::render(Game_Map_State *game_map_ptr) {


	//there is an initial render, for the initial render
	//all the layers are drawn onto the map_buffer

	//for update renderings, update_render is called

	clear(map_buffer); //will set the map_buffer as target and clear it
	//do a clear screen and set map buffer as target


	 //CALL CLIPPING ROUTINES TO CLIP IMAGES
	 //The clipper goes through all the game objects
	 //setting their isVisible and isPartiallyVisible
	 //flags according to their visibility via the
	 //information provided by and stored in the camera

	 //logger("Running game renderer");

	//render_background_image(); //renders a background image, like mountains or a sunset
	 render_terrain_bitmap(game_map_ptr); //exists below player

	 //render_player_sprite(); //renders player sprite
	 //render_npc_sprite();    //renders the npc sprites
	 //render_enemy_sprite();  //renders the enemy sprites

	 //render overlap blocks
	 //	explanation: overlap blocks are regions of the map
	 //				 that are painted overtop of Seren
	 //				 but belong to the terrain_bitmap (floor bitmap)
	 //				 this method call re-renders all of them now that
	 //				 all the sprites have been drawn

	 //render top bitmap layer (bitmap layer overtop seren)


	 //is this legal?
	 blitter(this->getCameraPointer()); ////renders map buffer to back buffer and flips the back buffer with the screen


}


void RenderingEngine::update_render(Game_Map_State *game_map_ptr) {
//This method will call of the update_render routines
//in the different game map objects. While render
//draws everything, update_render will only update/
//those things that have changed (such as replacing swapppable
//bitmaps under the player, new animations, etc)
//the rest of the map buffer is kept intact.


//render update first renders the updates for the map
//then for the sprites
//then for the overlap blocks
//then for the top layer map
//then the sprite effects layer and the interface layer
//after blit but before page flip.


//The above was for sprites. Another is the map_buffer;
//So instead having to rewrite the entire map buffer
//data, when we go to update the map we only draw
//a certain window of the map buffer to the back buffer.
//This window is determined by the camera.


	//after calling all update_renders,

	//before blitting to the backbuffer, draw the overload
	//images using the overload blocks
	//explanation:

	//render overlap blocks
		 //	explanation: overlap blocks are regions of the map
		 //				 that are painted overtop of Seren
		 //				 but belong to the terrain_bitmap (floor bitmap)
		 //				 this method call re-renders all of them now that
		 //				 all the sprites have been drawn

	//blit to backbuffer

	//run render the top effects layer to the
	//backbuffer (instead of map_buffer so it doesn't
	//corrupt the map_buffer image)


	//and render the interface after that to the
	//back buffer and then page flip and we're done

//a master timer controls the update render process,
//and the timer can be accesssed and slowed
//for a slow-motion effect by rendering frames
//less often (less than 30 fps)

}



void RenderingEngine::clear(ALLEGRO_BITMAP *bitmap)
{
	//al_lock_bitmap(bitmap, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READWRITE);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(CLEAR_COLOR);
    //al_unlock_bitmap(bitmap);
}


//renders map buffer to back buffer and flips the back buffer with the screen
void RenderingEngine::blitter(Camera *camera_ptr)
{
	Game::logger("Running blitting routine for rendering Engine");

	al_set_target_bitmap(al_get_backbuffer(display));

	al_draw_bitmap_region(this->getMapBufferPointer(),
			camera_ptr->getScrollX()*camera_ptr->getScrollScalingFactorX(),
			camera_ptr->getScrollY()*camera_ptr->getScrollScalingFactorY(),
			this->screen_width,
			this->screen_height,
			this->getScreenOriginX(),
			this->getScreenOriginY(),
			NULL);

	//render interface layer will draw overtop of the map buffer
	//and on the screen
	////render_top_effects_layer(); //renders the top layer (for particle effects, etc.)
	//render_top_effects_layer, the particle stuff, is done here
	//because we don't want to associate it with the map buffer
	//so that the map buffer doesn't need to be repeatedly drawn
	//more is written in the comments on update_renderer

	//renderInterfaceLayer();


	al_flip_display();
}



////////////////Rendering Individual Layers//////////////////////


void RenderingEngine::render_terrain_bitmap(Game_Map_State *game_map_ptr)
{

	Game::logger("Rendering Engine is calling render terrain on the map pointer.");

	if (game_map_ptr->getBottomLayerBitmap().getBitmapPointer() == NULL)
	{
		Game::logger("In rendering engine, temp texture pointer is null");
	}

	game_map_ptr->getBottomLayerBitmapReference().render(game_map_ptr);

}







} /* namespace fsaga_oop */
