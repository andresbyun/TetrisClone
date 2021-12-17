#ifndef __MAIN__
#define __MAIN__

/* Include statements */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

/* Using statements */
using std::cout;
using std::endl;

/* Function declarations */
void resizeCallback(GLFWwindow* window, int width, int height);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif