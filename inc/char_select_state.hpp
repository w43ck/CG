#pragma once

#include "state.hpp"

struct CharacterSelectState : public State {
	CharacterSelectState(Game * game);
	virtual ~CharacterSelectState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
	void setOutputStr(Game * game);
	void setCharSelected(Game * game, uint8_t n);
};
