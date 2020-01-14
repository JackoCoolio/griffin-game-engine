#include "stdafx.h"
#include "GGE_loop.h"

typedef std::chrono::high_resolution_clock Clock;

GGE::Loop::Loop(GGE::Game *game) : game(game)
{
	last = Clock::now();
}

void GGE::Loop::init()
{
	game->init();
}

void GGE::Loop::doTick()
{
	std::chrono::nanoseconds sec = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - last);
	last = Clock::now();
	game->update((double)sec.count() / 1000000);
}
