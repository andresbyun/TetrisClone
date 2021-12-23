#include <shaders.hpp>

#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>

using std::string;
using std::stringstream;
using std::ifstream;

/* Function prototypes only to be accessed by this file */
string ShaderCode(string filepath);
void CompileShader(unsigned int shaderId, char const* sourcePtr);
unsigned int CreateShader(string path, GLenum type);
void DeleteShader(unsigned int programId, unsigned int shaderId);

/* Return a ProgramID that has attached the Vertex and Fragment Shaders with their respective paths */
unsigned int LoadShaders(string vertexPath, string fragmentPath) {
	/* Create shaders */
	unsigned int VertexShaderId = CreateShader(vertexPath, GL_VERTEX_SHADER);
	unsigned int FragmentShaderId = CreateShader(fragmentPath, GL_FRAGMENT_SHADER);

	/* Link the program */
	unsigned int ProgramId = glCreateProgram();
	glAttachShader(ProgramId, VertexShaderId);
	glAttachShader(ProgramId, FragmentShaderId);
	glLinkProgram(ProgramId);

	/* Delete shaders */
	DeleteShader(ProgramId, VertexShaderId);
	DeleteShader(ProgramId, FragmentShaderId);

	return ProgramId;
}

/*	Create a shader and compile it based on the pathand the type.
	Returns the ID of the shader
*/
unsigned int CreateShader(string path, GLenum type) {
	/* Create the shader */
	unsigned int shaderId = glCreateShader(type);

	/* Obtain the source code for the shader */
	string srcCode = ShaderCode(path);
	
	/* Compile the shader with its source code */
	CompileShader(shaderId, srcCode.c_str());

	return shaderId;

}

/* Return the code of the shader based on the file path of the shader */
string ShaderCode(string filepath) {
	string code;
	ifstream ShaderStream(filepath, std::ios::in);
	
	if (ShaderStream.is_open()) {
		stringstream strm;
		strm << ShaderStream.rdbuf();
		code = strm.str();
		ShaderStream.close();
	}
	else {
		return "";
	}

	return code;
}

/* Compile the shader given its ID */
void CompileShader(unsigned int shaderId, char const* sourcePtr) {
	glShaderSource(shaderId, 1, &sourcePtr, NULL);
	glCompileShader(shaderId);
}

/* Detach and delete the program */
void DeleteShader(unsigned int programId, unsigned int shaderId) {
	glDetachShader(programId, shaderId);
	glDeleteShader(shaderId);
}
