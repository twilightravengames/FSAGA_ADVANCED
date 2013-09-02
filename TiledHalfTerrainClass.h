/*
 * TiledHalfTerrainClass.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef TILEDHALFTERRAINCLASS_H_
#define TILEDHALFTERRAINCLASS_H_




#include "allegroincludes.h"

#include "allegro_colors.h"




//MAP CONSTANTS
//Max number of Tiles (in tile units, not pixels)
#define TILE_GRID_MAX_WIDTH 100
#define TILE_GRID_MAX_HEIGHT 100

//Maximum number of vertices to compose the tiled 2 1/2 d terrain
#define MAX_NUMBER_OF_VERTICES 10000


namespace fsaga_oop {


/* a quad tile contains two indices into the triangle list
one for each face (triangle) making up the quad

to get a triangle's verts,
vertex_list[triangle_face.v0_index] = first vertex
vertex_list[triangle_face.v1_index] = second vertex
vertex_list[triangle_face.v2_index] = third vertex

to get a triangle_face,

quad_tile quad;
triangle_face_a = quad.face_a_index;
triangle_face_b = quad.face_b_index;

and to index into quads use terrain grid indices

and so on....



*/


typedef struct TriangleFace {
	//vertices references
	int v0_index; 	//index into the vertices list, represents the first vertex
	int v1_index;	//index into the vertices list, represents the second vertex
	int v2_index; 	//index into the vertices list, represents the third vertex

} TriangleFace;

//a quad tile contains two indices into the triangle list
//one for each face (triangle) making up the quad


typedef struct Quad_tile {
	 TriangleFace face_a_index; //index into triangle list for left half of quad (x least)
	 TriangleFace face_b_index; //index into triangle lsit for right half of quad (x most)
}Quad_Tile;


class TiledHalfTerrainClass {
public:
	TiledHalfTerrainClass();

	int getTempVertexIndex(ALLEGRO_VERTEX v);

	ALLEGRO_VERTEX *getVertexListPointer() {
		return vertex_list;
	}

	int getNumberOfVertices() {
		return this->number_of_vertices;
	}

	void render(ALLEGRO_BITMAP *terrain_texture); //renders the tiled 2 1/2d terrain

	//used for generating a generic surface of subdivided quads
	void generate_terrain();

	virtual ~TiledHalfTerrainClass();

private:

	TriangleFace calculate_quad_face_a(int x, int y, int height, int &nver_ctr);
		TriangleFace calculate_quad_face_b(int x, int y, int height, int &nver_ctr);
	//This terrain grid contains indices to quads in the quad list,
	//making up the terrain used to compare quad tiles to other game content
	//such as tag blocks and collision blocks and sprites
	int terraingrid[TILE_GRID_MAX_WIDTH][TILE_GRID_MAX_HEIGHT];

	//list of quads, indexed by the value stored in terraingrid
	Quad_Tile quad_tiles[TILE_GRID_MAX_WIDTH*TILE_GRID_MAX_HEIGHT*2]; //list of quad tiles

	//the total number of vertices in the list
	int number_of_vertices;

	ALLEGRO_VERTEX vertex_list[MAX_NUMBER_OF_VERTICES]; //all of the vertices in the terrain model

};

} /* namespace fsaga_oop */
#endif /* TILEDHALFTERRAINCLASS_H_ */
