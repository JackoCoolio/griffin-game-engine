#include "stdafx.h"
#include "GGE_camera.h"

GGE::Camera::Camera(Vector offset, Vector size) 
{
	this->offset = offset;
	this->size = size;
}

GGE::Vector GGE::Camera::getSize()
{
	return size;
}
