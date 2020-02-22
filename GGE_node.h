#pragma once

#include <vector>
#include <map>
#include "GGE_vector.h"
#include "GGE_behavior.h"

namespace GGE
{
	class Node
	{
	public:
		float rotation;
		Vector2 offset;
		std::map<std::string, Behavior*> behaviors;
		std::vector<Node> nodes;
		Node *parent;
	public:
		Node(Node *parent = nullptr, Vector2 offset = { 0, 0 });
		Behavior *getBehavior(std::string type);
		virtual void addBehavior(Behavior *beh);
		virtual void init();
		virtual void update(float delta);
		virtual void physicsUpdate();
		void setRotation(float rotation);
		float getRotation() const;
		void setOffset(Vector2 offset);
		Vector2 getOffset() const;
	};

}
