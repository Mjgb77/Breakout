#pragma once
#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include "shader_utilities.hpp"
#include "Engine\core\vertex.hpp"



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
		void init_vertex(std::vector<float> vertexes, std::vector <int> indexes);
		void on_render(std::vector <int> indexes);
		Renderer();
		~Renderer();
		void switch_view();



	};


#endif // !RENDERER_H_INCLUDED

