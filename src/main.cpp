#include "main.hpp"

int main() {
    GLFWwindow* window;

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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Process user keyboard input */
        glfwSetKeyCallback(window, keyCallback);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}

/* Resize the window */
void resizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

/* Process the key input */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    switch (key){
    case(GLFW_KEY_ESCAPE):
        glfwSetWindowShouldClose(window, true);
    default:
        break;
    }
}
