#pragma once

#include <vector>

namespace GGE
{
	class Node
	{
	private:
		std::vector<Node> nodes;
	public:
		Node();
		~Node();
		void init();
		void update(float delta);
		void physicsUpdate();
	};

}
