#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GL\GL.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GGE_renderable.h"

namespace GGE
{
	class Renderer
	{
	private:
		Renderer();

		SDL_Window *window;
		SDL_GLContext context;

		std::vector<Renderable*> renderables;

		Camera *camera;
	public:
		Renderer & operator=(const Renderer&) = delete;
		Renderer(const Renderer&) = delete;

		static Renderer & getInstance();

		void setCamera(Camera *camera);

		void addRenderable(Renderable *renderable);
		void removeRenderable(Renderable *renderable, bool del = false);
		void initialize(SDL_Window *window, bool enableVsync);
		void renderClear();
		void render();
	};
}
