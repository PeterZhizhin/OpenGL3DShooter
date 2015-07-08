#include "Cube.h"

#include <vector>
#include <iostream>

const std::vector<VertexData> Cube::getVertecies()
{
	std::cout << "Creating vertecies" << std::endl;
	std::vector<VertexData> result;
	VertexData vertex;
	result.reserve(3);

	vertex.setVertex(-1.0f,-1.0f,0.0f);
	vertex.print();
	result.push_back(vertex);

	vertex.setVertex(1.0f, -1.0f, 0.0f);
	vertex.print();
	result.push_back(vertex);

	vertex.setVertex(0.0f,1.0f,0.0f);
	vertex.print();
	result.push_back(vertex);

	std::cout << "Cube vertecies created" << std::endl;

	return result;
}

Cube::Cube() : VertexArray(Cube::getVertecies())
{
}
