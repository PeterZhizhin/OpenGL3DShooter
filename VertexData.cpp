#include "VertexData.h"
#include "AbstractShader.h"

#include <iostream>
#include <vector>

void VertexData::bindDataToVBO(std::vector<VertexData> vertecies)
{
	std::vector<GLfloat> allVertecies;
	//All vertecies have same length
	std::cout << "Allocating memory with " << vertecies.size()*VertexData::size << " float values" << std::endl;
	allVertecies.reserve(vertecies.size()*VertexData::size);
	for (auto vertex : vertecies)
	//Merge all vertecies into one array
		allVertecies.insert(allVertecies.end(), vertex.data.begin(), vertex.data.end());

	glBufferData(GL_ARRAY_BUFFER, allVertecies.size()*sizeof(GLfloat), &allVertecies[0], GL_STATIC_DRAW);
}

void VertexData::bindPointers()
{
	glVertexAttribPointer(AbstractShader::VERTEX_ATTRIB_LOCATION, VERTEX_SIZE, GL_FLOAT, GL_FALSE, stride, (GLvoid*)VERTEX_OFFSET);
	glVertexAttribPointer(AbstractShader::TEXCOORD_ATTRIB_LOCATION, TEXTURE_SIZE, GL_FLOAT, GL_FALSE, stride, (GLvoid*)TEXTURE_OFFSET);
	glVertexAttribPointer(AbstractShader::NORMAL_ATTRIB_LOCATION, NORMAL_SIZE, GL_FLOAT, GL_FALSE, stride, (GLvoid*)NORMAL_OFFSET);
}

void VertexData::enablePointers()
{
	glEnableVertexAttribArray(AbstractShader::VERTEX_ATTRIB_LOCATION);
	glEnableVertexAttribArray(AbstractShader::TEXCOORD_ATTRIB_LOCATION);
	glEnableVertexAttribArray(AbstractShader::NORMAL_ATTRIB_LOCATION);
}

VertexData::VertexData()
{
	data.reserve(size);	
}

void VertexData::setVertex(GLfloat x)
{
	setVertex(x,0.0f,0.0f,1.0f);
}

void VertexData::setVertex(GLfloat x, GLfloat y)
{
	setVertex(x,y,0.0f,1.0f);
}

void VertexData::setVertex(GLfloat x, GLfloat y, GLfloat z)
{
	setVertex(x,y,z,1.0);
}

void VertexData::setVertex(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	data[0]=x;
	data[1]=y;
	data[2]=z;
	data[3]=w;
}

void VertexData::setTexture(GLfloat u)
{
	setTexture(u,0.0f,0.0f);
}

void VertexData::setTexture(GLfloat u, GLfloat v)
{
	setTexture(u,v,0.0f);
}

void VertexData::setTexture(GLfloat u, GLfloat v, GLfloat w)
{
	data[4]=u;
	data[5]=v;
	data[6]=w;
}

void VertexData::setNormal(GLfloat x)
{
	setNormal(x,0.0f,0.0f);
}

void VertexData::setNormal(GLfloat x, GLfloat y)
{
	setNormal(x,y,0.0f);
}

void VertexData::setNormal(GLfloat x, GLfloat y, GLfloat z)
{
	data[7]=x;
	data[8]=y;
	data[9]=z;
}
