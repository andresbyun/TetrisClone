#ifndef __GAME__
#define __GAME__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <GameElements/Field.hpp>
#include <GameElements/Tetromino.hpp>

void gameInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void drawGame(unsigned int programId, unsigned int vertexBuffer);

#endif
