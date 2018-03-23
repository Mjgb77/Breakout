#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <GL/glew.h>



		class TextureManager {
			GLuint nTexture;


		public:
			GLuint load_texture(const char * texture_path);

		};

	





#endif // !TEXTURE_MANAGER_H

