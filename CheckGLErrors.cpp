#include "CheckGLErrors.h"

#include <iostream>
#include <string>
#include <GL/glew.h>

const void CheckGLErrors::checkErrors(std::string tag)
{
GLenum err (glGetError());
//bool wasError=false;
 
        while(err!=GL_NO_ERROR) {
//		wasError = true;
		std::string error;
 
                switch(err) {
                        case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
                        case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
                        case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
                        case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
                        case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
                }
 
		std::cerr << "GL_" << error <<" - "<< tag << std::endl;
                err=glGetError();
        }
//	if(wasError)
//		exit(EXIT_FAILURE);
}
