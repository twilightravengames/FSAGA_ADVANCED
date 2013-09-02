/*
 * InputHandler.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

namespace fsaga_oop {

class InputHandler {
public:
	InputHandler();

	//universal update method
	//every pollable class has an update method
	//called by the main game loop to poll input
	void update();



	virtual ~InputHandler();
};

} /* namespace fsaga_oop */
#endif /* INPUTHANDLER_H_ */
