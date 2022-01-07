#include "main.hpp"

/* Using statements */
using std::cout;
using std::endl;
using std::string;
using glm::value_ptr;
using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

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

	/* Create Program */
	unsigned int programId = LoadShaders(
		"resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Process user keyboard input */
		glfwSetKeyCallback(window, keyCallback);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (CURRENT_SCREEN == GAME) {
			drawGame(programId, vertexBuffer);
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
