#include "BasicShader.h"
#include "ShaderLoader.h"

BasicShader::BasicShader() : 
	AbstractShader(
		ShaderLoader::loadProgram("resources/shaders/basic.vert","resources/shaders/basic.frag")
   	  	      )
{
}

std::string BasicShader::getName()
{
	return "BasicShader";
}
