cmake_minimum_required(VERSION 3.10)
project(Tetris)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory(include/glfw-3.3.6)
add_subdirectory(include/glm)

# include directories
include_directories(
	include/
	include/glm/
	include/glfw-3.3.6/include
)

add_library(glad include/glad/glad.h src/glad.c)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
)

# Add the executable
add_executable(Tetris
	src/main.cpp
)

# Link Libraries
target_link_libraries(Tetris PUBLIC
	${ALL_LIBS}
)

target_link_libraries(Tetris
	PRIVATE
	glad
)