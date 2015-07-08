
#include <iostream>
#include <memory>
#include <thread>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "World.h"
#include "CheckGLErrors.h"

std::unique_ptr<World> world;
constexpr auto title = "Super game";
constexpr auto width = 640, height = 480;

bool create_update_thread();

bool init_resources(void) 
{
	std::cout << "Initializing" << std::endl;
	world = std::make_unique<World>(width,height);
	create_update_thread();
	return true;
}

bool create_update_thread() 
{
	std::thread updateThread(
	[]{
		auto currentTime = std::chrono::high_resolution_clock::now();
		decltype(currentTime) newTime;
		std::chrono::duration<float> dur;
		while(1){
			newTime = std::chrono::system_clock::now();
			dur = newTime - currentTime;
			(*world).update(dur.count());	
			currentTime = newTime;
		}
	});
	updateThread.detach();
	return true;
}

void onDisplay()
{
	(*world).draw();
	glutSwapBuffers();
	std::cout << "Calls finished" << std::endl;
}

void free_resources()
{
	world.release();
}

void reshape(int width, int height) 
{
	(*world).resize(width,height);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(3,3);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(width,height);
	glutCreateWindow(title);

	glewExperimental = GL_TRUE;
	GLenum glew_status = glewInit();
	CheckGLErrors::checkErrors("GLEW initialization");
	if(glew_status!=GLEW_OK)
	{
		std::cerr << "Error: " << glewGetErrorString(glew_status) << std::endl;
		return EXIT_FAILURE;
	}

	if(init_resources())
	{
		glutDisplayFunc(onDisplay);
		glutReshapeFunc(reshape);
		glutMainLoop();
	}
	else
		return EXIT_FAILURE;

	free_resources();

	return EXIT_SUCCESS;
}
