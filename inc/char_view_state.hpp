#pragma once

#include "state.hpp"

struct CharViewState : public State {
	CharViewState();
	CharViewState(uint8_t type, State * stt);
	virtual ~CharViewState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
	uint8_t type;
};