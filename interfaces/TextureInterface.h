/*
 * TextureInterface.h
 *
 *  Created on: Sep 2, 2012
 *      Author: User
 */

#ifndef TEXTUREINTERFACE_H_
#define TEXTUREINTERFACE_H_

namespace fsaga_oop {

class TextureInterface {
public:
	TextureInterface();
	virtual ~TextureInterface();

private:
	int x_screen_position;
	int y_screen_position;
};

} /* namespace fsaga_oop */
#endif /* TEXTUREINTERFACE_H_ */
