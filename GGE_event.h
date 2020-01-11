#pragma once

#include "SDL_events.h"

class GGE_EventManager
{
public:
	GGE_EventManager();
	~GGE_EventManager();
	void registerEvent(SDL_Event &event);
};

