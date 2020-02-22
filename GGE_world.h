#pragma once

#include <vector>
#include "GGE_node.h"

namespace GGE
{

	class World : public Node
	{
	private:
		std::vector<GGE::Node> nodes;
	public:
		World();
		~World();
		void addNode(Node node);
		void init();
		void update(float delta);
		void physicsUpdate();
		static World loadFromJSON(const char* file);
		Vector2 getOffset() const = delete;
		Vector2 setOffset(Vector2 offset) = delete;
	};

}
