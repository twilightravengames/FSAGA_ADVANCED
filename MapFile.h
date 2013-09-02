/*
 * MapFile.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef MAPFILE_H_
#define MAPFILE_H_

#include "GameMapState.h"

namespace fsaga_oop {

class Map_File {
public:
	Map_File() {

		//items that must be constructed upon Map_File construction
		this->game_map_state = new Game_Map_State();
	}

	~Map_File() {

		//items that were constructed on class construction
		//must be destructed by the class

		delete game_map_state;


		// TODO Auto-generated destructor stub
	}


	//Loads a map file from disk , creates data structure
	//and loads file into data structure
	void load();

	//Save map data structure to disk
	void save();

	//Generates a generic 2.5d terrain
	//Disabled for now (using bitmapped terrain)
	//void generate_terrain() {
	////	game_map_state->getTwoHalfTerrainReference().generate_terrain();

	//}

	//returns a reference to a game map state structure
	Game_Map_State * get_map_state_ptr() {
		return game_map_state;
	}



private:
	Game_Map_State *game_map_state;
};

} /* namespace fsaga_oop */
#endif /* MAPFILE_H_ */
