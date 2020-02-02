#pragma once

#include <GL\glew.h>

namespace GGE {
	class Texture
	{
	public:
		Texture();
		void bind();
		void load(const GLchar *file, GLboolean alpha);
		GLuint getWidth() const;
		GLuint getHeight() const;
		bool hasAlphaChannel() const;
	private:
		GLuint id;
		GLuint width, height;
		bool alpha;
		GLuint internalFormat, imageFormat, wrapS, wrapT, filterMin, filterMax;
		void generate(GLuint width, GLuint height, unsigned char* data);
	};
}
