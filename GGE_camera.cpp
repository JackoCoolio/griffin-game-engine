#include "stdafx.h"
#include "GGE_camera.h"

GGE::Camera::Camera(Vector2 offset, Vector2 size, float rotation) : size(size), rotation(rotation) 
{
	this->offset = offset;
}

GGE::Vector2 GGE::Camera::getSize() const
{
	return size;
}

float GGE::Camera::getRotation() const
{
	return rotation;
}
