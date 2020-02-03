#include "stdafx.h"
#include "GGE.h"

#include "GGE_input.h"
#include "GGE_game.h"
#include "GGE_loop.h"
#include "GGE_event.h"
#include "GGE_renderer.h"

#include <chrono>

int GGE::initialize(const char* title, const char* iconPath)
{
	std::cout << "Initializing SDL..." << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init threw error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	std::cout << "SDL initialized." << std::endl;

	std::cout << "Creating window..." << std::endl;
	
	if (!window.initialize(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL))
	{
		std::cout << "SDL_CreateWindow threw error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	std::cout << "Window created." << std::endl;

	std::cout << "Setting window icon..." << std::endl;
	if (window.setWindowIcon(iconPath, true))
	{
		std::cout << "Set window icon!" << std::endl;
	}
	else std::cout << "Unable to load icon!" << std::endl;

	std::cout << "Initializing game structure..." << std::endl;
	Game::getInstance();
	Loop::getInstance();
	EventManager::getInstance();
	Renderer::getInstance().initialize(window.getSDLWindow(), true);
	std::cout << "Game structure initialized." << std::endl;

	return 0;
}

void GGE::startLoop()
{
	SDL_Event event;

	Loop::getInstance().init();

	while (1)
	{

		std::chrono::time_point<std::chrono::high_resolution_clock> frameStart = std::chrono::high_resolution_clock::now();

		Input::cycleHistory();

		while (SDL_PollEvent(&event))
		{
			EventManager::getInstance().registerEvent(event);
			//std::cout << event.type << std::endl;
			
			if (event.type == SDL_QUIT)
				goto quit;
		}

		Renderer::getInstance().renderClear();

		Input::updateEdges();

		Loop::getInstance().doTick();

		Renderer::getInstance().render();

		frameCount++;
		time += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - frameStart).count();

		if (time > 1000000000)
		{
			std::cout << "FPS: " << frameCount << std::endl;
			time = frameCount = 0;
		}
	}

quit:
	shutdownEngine();
}

void GGE::shutdownEngine()
{
	SDL_Quit();
}