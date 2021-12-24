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

### GLAD ###
add_library(glad include/glad/glad.h src/glad.c)

# Define all the libraries
set(LIBS
	${OPENGL_LIBRARY}
	glfw
	glad
)

# Add the executable
add_executable(Tetris
	src/main.cpp
	src/shaders.cpp
)

# Copy the shaders to the executable's directory
FILE(COPY resources DESTINATION "${CMAKE_BINARY_DIR}")

# Link Libraries
target_link_libraries(Tetris PUBLIC
	${LIBS}
)
