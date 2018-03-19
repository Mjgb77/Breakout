#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <GL/glew.h>


class TextureManager {
	GLuint Texture1;


public:
	GLuint LoadTexture(const char * texture_path);

};






#endif // !TEXTURE_MANAGER_H

