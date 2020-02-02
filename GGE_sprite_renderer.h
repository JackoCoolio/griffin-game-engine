#pragma once

#include <GL\glew.h>
#include "glm\glm.hpp"
#include "GGE_shader.h"
#include "GGE_texture.h"
#include "GGE_renderable.h"
#include "GGE_vector.h"

namespace GGE {

	class SpriteRenderer : public Renderable
	{
	public:
		SpriteRenderer(Shader &shader, Texture &texture);
		~SpriteRenderer();
		void render();
		void initialize();
		void setScale(float x, float y);
		const Vector2 &getScale();
		void setPosition(float x, float y);
		const Vector2 &getPosition();
		void setRotationAngle(float angle);
		float getRotationAngle();
		std::string getType() { return "SpriteRenderer"; }
	private:
		GLuint vao;
		Shader shader;
		Texture texture;

		Vector2 scale;
		Vector2 transform;
		float rotate;

	};

}
