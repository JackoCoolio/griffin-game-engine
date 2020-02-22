#include "stdafx.h"
#include "GGE_vector.h"

GGE::Vector2 GGE::Vector2::operator+(const GGE::Vector2 &vec) const
{
	Vector2 res{ this->x + vec.x, this->y + vec.y };
	return res;
}

GGE::Vector2 GGE::Vector2::operator-(const GGE::Vector2 &vec) const
{
	Vector2 res{ this->x - vec.x, this->y - vec.y };
	return res;
}

GGE::Vector2 GGE::Vector2::operator*(const float multiplier) const
{
	Vector2 res{ this->x * multiplier, this->y * multiplier };
	return res;
}