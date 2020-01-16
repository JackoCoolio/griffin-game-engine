#include "stdafx.h"
#include "GGE_game.h"

GGE::Game::Game()
{
}

GGE::Game &GGE::Game::getInstance()
{
	static Game game;
	return game;
}

void GGE::Game::init()
{
	currentWorld.init();
}

void GGE::Game::update(float delta)
{
	currentWorld.update(delta);
}

void GGE::Game::physicsUpdate()
{
	currentWorld.physicsUpdate();
}
