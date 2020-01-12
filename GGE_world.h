#pragma once

#include <vector>
#include "GGE_node.h"

namespace GGE
{

	class World
	{
	private:
		std::vector<GGE::Node> nodes;
	public:
		World();
		~World();
		void init();
		void update(float delta);
		void physicsUpdate();
		static World loadFromJSON(const char* file);
	};

}
