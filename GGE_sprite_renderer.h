#pragma once

#include <GL\glew.h>
#include "glm\glm.hpp"
#include "GGE_shader.h"
#include "GGE_texture.h"
#include "GGE_renderable.h"

namespace GGE {

	class SpriteRenderer : public Renderable
	{
	public:
		SpriteRenderer(Shader &shader, Texture &texture);
		~SpriteRenderer();
		void render();
		void initialize();
	private:
		GLuint vao;
		Shader shader;
		Texture texture;
	};

}
