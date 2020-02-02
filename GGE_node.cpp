#include "stdafx.h"
#include "GGE_node.h"

GGE::Node::Node(Vector2 offset) : offset(offset) {}

GGE::Behavior *GGE::Node::getBehavior(std::string type)
{
	return behaviors[type];
}

void GGE::Node::addBehavior(Behavior *beh)
{
	behaviors[beh->getType()] = beh;
}

void GGE::Node::init()
{
	for (auto &pair : behaviors)
	{
		pair.second->init();
	}
	for (auto& node : nodes)
	{
		node.init();
	}
}

void GGE::Node::update(float delta)
{
	for (auto &pair : behaviors)
	{
		pair.second->update(delta);
	}
	for (auto& node : nodes)
	{
		node.update(delta);
	}
}

void GGE::Node::physicsUpdate()
{
	for (auto &pair : behaviors)
	{
		pair.second->physicsUpdate();
	}
	for (auto& node : nodes)
	{
		node.physicsUpdate();
	}
}

GGE::Vector2 GGE::Node::getOffset() const
{
	return offset;
}
