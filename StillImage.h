/*
 * StillImage.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef STILLIMAGE_H_
#define STILLIMAGE_H_

#include <iostream>
#include "interfaces/ImageInterface.h"
#include "allegroincludes.h"

using namespace std;

namespace fsaga_oop {

class StillImage: public fsaga_oop::ImageInterface {
public:
	StillImage();

	void render();

	virtual ~StillImage();

	ALLEGRO_BITMAP *getBitmapPointer()
	{ return this->bitmap; }

	void setBitmapPointer(ALLEGRO_BITMAP *bmp)
	{ this->bitmap = bmp; }

private:

	ALLEGRO_BITMAP *bitmap; //a copy of  the bitmap in memory

	int sheet_x_coordinate; //the x origin coordinate of the bitmap in the sprite sheet
	int sheet_y_coordinate; //the y origin coordinate of the bitmap in the sprite sheet
	int sheet_x_size; 		//the x size of the sprite on the sprite sheet
	int sheet_y_size;		//the y size of the sprite on the sprite sheet
	string source_sheet_name; //the name of the sprite sheet or solid bitmap

};

} /* namespace fsaga_oop */
#endif /* STILLIMAGE_H_ */
