#include "../inc/warrior.hpp"

uint64_t Warrior::wars = 0;

Warrior::Warrior(std::string_view playerName) : BaseCharacter() {
	this->name = "Warrior";
	++this->wars;
	this->playerName = playerName;
}

Warrior::~Warrior() {
	
}

void Warrior::use() {
	
}

void Warrior::heal(uint64_t hl) {
	
}

void Warrior::takeDmg(uint64_t dmg) {
	
}
