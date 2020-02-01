#include "stdafx.h"
#include "GGE_node.h"


GGE::Node::Node(Vector2 offset) : offset(offset) {}

GGE::Node::Node()
{
	offset = Vector2{ 0, 0 };
}

void GGE::Node::init()
{
	for (auto& beh : behaviors)
	{
		beh.init();
	}
	for (auto& node : nodes)
	{
		node.init();
	}
}

void GGE::Node::update(float delta)
{
	for (auto& beh : behaviors)
	{
		beh.update(delta);
	}
	for (auto& node : nodes)
	{
		node.update(delta);
	}
}

void GGE::Node::physicsUpdate()
{
	for (auto& beh : behaviors)
	{
		beh.physicsUpdate();
	}
	for (auto& node : nodes)
	{
		node.physicsUpdate();
	}
}

GGE::Vector2 GGE::Node::getOffset()
{
	return offset;
}
