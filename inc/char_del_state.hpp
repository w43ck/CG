#pragma once

#include "state.hpp"

struct CharacterDeleteState : public State {
	CharacterDeleteState(Game * game, State * stt, uint8_t n);
	virtual ~CharacterDeleteState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
	uint8_t n;
	State * stt;
};
