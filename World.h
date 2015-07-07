#ifndef WORLD_H
#define WORLD_H


class World {

public:
	World(int width, int height);
	~World();
	void update(float deltaTime);
	void draw();	
	void resize(int width, int height);
private:
	int width,height;
	int currentFPS;
	float timeAccumulator;
	void calculateFPS(float deltaTime);
};

#endif
