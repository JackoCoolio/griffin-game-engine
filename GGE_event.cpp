#include "stdafx.h"
#include "GGE_event.h"

#include "GGE_input.h"


GGE::EventManager::EventManager()
{
	std::cout << "event manager instantiated" << std::endl;
}

GGE::EventManager &GGE::EventManager::getInstance()
{
	static EventManager eventManager;
	return eventManager;
}

void GGE::EventManager::registerEvent(SDL_Event &event)
{
	// Eventually pass event to input manager, ui manager, etc.
	std::cout << "Event: " << event.type << std::endl;

	if (event.type == SDL_KEYDOWN)
	{
		Input::update(event.key.keysym.sym, true);
	}
	else if (event.type == SDL_KEYUP)
	{
		Input::update(event.key.keysym.sym, false);
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		// TODO
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		// TODO
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		// TODO
	}
}
