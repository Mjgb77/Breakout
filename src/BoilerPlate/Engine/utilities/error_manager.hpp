#pragma once
#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include <gl\glew.h>
struct ErrorManager {


	int throw_error(std::string file, std::string message, std::string line) ;
};


#endif // !ERROR_MANAGER_H
