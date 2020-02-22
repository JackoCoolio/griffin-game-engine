#pragma once

#include <GL\glew.h>
#include "glm\glm.hpp"
#include "GGE_shader.h"
#include "GGE_texture.h"
#include "GGE_renderable.h"
#include "GGE_vector.h"
#include "GGE_behavior.h"

namespace GGE {

	class SpriteRenderer : public Renderable, public Behavior
	{
	public:
		SpriteRenderer(Node *node, Shader &shader, Texture &texture);
		~SpriteRenderer();
		void render(Camera &camera);
		void init();
		void setScale(float x, float y);
		const Vector2 &getScale();
		void setPosition(float x, float y);
		const Vector2 &getPosition();
		void setRotationAngle(float angle);
		float getRotationAngle();
		std::string getType() const { return "SpriteRenderer"; }
	private:
		GLuint vao;
		Shader shader;
		Texture texture;

		Vector2 scale;
		Vector2 transform;
		float rotate;

	};

}
