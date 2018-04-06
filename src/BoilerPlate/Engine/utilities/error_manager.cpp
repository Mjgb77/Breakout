#include "error_manager.hpp"
#include <Windows.h>

int ErrorManager::throw_error(std::string pFile, std::string pMessage , std::string pLine) {
	std::string errorMessage = "File: " + pFile + " Line: " + pLine + " " + pMessage + " OpenGL version 3.30, GLSL";
	LPCSTR display_message = errorMessage.c_str();

#ifdef _WIN32 
 int messageID = MessageBoxA( NULL, display_message, "", MB_ICONWARNING | MB_OK ); 

#elif defined _unix_ II defined APPLE
	std::cerr « complete_message; 

#endif 
	return messageID;

}