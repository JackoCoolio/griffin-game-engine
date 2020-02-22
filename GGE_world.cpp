#include "stdafx.h"
#include "GGE_world.h"

GGE::World::World()
{
	this->offset = { 0, 0 };
}


GGE::World::~World()
{
}

void GGE::World::addNode(Node node)
{
	nodes.push_back(node);
}

void GGE::World::init()
{
	for (auto& node : nodes)
	{
		node.init();
	}
}

void GGE::World::update(float delta)
{
	for (auto& node : nodes)
	{
		node.update(delta);
	}
}

void GGE::World::physicsUpdate()
{
	for (auto& node : nodes)
	{
		node.physicsUpdate();
	}
}

GGE::World GGE::World::loadFromJSON(const char* file)
{
	// TODO
	World wld;
	return wld;
}
