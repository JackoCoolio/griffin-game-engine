#pragma once
namespace GGE
{
	class Renderable
	{
	public:
		Renderable() = default;
		virtual void render() = 0;
	};
}
