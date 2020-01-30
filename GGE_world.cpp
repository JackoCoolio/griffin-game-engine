#include "stdafx.h"
#include "GGE_world.h"

GGE::World::World()
{
}


GGE::World::~World()
{
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
	return World();
}
