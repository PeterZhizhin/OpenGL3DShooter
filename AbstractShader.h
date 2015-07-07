#pragma once

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <string>

class AbstractShader 
{
public:
	static const GLint VERTEX_ATTRIB_LOCATION = 0;
	static const GLint TEXCOORD_ATTRIB_LOCATION = 1;
	static const GLint NORMAL_ATTRIB_LOCATION = 2;
	static const GLint MATRIX_LOCATION = 3;

	AbstractShader(GLuint programId);
	~AbstractShader();
	void bind();
	void unbind();
	void bindMatrix(glm::mat4 matrix);
protected:
	void assertIfNotBinded();
private:
	GLuint id;
	bool isBinded;
	virtual std::string getName();
};
