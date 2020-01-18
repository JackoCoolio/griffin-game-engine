#include "stdafx.h"
#include "GGE_loop.h"

typedef std::chrono::high_resolution_clock Clock;

GGE::Loop::Loop()
{
	last = Clock::now();
}

GGE::Loop &GGE::Loop::getInstance()
{
	static Loop loop;
	return loop;
}

void GGE::Loop::init()
{
	Game::getInstance().init();
}

void GGE::Loop::doTick()
{
	std::chrono::nanoseconds sec = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - last);
	last = Clock::now();
	Game::getInstance().update((float)sec.count() / 1000000);
}
