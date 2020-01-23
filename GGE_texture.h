#pragma once

#include <GL\glew.h>

class Texture
{
public:
	GLuint id;
	GLuint width, height;
	GLuint internalFormat, imageFormat, wrapS, wrapT, filterMin, filterMax;

	Texture();
	void generate(GLuint width, GLuint height, unsigned char* data);
	void bind() const;
};

