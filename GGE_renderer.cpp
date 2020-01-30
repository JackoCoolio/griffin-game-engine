#include "stdafx.h"
#include "GGE_renderer.h"

GGE::Renderer::Renderer()
{
	std::cout << "renderer instantiated" << std::endl;
}

GGE::Renderer &GGE::Renderer::getInstance()
{
	static Renderer renderer;
	return renderer;
}

void GGE::Renderer::initialize(SDL_Window *window, bool enableVsync)
{
	this->window = window;

	context = SDL_GL_CreateContext(window);
	if (context == nullptr)
	{
		std::cout << "SDL_GLContext was not created!" << std::endl;
		SDL_Quit();
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "GLEW was not initialized!" << std::endl;
		SDL_Quit();
	}

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set background color to gray.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glm::mat4 projection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

	

	/*if (enableVsync)
		SDL_GL_SetSwapInterval(1);*/
	
}

void GGE::Renderer::renderClear()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
}

void GGE::Renderer::render()
{

	// Iterate through all Renderables
	SDL_GL_SwapWindow(window);
}
