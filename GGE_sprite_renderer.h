#pragma once

#include <GL\glew.h>
#include "glm\glm.hpp"
#include "GGE_shader.h"
#include "GGE_texture.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();
	void draw(Texture &texture);
	void initialize();
private:
	GLuint vao;
	Shader shader;
};

