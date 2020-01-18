#include "stdafx.h"
#include "GGE.h"

int GGE::initialize(const char* title, const char* iconPath)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init threw error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	window = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow threw error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Surface *bmp = SDL_LoadBMP(iconPath);
	if (bmp != nullptr)
	{
		SDL_SetWindowIcon(window, bmp);
		SDL_FreeSurface(bmp);
	}
	else std::cout << "Unable to load icon!" << std::endl;

	context = SDL_GL_CreateContext(window);
	if (context == nullptr)
	{
		std::cout << "SDL_GLContext was not created!" << std::endl;
		SDL_Quit();
		return 1;
	}

	Game::getInstance();
	Loop::getInstance();
	EventManager::getInstance();

	return 0;
}

void GGE::startLoop()
{
	SDL_Event event;

	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			EventManager::getInstance().registerEvent(event);
			std::cout << event.type << std::endl;
			
			if (event.type == SDL_QUIT)
				goto quit;
		}

		Loop::getInstance().doTick();

	}

quit:
	shutdownEngine();
}

void GGE::shutdownEngine()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}