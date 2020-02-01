#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GL\GL.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

//Testing
#include "GGE_shader.h"
#include "GGE_texture.h"
#include "GGE_sprite_renderer.h"

namespace GGE
{

	class Renderer
	{
	private:
		Renderer();
		SDL_Window *window;
		SDL_GLContext context;

		SpriteRenderer *sprenderer;
		Shader shader;
		Texture texture;

		std::vector<Renderable*> renderables;

		glm::mat4 projection;
	public:
		Renderer & operator=(const Renderer&) = delete;
		Renderer(const Renderer&) = delete;
		static Renderer & getInstance();
		void addRenderable(Renderable *renderable);
		void removeRenderable(Renderable *renderable, bool del = false);
		void initialize(SDL_Window *window, bool enableVsync);
		void renderClear();
		void render();
	};

}
