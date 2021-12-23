#ifndef __MAIN__
#define __MAIN__

/* Include statements */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>

/* Using statements */
using std::cout;
using std::endl;
using std::string;
using glm::value_ptr;
using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

/* Modes for title screen or playing the game */
enum screen_mode {
	TITLE,
	GAME
};

/* Global variables */
int CURRENT_SCREEN = TITLE;

/* Function declarations */
void resizeCallback(GLFWwindow* window, int width, int height);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void render(GLFWwindow* window);

#endif