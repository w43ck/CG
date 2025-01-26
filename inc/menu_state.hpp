#pragma once

#include "state.hpp"

struct MenuState : public State {
	MenuState();
	virtual ~MenuState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
	
};