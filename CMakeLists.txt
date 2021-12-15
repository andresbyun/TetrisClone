cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tetris)

include_directories(
	include/glm/
	include/glfw-3.3.6/include
)

# add the executable
add_executable(Tetris
	src/main.cpp
)