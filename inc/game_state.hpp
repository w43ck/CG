#pragma once

#include "state.hpp"

struct GameState : public State {
	GameState();
	virtual ~GameState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
};