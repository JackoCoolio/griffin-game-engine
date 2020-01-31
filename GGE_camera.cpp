#include "stdafx.h"
#include "GGE_camera.h"

GGE::Camera::Camera(Vector2 offset, Vector2 size) 
{
	this->offset = offset;
	this->size = size;
}

GGE::Vector2 GGE::Camera::getSize()
{
	return size;
}
