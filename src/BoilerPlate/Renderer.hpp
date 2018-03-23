#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "shader_utilities.hpp"


struct Renderer {
	//members
	GLuint VertexArrayObject; //VAO
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO
	GLuint ProgramID;

	GLuint indexBufferID;
	float vertexes[9] = { 0.5,0.5,0.0,  0.5,-0.5,0.0 , -0.5,0.5,0.0 };

	bool wireFrame;

	//functions 
	void init_vertex();
	void on_render();
	Renderer();
	~Renderer();
	void switch_view();



};







#endif // !RENDERER_H_INCLUDED
