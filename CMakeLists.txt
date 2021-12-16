cmake_minimum_required(VERSION 3.10)
project(Tetris)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory (include/glfw-3.3.6)

# include directories
include_directories(
	include/glm/
	include/glfw-3.3.6/include
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
)

# Add the executable
add_executable(Tetris
	src/main.cpp
)

# Link Libraries
target_link_libraries(Tetris
	${ALL_LIBS}
)