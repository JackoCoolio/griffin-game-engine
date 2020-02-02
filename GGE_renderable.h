#pragma once

#include "GGE_camera.h"

namespace GGE
{
	class Renderable
	{
	public:
		Renderable() = default;
		virtual void render(Camera &camera) = 0;
	};
}
