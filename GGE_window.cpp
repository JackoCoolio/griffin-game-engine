#include "stdafx.h"
#include "GGE_window.h"

#include <iostream>
#include <SOIL\SOIL.h>

GGE::Window::~Window()
{
	SDL_DestroyWindow(window);
}

bool GGE::Window::initialize(const char* title, int x, int y, int width, int height, Uint32 flags)
{
	window = SDL_CreateWindow(title, x, y, width, height, flags);
	return window;
}

SDL_Window *GGE::Window::getSDLWindow()
{
	return window;
}

int GGE::Window::getWindowWidth()
{
	int w;
	SDL_GetWindowSize(window, &w, nullptr);
	return w;
}

int GGE::Window::getWindowHeight()
{
	int h;
	SDL_GetWindowSize(window, &h, nullptr);
	return h;
}

void GGE::Window::getWindowBounds(int *width, int *height)
{
	SDL_GetWindowSize(window, width, height);
}

bool GGE::Window::setWindowIcon(const char* path, bool alpha)
{
	int width, height, channels;
	unsigned char* data = SOIL_load_image(path, &width, &height, &channels, alpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

	SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(data, width, height, channels * sizeof(unsigned char), 0, 0, 0, 0, 0);

	if (!data)
	{
		return 0;
	}

	SDL_SetWindowIcon(window, surface);
	
	SDL_FreeSurface(surface);

	return 1;
}