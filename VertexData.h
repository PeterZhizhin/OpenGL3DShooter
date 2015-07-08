#pragma once

#include <vector>
#include <GL/glew.h>

class VertexData
{
public:
	static void bindDataToVBO(std::vector<VertexData> vertecies);
	static void bindPointers();
	static void enablePointers();
	VertexData();
	~VertexData();
	void print();
	void setVertex(GLfloat x);
	void setVertex(GLfloat x, GLfloat y);
	void setVertex(GLfloat x, GLfloat y, GLfloat z);
	void setVertex(GLfloat x, GLfloat y, GLfloat z, GLfloat w);	

	void setTexture(GLfloat u);
	void setTexture(GLfloat u, GLfloat v);
	void setTexture(GLfloat u, GLfloat v, GLfloat w);

	void setNormal(GLfloat x);
	void setNormal(GLfloat x, GLfloat y);
	void setNormal(GLfloat x, GLfloat y, GLfloat z);
private:
	//Max number of vCount + tCount + vCount	
	static constexpr int size = 4+3+3;
	std::vector<GLfloat> data;
	static constexpr GLsizei stride = size*sizeof(GLfloat);
	static constexpr int VERTEX_OFFSET = 0;
	static constexpr int VERTEX_SIZE = 4;
	static constexpr int TEXTURE_OFFSET = 4*sizeof(GLfloat);
	static constexpr int TEXTURE_SIZE = 3;
	static constexpr int NORMAL_OFFSET = (4+3)*sizeof(GLfloat);
	static constexpr int NORMAL_SIZE = 3;
};
