#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include "../utilities/shader_utilities.hpp"
#include "vertex_object.hpp"


struct renderer {
	//members
	GLuint VertexArrayObject; //VAO
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO

	GLuint mTextureBall;
	GLuint mTextureBlock;
	GLuint ProgramID;


	//functions 
	void init(float [], int []);
	void render(int [], float [], int, float);
	renderer();
	~renderer();
};


#endif // !RENDERER_H_INCLUDED

