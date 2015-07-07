#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H 

#include <string>
#include <GL/glew.h>

class ShaderLoader 
{
public:
	static GLuint loadProgram(std::string vertexPath, std::string fragmentPath);
private: 
	static std::string loadFile(std::string path);
	static GLuint createShader(std::string path, GLenum type);
};

#endif
