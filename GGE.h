#pragma once

#include "SDL.h"
#include <iostream>

#include "GGE_event.h"
#include "GGE_game.h"
#include "GGE_node.h"


namespace GGE
{

	namespace
	{
		SDL_Window *window;
		SDL_Renderer *renderer;
		EventManager *eventManager;
	}

	int initialize(const char* title, const char* iconPath);

	void startLoop();

	void shutdownEngine();
}
