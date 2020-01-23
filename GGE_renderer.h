#pragma once

#include <SDL.h>
#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GL\GL.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

//Testing
#include "GGE_shader.h"
#include "GGE_texture.h"

namespace GGE
{

	class Renderer
	{
	private:
		Renderer();
		SDL_Window *window;
		SDL_GLContext context;

		Shader shader;
		Texture texture;
	public:
		Renderer & operator=(const Renderer&) = delete;
		Renderer(const Renderer&) = delete;
		static Renderer & getInstance();
		void initialize(SDL_Window *window, bool enableVsync);
		void renderClear();
		void render();
	};

}
