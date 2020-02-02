#pragma once

#include <vector>
#include <map>
#include "GGE_vector.h"
#include "GGE_behavior.h"

namespace GGE
{
	class Node
	{
	protected:
		Vector2 offset;
		std::map<std::string, Behavior*> behaviors;
		std::vector<Node> nodes;
	public:
		Node(Vector2 offset);
		Node();
		Behavior *getBehavior(std::string type);
		void addBehavior(Behavior *beh);
		void init();
		void update(float delta);
		void physicsUpdate();
		Vector2 getOffset();
	};

}
