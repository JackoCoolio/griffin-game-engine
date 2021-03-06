#include "stdafx.h"
#include "GGE_sprite_renderer.h"

#include <iostream>
#include "GGE_debug.h"
#include "GGE_renderer.h"
#include "GGE_node.h"

#include <math.h>
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

GGE::SpriteRenderer::SpriteRenderer(Node *node, Shader &shader, Texture &texture) : Renderable(), Behavior(node)
{
	std::cout << "Sprite Renderer constructed." << std::endl;
	
	this->shader = shader;
	this->texture = texture;
	Renderer::getInstance().addRenderable(this);

	rotate = 0;

	scale = { 1, 1 };
	transform = { 0, 0 };
}

GGE::SpriteRenderer::~SpriteRenderer()
{
	Renderer::getInstance().removeRenderable(this, 0);
}

void GGE::SpriteRenderer::init()
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

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0); // Not necessary, but good practice.

}

void GGE::SpriteRenderer::render(Camera &camera)
{

	glActiveTexture(GL_TEXTURE0);
	texture.bind();


	
	glUseProgram(shader.id);

	glUniform1i(glGetUniformLocation(shader.id, "tex"), 0);

	glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f); // Transform to pixel-space
	glm::mat4 camTranslate = glm::translate(glm::mat4(1.0f), glm::vec3(320 - camera.getNode()->getOffset().x, 240 - camera.getNode()->getOffset().y, 0)); // Camera
	glm::mat4 camScale = glm::scale(glm::mat4(1.0f), glm::vec3(camera.getScale().x, camera.getScale().y, 1.0f));
	glm::mat4 camRotation = glm::toMat4(glm::quat(cos(camera.getNode()->getRotation() / 2), 0, 0, sin(camera.getNode()->getRotation() / 2)));

	glm::mat4 view = camTranslate * camRotation * camScale;
	//view *= glm::toMat4(glm::quat(cos(angle / 2), 0, 0, sin(angle / 2)));

	glm::mat4 translateMat = glm::translate(glm::mat4(1.0f), glm::vec3(transform.x, transform.y, 0));
	glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x * texture.getWidth(), scale.y * texture.getWidth(), 1.0f));
	glm::mat4 rotMat = glm::toMat4(glm::quat(
		cos(rotate / 2),
		0,
		0,
		sin(rotate / 2)
	));

	//glm::mat4 model = translateMat * rotMat * scaleMat;

	//glm::mat4 mvp = proj * view * model;

	shader.setMatrix4("translate", translateMat);
	shader.setMatrix4("scale", scaleMat);
	shader.setMatrix4("rotation", rotMat);
	shader.setMatrix4("view", view);
	shader.setMatrix4("projection", proj);

	//glUniformMatrix4fv(glGetUniformLocation(shader.id, "mvp"), 1, GL_FALSE, &mvp[0][0]);

	glBindVertexArray(vao);

	GL_ASSERT(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0));
}

void GGE::SpriteRenderer::setScale(float x, float y)
{
	scale = { x, y };
}

const GGE::Vector2 &GGE::SpriteRenderer::getScale()
{
	return scale;
}

void GGE::SpriteRenderer::setPosition(float x, float y)
{
	transform = { x, y };
}

const GGE::Vector2 &GGE::SpriteRenderer::getPosition()
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