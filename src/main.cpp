#include "main.hpp"

int main() {
	GLFWwindow* window;
	CURRENT_SCREEN = TITLE;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Tetris", NULL, NULL);
	if (!window) {
		cout << "Failed to create a window" << endl;
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, resizeCallback);

	/* Initialize GLAD */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	render(window);

	glfwTerminate();
	return 0;
}

/* Render Function */
void render(GLFWwindow* window) {
	/* Create a Vertex Array Objects */
	unsigned int vertexArrayID;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	/* Vertex buffer for a triangle */
	static const float data[] = {
		-.5f, -.5f,  .0f,
		 .5f, -.5f,  .0f,
		 .0f,  .5f,  .0f
	};

	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Process user keyboard input */
		glfwSetKeyCallback(window, keyCallback);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		if (CURRENT_SCREEN) {
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glDisableVertexAttribArray(0);
		}
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
}

/* Resize the window */
void resizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

/* Process the key input */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case(GLFW_KEY_ESCAPE):
			glfwSetWindowShouldClose(window, true);
			break;
		case(GLFW_KEY_ENTER):
			CURRENT_SCREEN ^= 1; // Flip the bit
			break;
		default:
			break;
		}
	}
}
