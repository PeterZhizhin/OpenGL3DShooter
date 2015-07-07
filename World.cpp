#include "World.h"

#include <iostream>
#include <GL/glew.h>

World::World(int width, int height) 
{
	std::cout << "Initializing world" << std::endl;	
	this->width = width;
	this->height = height;
	currentFPS = 0;
	timeAccumulator = 0;

	glViewport(0,0,width,height);
	glClearColor(0.9f,0.9f,0.9f,1);
}

void World::resize(int width, int height) 
{
	std::cout << "Resizing " << width << " " << height << std::endl;
	this->width = width;
	this->height = height;
	glViewport(0,0,width,height);	
}

World::~World()
{
	std::cout << "Destroying world" << std::endl;	
}

void World::calculateFPS(float deltaTime) 
{
	++currentFPS;
	timeAccumulator+=deltaTime;
	if (timeAccumulator>=1) {
		std::cout << "FPS: " << currentFPS << std::endl;
		timeAccumulator = 0;
		currentFPS = 0;
	}	
}

void World::update(float deltaTime)
{
	calculateFPS(deltaTime);
}

void World::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
