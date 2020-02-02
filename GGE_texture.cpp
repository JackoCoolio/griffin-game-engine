#include "stdafx.h"
#include "GGE_texture.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <SOIL\SOIL.h>
#include "SDL.h"

GGE::Texture::Texture() : width(0), height(0), internalFormat(GL_RGB), imageFormat(GL_RGB), wrapS(GL_CLAMP_TO_BORDER), wrapT(GL_CLAMP_TO_BORDER), filterMin(GL_NEAREST), filterMax(GL_NEAREST)
{
	std::cout << "Texture constructed." << std::endl;
}

void GGE::Texture::generate(GLuint width, GLuint height, unsigned char* data)
{
	std::cout << "Texture generated." << std::endl;
	this->width = width;
	this->height = height;

	glGenTextures(1, &this->id);

	glBindTexture(GL_TEXTURE_2D, this->id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMax);
	glTexImage2D(GL_TEXTURE_2D, 0, this->internalFormat, width, height, 0, this->imageFormat, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GGE::Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, this->id);
}

void GGE::Texture::load(const GLchar *file, GLboolean alpha)
{
	std::cout << "Texture loaded." << std::endl;
	std::cout << "Loading image: "
		<< file
		<< std::endl;
	if (this->alpha = alpha)
	{
		internalFormat = GL_RGBA;
		imageFormat = GL_RGBA;
	}

	int width, height, nrChannels;
	unsigned char *image = SOIL_load_image(file, &width, &height, &nrChannels, imageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

	if (!image)
	{
		std::cout << "[ERROR] Failed to load texture at \"" << file << "\"!" << std::endl;
		std::cin.get();
		SDL_Quit();
	}
	else
	{
		std::cout << "Loaded image (" << file << ")"
			<< "\nWidth: " << width
			<< "\nHeight: " << height
			<< "\nChannels: " << nrChannels
			<< std::endl;
	}

	generate(width, height, image);

	SOIL_free_image_data(image);
}

GLuint GGE::Texture::getWidth() const
{
	return width;
}

GLuint GGE::Texture::getHeight() const
{
	return height;
}

bool GGE::Texture::hasAlphaChannel() const
{
	return alpha;
}
