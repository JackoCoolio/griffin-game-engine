#include "stdafx.h"
#include "GGE_event.h"


GGE::EventManager::EventManager()
{

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
}
