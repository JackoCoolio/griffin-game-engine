#include "stdafx.h"
#include "GGE_input.h"
#include "nlohmann\json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

std::map<SDL_Keycode, std::string> GGE::Input::actions;
std::map<std::string, GGE::Input::ActionState> GGE::Input::states;


void GGE::Input::loadKeyConfig(std::string path)
{
	std::ifstream stream(path);
	json j;
	stream >> j;

	std::cout << "Size: " << j.size() << std::endl;

	for (auto it = j.begin(); it != j.end(); ++it)
	{
		for (auto &keycode : it.value())
		{
			std::string code = keycode.dump().substr(1, keycode.dump().length() - 2);
			SDL_Keycode num = std::stol(code);
			std::cout << num << std::endl;
			actions[num] = it.key();
		}
	}

	for (auto &p : actions)
	{
		std::cout << p.first << " : " << p.second << std::endl;
	}

}

void GGE::Input::update(SDL_Keycode code, bool active)
{

	//states[actions[code]].previous = states[actions[code]].active;

	states[actions[code]].active = active;

}

void GGE::Input::updateEdges()
{
	for (auto &state : states)
	{
		if (state.second.previous != state.second.active) // detect edge
		{
			if (state.second.active) // if it just became active
			{
				state.second.rising = true; // rising edge
			}
			else // if it just became inactive
			{
				state.second.falling = true; // falling edge
			}
		}
		else // no edge
		{
			state.second.rising = state.second.falling = false; // not rising or falling
		}
	}
}

void GGE::Input::cycleHistory()
{
	for (auto &state : states)
	{
		state.second.previous = state.second.active;
	}
}

bool GGE::Input::isKeyPressed(std::string key)
{
	return states[key].active;
}

bool GGE::Input::isKeyDown(std::string key)
{
	return states[key].rising;
}

bool GGE::Input::isKeyUp(std::string key)
{
	return states[key].falling;
}
