#pragma once

#include "SDL_keycode.h"
#include <map>
#include <string>

namespace GGE
{

	class Input
	{
	private:

		typedef struct ActionState
		{
			bool previous;
			bool active;
			bool rising;
			bool falling;
		} ActionState;
		
	public:
		static void loadKeyConfig(std::string path);
		static void update(SDL_Keycode code, bool active);
		static void updateEdges();
		static void cycleHistory();
		static bool isKeyPressed(std::string key);
		static bool isKeyDown(std::string key);
		static bool isKeyUp(std::string key);
	public:
		static std::map<SDL_Keycode, std::string> actions; // Two keycodes can share the same action.
		static std::map<std::string, ActionState> states; // 1-to-1 mapping between actions and ActionStates
	};

}
