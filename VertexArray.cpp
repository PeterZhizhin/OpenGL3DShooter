#include "VertexArray.h"


#include <vector>
#include <iostream>

VertexArray::VertexArray(std::vector<VertexData> vertecies)
{
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	VertexData::bindDataToVBO(vertecies);
	VertexData::bindPointers();	
	VertexData::enablePointers();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	isBinded = false;
}

VertexArray::~VertexArray() 
{
	glDeleteBuffers(1, &vboID);
	glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::bind() 
{
	glBindVertexArray(vaoID);
	isBinded = true;
}

void VertexArray::unbind()
{
	
}
