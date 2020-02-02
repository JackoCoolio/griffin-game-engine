#pragma once

#include <string>

namespace GGE
{

	class Behavior
	{
	public:
		virtual void init() {}
		virtual void update(float delta) {}
		virtual void physicsUpdate() {}
		virtual std::string getType() const = 0;
	};

}
