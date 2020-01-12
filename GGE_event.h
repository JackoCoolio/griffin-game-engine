#pragma once

#include "SDL_events.h"

namespace GGE
{

	class EventManager
	{
	public:
		EventManager();
		~EventManager();
		void registerEvent(SDL_Event &event);
	};

}
