#include "ShaderLoader.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <streambuf>
#include <GL/glew.h>
#include <GL/gl.h>

std::string ShaderLoader::loadFile(std::string path)
{
	std::ifstream stream(path);	
	std::string result((std::istreambuf_iterator<char>(stream)),
			std::istreambuf_iterator<char>());
	return result;
}

GLuint ShaderLoader::createShader(std::string path, GLenum type) 
{
	GLuint shader = glCreateShader(type);
	auto source = loadFile(path).c_str();
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if(isCompiled==GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
		for (auto symbol : errorLog)
			std::cerr << symbol;
		glDeleteShader(shader);
		return 0;
	}

	return shader;
}


GLuint ShaderLoader::loadProgram(std::string vertexPath, std::string fragmentPath) 
{
	GLuint vertexShader = createShader(vertexPath, GL_VERTEX_SHADER);	
	GLuint fragmentShader = createShader(fragmentPath, GL_FRAGMENT_SHADER);
	if(vertexShader==0 || fragmentShader == 0)
		return 0;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
	if(isLinked==GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
	
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
		for (auto symbol : infoLog)
			std::cerr << symbol;
		
		glDeleteProgram(program);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		
		return 0;
	}

	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);	

	return program;
}
