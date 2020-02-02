#pragma once

#include "SDL.h"
#include "GGE_window.h"

namespace GGE
{

	namespace
	{
		Window window;
	}

	int initialize(const char* title, const char* iconPath);

	void startLoop();

	void shutdownEngine();
}
