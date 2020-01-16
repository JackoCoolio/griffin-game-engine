#pragma once

#include "SDL.h"
#include <iostream>

#include "GGE_event.h"
#include "GGE_game.h"
#include "GGE_loop.h"

namespace GGE
{

	namespace
	{
		SDL_Window *window;
		SDL_GLContext context;
		EventManager *eventManager;
		Game *game;
		Loop *gameLoop;
	}

	int initialize(const char* title, const char* iconPath);

	void startLoop();

	void shutdownEngine();
}
