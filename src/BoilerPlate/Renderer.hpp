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
	GLuint mTextureBall;
	GLuint mTextureBlock;
	GLuint ProgramID;



	GLuint indexBufferID;
	float mTemporalVertexes[82] = 
	{ // positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right 0
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right 1
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f,    // top left  3
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right 1
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left 2
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left  3
	};

	bool wireFrame;

	//functions 
	void init_vertex();
	void on_render();
	Renderer();
	~Renderer();
	void switch_view();



};







#endif // !RENDERER_H_INCLUDED
