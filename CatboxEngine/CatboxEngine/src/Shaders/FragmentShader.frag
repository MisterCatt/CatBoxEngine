#version 440 core

out vec4 FragColor;

in vec4 vertexColor; // from vertex shader

void main()
{
	FragColor = vertexColor;
}