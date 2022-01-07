 #include <game.hpp>

/* User input while playing the game */
void gameInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case(GLFW_KEY_ESCAPE):
			glfwSetWindowShouldClose(window, true);
			break;
		case(GLFW_KEY_ENTER):
			break;
		default:
			break;
		}
	}
}

/* Render the game */
void drawGame(unsigned int programId, unsigned int vertexBuffer) {
	glUseProgram(programId);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}
