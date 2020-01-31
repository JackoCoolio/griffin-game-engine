#pragma once

#include <vector>
#include "GGE_vector.h"
#include "GGE_script.h"

namespace GGE
{
	class Node
	{
	protected:
		Vector2 offset;
		std::vector<Script> scripts;
		std::vector<Node> nodes;
	public:
		Node(Vector2 offset);
		Node();
		void init();
		void update(float delta);
		void physicsUpdate();
		Vector2 getOffset();
	};

}
