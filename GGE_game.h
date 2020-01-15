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
	public:
		Game();
		~Game();
		void init();
		void update(float delta);
		void physicsUpdate();
	};

}
