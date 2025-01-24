#pragma once

#include "game_state.hpp"
#include "menu_state.hpp"

struct Game {
	Game();
	~Game();
	
	void update();
	void render();
	
	void initStates();
	
	std::stack<State *> states;
	bool isRunning;
};