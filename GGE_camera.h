#pragma once

#include "GGE_behavior.h"
#include "GGE_vector.h"

namespace GGE
{

	class Camera : public Behavior
	{
	private:
		Vector2 scale;
	public:
		Camera(Node *node, Vector2 scale = { 1, 1 });
		void setScale(Vector2 scale);
		Vector2 getScale() const;
		std::string getType() const;
	};

}
