#include "stdafx.h"
#include "GGE_event.h"


GGE::EventManager::EventManager()
{

}

GGE::EventManager::~EventManager()
{

}

void GGE::EventManager::registerEvent(SDL_Event &event)
{
	// Eventually pass event to input manager, ui manager, etc.
}
