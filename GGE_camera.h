#pragma once

#include "GGE_node.h"
#include "GGE_vector.h"

namespace GGE
{

	class Camera : public Node
	{
	private:
		Vector size;
	public:
		Camera(Vector offset, Vector size);
		Vector getSize();
	};

}
