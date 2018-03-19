#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "shaderUtilities.hpp"

struct Renderer {
	//members
	GLuint VertexArrayObject; //VAO      // opengl-tutorial.org
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO
	GLuint ProgramID;
	void Init(float vertexes[]);
	void onRender();

	//functions
	Renderer();
	~Renderer();




};







#endif // !RENDERER_H_INCLUDED
