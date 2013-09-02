/*
 * TiledHalfTerrainClass.cpp
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#include "TiledHalfTerrainClass.h"
#include "Game.h"
#include "allegroincludes.h"
#include "allegro_colors.h"

//this constant scales the quad so it is viewable
#define SURFACE_INFLATION_CONSTANT 10
#define TERRAIN_COLOR al_map_rgba(125,125,125, 125)


namespace fsaga_oop {

TiledHalfTerrainClass::TiledHalfTerrainClass() {
	// TODO Auto-generated constructor stub

}

TiledHalfTerrainClass::~TiledHalfTerrainClass() {
	// TODO Auto-generated destructor stub
}


void TiledHalfTerrainClass::generate_terrain()//Generates a generic 2.5d terrain
{
	//number of quads in the x and y direction
	int num_quads_y = 20;
	int num_quads_x = 20;

	//number of overall vertices, including shared
	int nver_ctr = 0;

	//height is a generic z value for where
	//the quad grid is floating
	int height = 1;

	int quad_tile_number_ctr = 0;

	//iterate in the y direction  (rows)
	for (int y=0;y<num_quads_y;y++)
	{
		//iterate in the x direction (columns)
		for (int x=0;x<num_quads_x;x++)
		{
			Quad_Tile quad_tile;
			TriangleFace face_a = calculate_quad_face_a(x, y, height, nver_ctr);
			TriangleFace face_b = calculate_quad_face_b(x, y, height, nver_ctr);
			quad_tile.face_a_index = face_a;
			quad_tile.face_b_index = face_b;

			//add to quad_tiles list

			quad_tiles[quad_tile_number_ctr] = quad_tile;
			terraingrid[x][y] = quad_tile_number_ctr;

			quad_tile_number_ctr++;

		}
	}

	this->number_of_vertices = nver_ctr;

}


TriangleFace TiledHalfTerrainClass::calculate_quad_face_a(int x, int y, int height, int &nver_ctr)
{
	//TWO FACES TO STORE PER ITERATION


	//FACE A
	TriangleFace face_a;


	//a temporary allegro vertex
	ALLEGRO_VERTEX temp_v_a;
	ALLEGRO_VERTEX temp_v_b;
	ALLEGRO_VERTEX temp_v_c;


	/////////////////////////////////////////////////
	///////////FACE A, VERTEX 1/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_a.x = x*SURFACE_INFLATION_CONSTANT;
	temp_v_a.y = (1 + y)*SURFACE_INFLATION_CONSTANT;
	temp_v_a.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_a.color = TERRAIN_COLOR;
	temp_v_a.u = 0.5;
	temp_v_a.v = 64.5;

	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	int tempVertexIndex = -1;

	//tempVertexIndex =this->getTempVertexIndex(temp_v_a);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_a;
		tempVertexIndex = nver_ctr;


		//add vertex to the references
		face_a.v0_index = nver_ctr;

		nver_ctr++;

	} else
	{
		face_a.v0_index = tempVertexIndex;
	}


	///////////////////////////////////

	/////////////////////////////////////////////////
	///////////FACE A, VERTEX 2/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_b.x = x*SURFACE_INFLATION_CONSTANT;
	temp_v_b.y = y*SURFACE_INFLATION_CONSTANT;
	temp_v_b.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_b.color = TERRAIN_COLOR;
	temp_v_b.u = 0.5;
	temp_v_b.v = 0.5;
	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	tempVertexIndex = -1;

	//tempVertexIndex =this->getTempVertexIndex(temp_v_b);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_b;
		tempVertexIndex = nver_ctr;

		//add vertex to the references

		face_a.v1_index = nver_ctr;

		nver_ctr++;
	} else

	{
		face_a.v1_index = tempVertexIndex;
	}

	/////////////////////////////////////////////

	/////////////////////////////////////////////////
	///////////FACE A, VERTEX 3/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_c.x = (1 + x)*SURFACE_INFLATION_CONSTANT;
	temp_v_c.y = (1 + y)*SURFACE_INFLATION_CONSTANT;
	temp_v_c.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_c.color = TERRAIN_COLOR;
	temp_v_c.u = 64.5;
	temp_v_c.v = 64.5;
	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	tempVertexIndex = -1;

	//tempVertexIndex = this->getTempVertexIndex(temp_v_c);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_c;
		tempVertexIndex = nver_ctr;


		//add vertex to the references
		face_a.v2_index = nver_ctr;

		nver_ctr++;


	} else {
		face_a.v2_index = tempVertexIndex;
	}

	////////////////////////////////////////

	return face_a;
}


TriangleFace TiledHalfTerrainClass::calculate_quad_face_b(int x, int y, int height, int &nver_ctr)
{
	//TWO FACES TO STORE PER ITERATION


	//FACE B
	TriangleFace face_b;

	//a temporary allegro vertex
	ALLEGRO_VERTEX temp_v_a;
	ALLEGRO_VERTEX temp_v_b;
	ALLEGRO_VERTEX temp_v_c;


	/////////////////////////////////////////////////
	///////////FACE B, VERTEX 1/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_a.x = x*SURFACE_INFLATION_CONSTANT;
	temp_v_a.y = y*SURFACE_INFLATION_CONSTANT;
	temp_v_a.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_a.color = TERRAIN_COLOR;
	temp_v_a.u = 0.5;
	temp_v_a.v = 0.5;

	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	int tempVertexIndex = -1;

	//tempVertexIndex =this->getTempVertexIndex(temp_v_a);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_a;
		tempVertexIndex = nver_ctr;


		//add vertex to the references
		face_b.v0_index = nver_ctr;

		nver_ctr++;

	} else
	{
		face_b.v0_index = tempVertexIndex;
	}


	///////////////////////////////////

	/////////////////////////////////////////////////
	///////////FACE B, VERTEX 2/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_b.x = (1 + x)*SURFACE_INFLATION_CONSTANT;
	temp_v_b.y = (1 + y)*SURFACE_INFLATION_CONSTANT;
	temp_v_b.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_b.color = TERRAIN_COLOR;
	temp_v_b.u = 64.5;
	temp_v_b.v = 64.5;

	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	tempVertexIndex = -1;

	//tempVertexIndex =this->getTempVertexIndex(temp_v_b);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_b;
		tempVertexIndex = nver_ctr;

		//add vertex to the references

		face_b.v1_index = nver_ctr;

		nver_ctr++;
	} else

	{
		face_b.v1_index = tempVertexIndex;
	}

	/////////////////////////////////////////////

	/////////////////////////////////////////////////
	///////////FACE B, VERTEX 3/////////////////////

	//intialized to 0, x increases by 1 for each
	//column
	temp_v_c.x = (1 + x)*SURFACE_INFLATION_CONSTANT;
	temp_v_c.y = y*SURFACE_INFLATION_CONSTANT;
	temp_v_c.z = height*SURFACE_INFLATION_CONSTANT;
	temp_v_c.color = TERRAIN_COLOR;
	temp_v_c.u = 64.5;
	temp_v_c.v = 0.5;

	//check to see if vertex already exists
	//and if it does, get the index so we can
	//store the index

	tempVertexIndex = -1;

	//tempVertexIndex = this->getTempVertexIndex(temp_v_c);

	//the vertex is not yet added to the terrain map
	if (tempVertexIndex == -1)
	{
		vertex_list[nver_ctr] = temp_v_c;
		tempVertexIndex = nver_ctr;


		//add vertex to the references
		face_b.v2_index = nver_ctr;

		nver_ctr++;


	} else {
		face_b.v2_index = tempVertexIndex;
	}

	////////////////////////////////////////

	return face_b;
}


//used in creation of flat quad surface
int TiledHalfTerrainClass::getTempVertexIndex(ALLEGRO_VERTEX v)
{
	//searches vertices for a match to vertex v
	//if there is a match, returns the index into the array
	//for the vertex
	//if no match, returns -1

	for (int i = 0; i < MAX_NUMBER_OF_VERTICES; i++)
	{
		ALLEGRO_VERTEX t_v = vertex_list[i];

		if (t_v.x == v.x)
		{
			if (t_v.y == v.y)
			{
				if (t_v.z == v.z) {
					return i;
				}
			}
		}

	}

	return -1;
}

//class function called from within master rendering
//function of the renderingEngine
//should draw to map_buffer using draw primitive
//on this classes triangles/vertices
void TiledHalfTerrainClass::render(ALLEGRO_BITMAP *terrain_texture)
{


	ALLEGRO_VERTEX v[3];

	v[0].x = 10;
	v[0].y = 10;
	v[0].z = 1;
	v[0].color = MID_COLOR;
	v[0].u = 0.5;
	v[0].v = 0.5;


	v[1].x = 300;
	v[1].y = 300;
	v[1].z = 1;
    v[1].color = MID_COLOR;
	v[1].u = 64.5;
	v[1].v = 64.5;


	v[2].x = 300;
	v[2].y = 10;
	v[2].z = 1;
	v[2].color = MID_COLOR;
	v[2].u = 64.5;
	v[2].v = 0.5;
	//Game::logger("Running tiledhalfterrainclass rendering of primitives");
		//al_draw_prim(v, NULL, terrain_texture, 0, 3, ALLEGRO_PRIM_TRIANGLE_LIST);

	if (terrain_texture == NULL)
	{
		Game::logger("NUll terrain texture");
	}

	al_draw_prim(vertex_list, NULL, terrain_texture, 0, number_of_vertices, ALLEGRO_PRIM_TRIANGLE_LIST);

	Game::logger("Vertices for first vertex:");
	Game::logfloat(vertex_list[0].x);
	Game::logfloat(vertex_list[0].y);
	Game::logfloat(vertex_list[0].z);

	Game::logfloat(vertex_list[1].x);
	Game::logfloat(vertex_list[1].y);
	Game::logfloat(vertex_list[1].z);

	Game::logfloat(vertex_list[2].x);
	Game::logfloat(vertex_list[2].y);
	Game::logfloat(vertex_list[2].z);

	//al_draw_line(10, 10, 300, 300, WHITE_COLOR, 5);

}


} /* namespace fsaga_oop */
