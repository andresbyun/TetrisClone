#ifndef __TETROMINO__

#include <vector>
#include <glm/glm.hpp>

using glm::mat4;
using glm::vec2;

class Tetromino {
public:
	Tetromino();
	void Rotate();

protected:
	/* Tetromino fields */
	int id;
	vec2 position = vec2(0, 0);
	mat4 state;

	/* Tetromino types */
	mat4 types[7] = {
		mat4(
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			1, 1, 1, 0,
			0, 1, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			0, 1, 0, 0,
			0, 1, 0, 0,
			1, 1, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 1, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			0, 1, 1, 0,
			1, 1, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		),
		mat4(
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		)
	}
};

#endif
