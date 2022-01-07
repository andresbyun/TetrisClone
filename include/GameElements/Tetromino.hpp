#ifndef __TETROMINO__
#define __TETROMINO__

#include <vector>
#include <glm/glm.hpp>
#include <BoolMat.hpp>
#include <stdlib.h>
#include <glad/glad.h>

using glm::vec2;
using std::vector;

class Tetromino {
public:
	Tetromino();
	void Rotate();
	void MoveLeft();
	void MoveRight();
	void Draw();

protected:
	/* Tetromino fields */
	int id;
	vec2 position = vec2(0, 0);
	BoolMat state = BoolMat(4, 4);
};

#endif
