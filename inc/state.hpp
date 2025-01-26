#pragma once

#include "incs.hpp"
#include "game.hpp"

struct Game;

struct State {
	State();
	virtual ~State() = 0;
	
	virtual void update(Game * game) = 0;
	virtual void render() = 0;
	
	virtual void endState() = 0;
	
	char input;
	int st;
	std::string output;
};