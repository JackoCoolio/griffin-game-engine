#include "stdafx.h"
#include "GGE_node.h"

#include <iostream>

GGE::Node::Node(Node *parent, Vector2 offset) : parent(parent), offset(offset) {}

GGE::Behavior *GGE::Node::getBehavior(std::string type)
{
	return behaviors[type];
}

void GGE::Node::addBehavior(Behavior *beh)
{
	std::cout << "Adding behavior \"" << beh->getType() << "\"\n";
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
	//std::cout << "Updating " << behaviors.size() << " behaviors." << std::endl;
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

void GGE::Node::setRotation(float rotation)
{
	this->rotation = rotation;
}

float GGE::Node::getRotation() const
{
	return rotation;
}

void GGE::Node::setOffset(Vector2 offset)
{
	this->offset = offset;
}

GGE::Vector2 GGE::Node::getOffset() const
{
	return offset;
}
