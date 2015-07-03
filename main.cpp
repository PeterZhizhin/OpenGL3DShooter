#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

int init_resources(void) 
{

	return 1;
}

void onDisplay()
{

}

void free_resources() {

}

constexpr auto title = "Title!";

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(3,3);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow(title);

	GLenum glew_status = glewInit();
	if(glew_status!=GLEW_OK)
	{
		std::cerr << "Error: " << glewGetErrorString(glew_status) << std::endl;
		return EXIT_FAILURE;
	}

	if(init_resources())
	{
		glutDisplayFunc(onDisplay);
		glutMainLoop();
	}

	free_resources();

	return EXIT_SUCCESS;
}
