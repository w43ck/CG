#pragma once

#include "state.hpp"

struct CharacterState : public State {
	CharacterState();
	virtual ~CharacterState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
	
};