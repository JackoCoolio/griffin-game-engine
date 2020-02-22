#include "stdafx.h"

#include "GGE_camera.h"

GGE::Camera::Camera(GGE::Node *node, Vector2 scale) : Behavior(node), scale(scale) {}

void GGE::Camera::setScale(Vector2 scale)
{
	this->scale = scale;
}

GGE::Vector2 GGE::Camera::getScale() const
{
	return scale;
}

std::string GGE::Camera::getType() const
{
	return "GGE::Camera";
}