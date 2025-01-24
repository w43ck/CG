#pragma once

#include "state.hpp"

struct GameState : public State {
	GameState();
	virtual ~GameState();
	
	void update() override;
	void render() override;
	void checkInput() override;
	void endState() override;
	
};