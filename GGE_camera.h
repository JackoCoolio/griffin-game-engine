#pragma once

#include "GGE_node.h"
#include "GGE_vector.h"

namespace GGE
{

	class Camera : public Node
	{
	private:
		Vector2 size;
	public:
		Camera(Vector2 offset, Vector2 size);
		Vector2 getSize();
	};

}
