#include "VertexArray.h"

#include <vector>
#include <iostream>
#include <GL/glew.h>

VertexArray::VertexArray(std::vector<VertexData> vertecies)
{
	std::cout << "Creating vertex array" << std::endl;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	std::cout << "Creating vertex data" << std::endl;

	VertexData::bindDataToVBO(vertecies);
	VertexData::bindPointers();	
	VertexData::enablePointers();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	verteciesCount = vertecies.size();

	isBinded = false;
	std::cout << "Vertex array created" << std::endl;
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

void VertexArray::assertIfNotBinded()
{
	if(!isBinded)
		std::cerr << "VertexArray is not binded. Forcing!" << std::endl;
}

void VertexArray::unbind()
{
	assertIfNotBinded();
	glBindVertexArray(0);
	isBinded=false;	
}

void VertexArray::render()
{
	std::cout << "Rendering VAO" << std::endl;
	glDrawArrays(GL_TRIANGLES, 0, verteciesCount);
}
