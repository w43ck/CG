#pragma once

#include "character.hpp"

struct State;

struct Game {
	Game();
	~Game();
	
	void update();
	void render();
	
	void initStates();
	
	bool isRunning;
	std::shared_ptr<BaseCharacter> activeCharacter;
	std::stack<State *> states;
	std::vector<std::shared_ptr<BaseCharacter>> characters;
};