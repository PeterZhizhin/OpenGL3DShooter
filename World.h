#pragma once

#include "BasicShader.h"
#include "Cube.h"

class World {

public:
	World(int width, int height);
	~World();
	void update(float deltaTime);
	void draw();	
	void resize(int width, int height);
private:
	BasicShader shader;
	Cube cube;
	int width,height;
	int currentFPS;
	float timeAccumulator;
	void calculateFPS(float deltaTime);
};
