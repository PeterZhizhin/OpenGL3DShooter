#include "AbstractShader.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


AbstractShader::AbstractShader(GLuint programId)
{
	id = programId;
	isBinded = false;
}
AbstractShader::~AbstractShader()
{
	glDeleteShader(id);
}
void AbstractShader::bind()
{
	glUseProgram(id);
	isBinded = true;
}
void AbstractShader::unbind()
{
	glUseProgram(0);
	isBinded = false;
}
std::string AbstractShader::getName()
{
	return "AbstractShader";
}
void AbstractShader::assertIfNotBinded()
{
	if(!isBinded)
		std::cerr << "Shader " << getName() << " is not binded. Forcing." << std::endl;
}
void AbstractShader::bindMatrix(glm::mat4 matrix)
{
	assertIfNotBinded();
	glUniformMatrix4fv(MATRIX_LOCATION, 1, GL_FALSE, glm::value_ptr(matrix));
}
