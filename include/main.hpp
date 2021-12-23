#ifndef __MAIN__
#define __MAIN__

/* Include statements */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <shaders.hpp>

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