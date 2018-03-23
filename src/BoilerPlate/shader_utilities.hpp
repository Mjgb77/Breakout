#pragma once
#ifndef SHADER_UTILITIES_H
#define SHADER_UTILITIES_H
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "error_manager.hpp"

class ShaderUtilities {

public:
	static GLuint load_shaders(const char * vertex_file_path, const char * fragment_file_path);


};









#endif // !SHADER_UTILITIES_H
