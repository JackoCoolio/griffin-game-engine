#pragma once

namespace GGE
{

	class Script
	{
	public:
		virtual void init() {}
		virtual void update(float delta) {}
		virtual void physicsUpdate() {}
	};

}
