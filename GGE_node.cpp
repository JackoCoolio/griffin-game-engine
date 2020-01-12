#include "stdafx.h"
#include "GGE_node.h"


Node::Node()
{
}


Node::~Node()
{
}

void Node::init()
{
	for (auto& node : nodes)
	{
		node.init();
	}
}

void Node::update(float delta)
{
	for (auto& node : nodes)
	{
		node.update(delta);
	}
}

void Node::physicsUpdate()
{
	for (auto& node : nodes)
	{
		node.physicsUpdate();
	}
}
