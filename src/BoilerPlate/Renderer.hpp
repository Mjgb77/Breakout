#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "shaderUtilities.hpp"

struct Renderer {
	//members
	GLuint VertexArrayObject; //VAO
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO
	GLuint ProgramID;



	GLushort indexes[3];
	GLuint indexBufferID;
	float vertexes[9] = { 0.5,0.5,0.0,  0.5,-0.5,0.0 , -0.5,0.5,0.0 };

	bool wireFrame;

	//functions 
	void InitVertex();
	void OnRender();
	Renderer();
	~Renderer();
	void SwitchView();



};







#endif // !RENDERER_H_INCLUDED
