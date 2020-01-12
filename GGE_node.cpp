#include "stdafx.h"
#include "GGE_node.h"


GGE::Node::Node()
{
}


GGE::Node::~Node()
{
}

void GGE::Node::init()
{
	for (auto& node : nodes)
	{
		node.init();
	}
}

void GGE::Node::update(float delta)
{
	for (auto& node : nodes)
	{
		node.update(delta);
	}
}

void GGE::Node::physicsUpdate()
{
	for (auto& node : nodes)
	{
		node.physicsUpdate();
	}
}
