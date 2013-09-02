/*
 * TimerClass.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef TIMERCLASS_H_
#define TIMERCLASS_H_

namespace fsaga_oop {

class TimerClass {
public:
	TimerClass();

	//standard update function called to poll the timer
	//and update its ticks per game loop cycle
	void update(void);

	virtual ~TimerClass();
};

} /* namespace fsaga_oop */
#endif /* TIMERCLASS_H_ */
