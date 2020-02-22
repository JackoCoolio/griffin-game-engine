#pragma once

#include <string>

namespace GGE
{

	class Node;

	class Behavior
	{
	private:
		Node * node;
	public:
		Behavior(Node *node) : node(node) {}
		Node *getNode() { return this->node; }
		virtual void init() {}
		virtual void update(float delta) {}
		virtual void physicsUpdate() {}
		virtual std::string getType() const = 0;
	};

}
