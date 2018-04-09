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
	//ESTAS 3 cosas se sobre escriben cuando se llama init vertex!
	GLuint VertexArrayObject; //VAO
	GLuint VertexBufferObject; //VBO
	GLuint ElementBufferObject; //EBO
	// osea creo q no deberia  de ir en esta clase si no ball deberia de guardar esa info
	//o otra clase no se

	GLuint mTextureBall;
	GLuint mTextureBlock;
	GLuint ProgramID;


	//functions 
	void init_vertex(float [], int []);
	void on_render(int [], float [], int);
	Renderer();
	~Renderer();
};


#endif // !RENDERER_H_INCLUDED

