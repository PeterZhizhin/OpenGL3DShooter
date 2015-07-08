#version 330 core
#extension GL_ARB_explicit_uniform_location : require
layout(location = 0) in vec4 vertex;
layout(location = 1) in vec3 texCoord;
layout(location = 2) in vec3 normal;
layout(location = 3) uniform mat4 matrix;

out vec3 t_texCoord;
out vec3 t_normal;

void main()
{
	gl_Position = matrix*vertex;
	t_normal = normal;
	t_texCoord = texCoord;
}
