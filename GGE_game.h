#pragma once

#include <vector>
#include "GGE_world.h"

namespace GGE
{

	class Game
	{
	private:
		std::vector<World> worlds;
		World currentWorld;
		Game();
	public:
		static Game &getInstance();
		void init();
		void update(float delta);
		void physicsUpdate();
	};

}
