#ifndef __FIELD__
#define __FIELD__

#include <GameElements/Tetromino.hpp>
#include <glm/glm.hpp>

class Field {
public:
	Field();
protected:
	BoolMat board = BoolMat(10, 20);
};

#endif
