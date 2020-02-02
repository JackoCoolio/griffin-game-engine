#pragma once

#include "GGE_node.h"
#include "GGE_vector.h"

namespace GGE
{

	class Camera : public Node
	{
	private:
		Vector2 size;
		float rotation;
	public:
		Camera(Vector2 offset = { 0, 0 }, Vector2 size = { 1, 1 }, float rotation = 0.0f);
		Vector2 getSize() const;
		float getRotation() const;
	};

}
