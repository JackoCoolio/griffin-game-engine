#pragma once

#include <iostream>
#include <string>

namespace GGE
{

	struct Vector2
	{
		float x, y;
		Vector2 operator+(const Vector2&) const;
		Vector2 operator-(const Vector2&) const;
		Vector2 operator*(const float) const;
	};

	struct Vector3
	{
		float x, y, z;
	};

	struct Vector4
	{
		float x, y, z, w;
	};

}
