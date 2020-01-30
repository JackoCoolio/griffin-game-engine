#include "stdafx.h"
#include "GGE_sprite_renderer.h"

#include <iostream>
#include "GGE_debug.h"

SpriteRenderer::SpriteRenderer(Shader &shader)
{
	std::cout << "Sprite Renderer constructed." << std::endl;
	this->shader = shader;
}


SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::initialize()
{
	std::cout << "Sprite Renderer initialized." << std::endl;

	
	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices[] =
	{
		 0.5f,  0.5f,  0.0f, // top right
		 0.5f, -0.5f,  0.0f, // bottom right
		-0.5f, -0.5f,  0.0f, // bottom left
		-0.5f,  0.5f,  0.0f // top left
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

void SpriteRenderer::draw(Texture &texture)
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

	/*glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0);
	glBindVertexArray(0);*/

	glBindVertexArray(vao);

	GL_ASSERT(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0));
}