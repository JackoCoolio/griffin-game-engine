#pragma once

namespace GGE
{

	class Behavior
	{
	public:
		virtual void init() {}
		virtual void update(float delta) {}
		virtual void physicsUpdate() {}
	};

}
