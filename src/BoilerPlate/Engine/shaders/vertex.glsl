#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;


void main() {
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
	ourColor = aColor;
	TexCoord = aTexCoord;
}