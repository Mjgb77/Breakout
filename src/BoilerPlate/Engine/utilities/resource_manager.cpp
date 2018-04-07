#include "resource_manager.hpp"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#include <iostream>

//Y esa clase el se la dio completa? l esta ?si el nos dio la funcion? la de load texture
//yy q eeso hace??? cargar la imagen de la bola.///

//pero q el hace por dentro? osea
//el donde la guarda se guarda en el gluint donde la cargues que
//como asi?k mmm dejame ver

TextureManager::TextureManager() {

}

GLuint TextureManager::load_texture(const char * texture_path) {
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	// Load the texture
	unsigned char *data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
		return -1;
	}
	stbi_image_free(data);

	return texture;
}