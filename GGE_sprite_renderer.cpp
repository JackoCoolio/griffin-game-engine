#include "stdafx.h"
#include "GGE_sprite_renderer.h"

#include <iostream>
#include "GGE_debug.h"
#include "GGE_renderer.h"

GGE::SpriteRenderer::SpriteRenderer(Shader &shader, Texture &texture) : Renderable()
{
	std::cout << "Sprite Renderer constructed." << std::endl;
	this->shader = shader;
	this->texture = texture;
	Renderer::getInstance().addRenderable(this);
}


GGE::SpriteRenderer::~SpriteRenderer()
{
	Renderer::getInstance().removeRenderable(this, 0);
}

void GGE::SpriteRenderer::initialize()
{
	std::cout << "Sprite Renderer initialized." << std::endl;

	
	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices[] =
	{
		 1.0f, 1.0f,  0.0f, // top right
		 1.0f, 0.0f,  0.0f, // bottom right
		 0.0f, 0.0f,  0.0f, // bottom left
		 0.0f, 1.0f,  0.0f // top left
	};
	float texCoords[] =
	{
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};
	GLushort indices[] =
	{
		0, 1, 3,
		1, 2, 3
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(texCoords), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(texCoords), texCoords);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertices));
	glEnableVertexAttribArray(1);

	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5, OFFSET(3));
	//glEnableVertexAttribArray(1);

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0); // Not necessary, but good practice.

	//////////////////////////////
	/*glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	
	float vertices[] =
	{
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, OFFSET(0));

	glEnableVertexAttribArray(0);

	glBindVertexArray(0);*/
}

void GGE::SpriteRenderer::render()
{

	/*glBegin(GL_TRIANGLES);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();*/

	glActiveTexture(GL_TEXTURE0);
	texture.bind();


	
	glUseProgram(shader.id);

	glUniform1i(glGetUniformLocation(shader.id, "tex"), 0);

	glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f); // Transform to pixel-space
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0)); // Camera
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

	glm::mat4 mvp = proj * view * model;

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "mvp"), 1, GL_FALSE, &mvp[0][0]);

	/*glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0);
	glBindVertexArray(0);*/

	glBindVertexArray(vao);

	GL_ASSERT(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0));
}

void GGE::SpriteRenderer::setScale(float x, float y)
{
	scale = { x, y };
}

GGE::Vector2 &GGE::SpriteRenderer::getScale()
{
	return scale;
}

void GGE::SpriteRenderer::setPosition(float x, float y)
{
	transform = { x, y };
}

GGE::Vector2 &GGE::SpriteRenderer::getPosition()
{
	return transform;
}

void GGE::SpriteRenderer::setRotationAngle(float angle)
{
	rotate = angle;
}

float GGE::SpriteRenderer::getRotationAngle()
{
	return rotate;
}