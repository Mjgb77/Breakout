#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include "../utilities/shader_utilities.hpp"
#include "vertex_object.hpp"


struct Renderer {
	//members
	GLuint VertexArrayObject; //VAO
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO
	GLuint mTextureBall;
	GLuint mTextureBlock;
	GLuint ProgramID;


	bool wireFrame;

	//functions 
	void init_vertex(float *, int *);
	void on_render(int *);
	Renderer();
	~Renderer();
	void switch_view();
};


#endif // !RENDERER_H_INCLUDED

