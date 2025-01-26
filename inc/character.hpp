#pragma once

#include "incs.hpp"

struct BaseCharacter {
	BaseCharacter();
	virtual ~BaseCharacter();
	
	// virtual void baseAttack();
	virtual void use() = 0;
	virtual void heal(uint64_t hl) = 0;
	virtual void takeDmg(uint64_t dmg) = 0;
	
	uint64_t hp;
	uint64_t mp;
	
	uint32_t strength;
	uint32_t intelligence;
	uint32_t dexterity;
	
	std::string name;
	std::string playerName;
};