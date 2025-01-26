#pragma once

#include "state.hpp"

struct WorldMapState : public State {
	WorldMapState(Game * game);
	virtual ~WorldMapState();
	
	void update(Game * game) override;
	void render() override;
	void endState() override;
	
};