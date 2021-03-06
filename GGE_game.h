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
		World &getWorld() { return currentWorld; }
		void init();
		void update(float delta);
		void physicsUpdate();
	};

}
