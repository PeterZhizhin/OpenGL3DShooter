#pragma once

#include "VertexData.h"


#include <vector>
#include <GL/glew.h>

class VertexArray
{
public:
	VertexArray(std::vector<VertexData> vertecies);	
	~VertexArray();
	void bind();
	void unbind();
	void render();
private:
	void assertIfNotBinded();
	bool isBinded;
	GLuint vaoID;
	GLuint vboID;
	GLsizei verteciesCount;
};
