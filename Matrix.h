/*
 * Matrix.h
 *
 *  Created on: Sep 6, 2012
 *      Author: User
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "allegroincludes.h"

namespace fsaga_oop {

class Matrix {
public:
	Matrix();
	virtual ~Matrix();



	int getMatrixValue(int a, int b) {
		return matrix[a][b];
	}

	void setMatrixValue(int a, int b, float value) {
		matrix[a][b] = value;
	}

	//for rotations aroudn the x axis
	//angle must be in randians
	static Matrix getAnXAxisRotationMatrix(float angle);

	//for rotations around the y axis
	//angle must be in radians
	static Matrix getAnYAxisRotationMatrix(float);

	//for matrix multiplication

	// (..,..,..) [      ]
	//			  [      ]
	//            [      ]

	static ALLEGRO_VERTEX multiplyMatrixByVertex(ALLEGRO_VERTEX v, Matrix matrix);

private:
	float matrix[3][3]; //first value is x, second is y
};

} /* namespace fsaga_oop */
#endif /* MATRIX_H_ */
