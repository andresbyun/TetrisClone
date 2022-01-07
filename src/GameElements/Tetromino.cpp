#include <GameElements/Tetromino.hpp>

/* Constructor */
Tetromino::Tetromino() {
	/* Tetromino types */
	bool types[7][16] = {
		{
			true, true, true, true,
			false, false, false, false,
			false, false, false, false,
			false, false, false, false
		},
		{
			false, true, true, false,
			false, true, true, false,
			false, false, false, false,
			false, false, false, false
		},
		{
			true, true, true, false,
			false, true, false, false,
			false, false, false, false,
			false, false, false, false
		},
		{
			false, true, false, false,
			false, true, false, false,
			true, true, false, false,
			false, false, false, false
		},
		{
			true, false, false, false,
			true, false, false, false,
			true, true, false, false,
			false, false, false, false
		},
		{
			false, true, true, false,
			true, true, false, false,
			false, false, false, false,
			false, false, false, false
		},
		{
			true, true, false, false,
			false, true, true, false,
			false, false, false, false,
			false, false, false, false
		}
	};

	id = rand() % 7;
	state = BoolMat(4, 4, types[id]);
}

/* Rotate the Tetromino by 90 degrees */
void Tetromino::Rotate() {
	BoolMat nextState(4, 4);
	int maxIndex = 3;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nextState[maxIndex - j][i] = state[i][j];
		}
	}

	state = nextState;
}

/* Move the tetromino to the left */
void Tetromino::MoveLeft() {
	position.x = position.x == 0 ?
		0 : position.x - 1;
}

/* Move the tetromino to the right */
void Tetromino::MoveRight() {
	position.x = position.x == 16 ?
		16 : position.x + 1;
}

void Tetromino::Draw() {
	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (state[i][j]) {
				static const float vertices[] = {
					i, j, 0,
					i+1, j, 0,
					i+1, j+1, 0,
					i, j+1, 0
				};

				glEnableVertexAttribArray(0);
				glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

			}
		}
	}
}
