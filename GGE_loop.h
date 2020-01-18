#pragma once

#include "GGE_game.h"
#include <chrono>

namespace GGE
{

	class Loop
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> last;
		Game *game;
		Loop();
	public:
		static Loop &getInstance();
		void init();
		void doTick();
	};

}
