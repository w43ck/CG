#pragma once

#include "state.hpp"

struct MenuState : public State {
	MenuState();
	virtual ~MenuState();
	
	void update() override;
	void render() override;
	void checkInput() override;
	void endState() override;
	
	
};