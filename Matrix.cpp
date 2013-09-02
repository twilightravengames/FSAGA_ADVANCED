/*
 * Matrix.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: User
 */

#include <cmath>
#include "Matrix.h"
#include "allegroincludes.h"

//

namespace fsaga_oop {

Matrix::Matrix() {
	// TODO Auto-generated constructor stub

}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}




//rotate vertices at angle around x axis
//(around

// multiply vertices times
//
//	ROTATE AROUND X AXIS
//
//	|	1      0            0        |
//  |   0  cos(angle) -sin(angle)    |
//  |   0  sin(angle)    cos(angle)  |

//for rotations aroudn the x axis
//angle must be in radians
 Matrix Matrix::getAnXAxisRotationMatrix(float angle)
{
	Matrix m;

	m.setMatrixValue(0,0,1);
	m.setMatrixValue(1,0,0);
	m.setMatrixValue(2,0,0);

	m.setMatrixValue(0,1,0);
	m.setMatrixValue(1,1,cos(angle));
	m.setMatrixValue(2,1,(-sin(angle)));

	m.setMatrixValue(0,2,0);
	m.setMatrixValue(1,2,sin(angle));
	m.setMatrixValue(2,2,cos(angle));

	return m;
}


//  ROTATE AROUND Y AXIS
//
//
//  |   cos(angle)   0    sin(angle) |
//  |      0         1         0     |
//  |  -sin(angle)   0    cos(angle) |
//



//for rotations around the y axis
//angle must be in radians
 Matrix Matrix::getAnYAxisRotationMatrix(float angle)
{
	Matrix m;

	m.setMatrixValue(0,0,cos(angle));
	m.setMatrixValue(1,0,0);
	m.setMatrixValue(2,0,sin(angle));

	m.setMatrixValue(0,1,0);
	m.setMatrixValue(1,1,1);
	m.setMatrixValue(2,1,0);

	m.setMatrixValue(0,2,(-sin(angle)));
	m.setMatrixValue(1,2,0);
	m.setMatrixValue(2,2,cos(angle));

	return m;
}


//for multiplication of a vertex by a Matrix

 ALLEGRO_VERTEX Matrix::multiplyMatrixByVertex(ALLEGRO_VERTEX v, Matrix matrix)
{
	 ALLEGRO_VERTEX new_v;
	 //multiply v.x times the first row, summing products
	 //to get new x coordinate

	 new_v.x = v.x*matrix.getMatrixValue(0,0) + v.x*matrix.getMatrixValue(1,0) + v.x*matrix.getMatrixValue(2,0);
	 new_v.y = v.y*matrix.getMatrixValue(0,1) + v.y*matrix.getMatrixValue(1,1) + v.x*matrix.getMatrixValue(2,1);
	 new_v.z = v.z*matrix.getMatrixValue(0,2) + v.z*matrix.getMatrixValue(1,2) + v.z*matrix.getMatrixValue(2,2);

	 return new_v;
}






} /* namespace fsaga_oop */
