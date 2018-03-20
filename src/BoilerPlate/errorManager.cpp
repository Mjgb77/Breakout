#include "errorManager.hpp"
#include <Windows.h>

int ErrorManager::throwError(std::string file, std::string message , std::string line) {
	std::string errorMessage = "File: " + file +  " Line: " + line + " " + message + " OpenGL version 3.30, GLSL";
	LPCSTR display_message = errorMessage.c_str();

#ifdef _WIN32 
 int messageID = MessageBoxA( NULL, display_message, "", MB_ICONWARNING | MB_OK ); 

#elif defined _unix_ II defined APPLE
	std::cerr « complete_message; 

#endif 
	return messageID;

}