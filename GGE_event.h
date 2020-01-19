#pragma once

#include "SDL_events.h"
#include <iostream>

namespace GGE
{

	class EventManager
	{
	private:
		EventManager();
	public:
		static EventManager &getInstance();
		void registerEvent(SDL_Event &event);
	};

}
