#include "stdafx.h"
#include "GGE.h"

int GGE::initialize(const char* title, const char* iconPath)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init threw error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer threw error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	eventManager = new EventManager();

	return 0;
}

void GGE::startLoop()
{
	SDL_Event event;

	while (1)
	{
		while (SDL_PollEvent(&event))
		{

			eventManager->registerEvent(event);

			if (event.type == SDL_QUIT)
				goto quit;
		}
	}

quit:
	shutdownEngine();
}

void GGE::shutdownEngine()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}