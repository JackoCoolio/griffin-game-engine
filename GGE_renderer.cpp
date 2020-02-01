#include "stdafx.h"
#include "GGE_renderer.h"

#include <algorithm>



GGE::Renderer::Renderer()
{
	std::cout << "Renderer constructed." << std::endl;
}

GGE::Renderer &GGE::Renderer::getInstance()
{
	static Renderer renderer;
	return renderer;
}

void GGE::Renderer::addRenderable(Renderable *renderable)
{
	renderables.push_back(renderable);
}

void GGE::Renderer::removeRenderable(Renderable *renderable, bool del)
{
	std::remove(renderables.begin(), renderables.end(), renderable);
	if (del)
		delete renderable;
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
	std::cout << "GLContext created." << std::endl;
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "GLEW was not initialized!" << std::endl;
		SDL_Quit();
	}
	std::cout << "GLEW initialized." << std::endl;

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND); // Enable transparency.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // This prevents the texture from looking like garbage.

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set background color to gray.

	texture.load("assets/test/bbbt.png", true);

	shader.compile("assets/test/sprite.vert", "assets/test/sprite.frag");

	sprenderer = new SpriteRenderer(shader, texture);
	sprenderer->initialize();

	renderables.push_back(sprenderer);
}

void GGE::Renderer::renderClear()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
}

void GGE::Renderer::render()
{
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glViewport(0, 0, 640, 480);
	//std::cout << "Texture: " << texture.id << " Shader: " << shader.id << std::endl;
	//sprenderer->draw(texture);

	for (auto &r : renderables)
	{
		r->render();
	}

	// Iterate through all Renderables
	SDL_GL_SwapWindow(window);
}
