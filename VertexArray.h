#pragma once

#include "VertexData.h"

#include <vector>

class VertexArray
{
public:
	VertexArray(std::vector<VertexData> vertecies);	
	~VertexArray();
	void bind();
	void unbind();
	void render();
private:
	bool assertIfNotBinded();
	bool isBinded;
	GLuint vaoID;
	GLuint vboID;
	GLsizei verteciesCount;
};
