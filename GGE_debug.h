#pragma once

#ifdef _DEBUG
#include "GL\glew.h"
#include <gl\GLU.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GL_ASSERT(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
	if (GLenum error = glGetError())
	{
		std::cout << "[ERROR] An OpenGL error (" << glewGetErrorString(error) << ") was caused by\n"
			<< function
			<< " in " << file << ":" << line 
			<< std::endl;
		return false;
	}
	return true;
}

#else

#define GLCall(x) x

#endif
