#version 330 core
in vec3 t_texCoord;
in vec3 t_normal;

layout(location=0) out vec4 outColor;

void main()
{
	outColor = vec4(0,1,0,1);	
}
