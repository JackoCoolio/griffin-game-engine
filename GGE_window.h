#pragma once
#include "SDL.h"

namespace GGE
{
	class Window
	{
	private:
		SDL_Window *window;
	public:
		Window() = default;
		~Window();
		bool initialize(const char* title, int x, int y, int width, int height, Uint32 flags = 0);
		SDL_Window *getSDLWindow();
		int getWindowWidth();
		int getWindowHeight();
		void getWindowBounds(int *width, int *height);
		bool setWindowIcon(const char* path, bool alpha);
	};
}
