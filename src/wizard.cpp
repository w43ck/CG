#include "../inc/wizard.hpp"

uint64_t Wizard::wizs = 0;

Wizard::Wizard(std::string_view playerName) : BaseCharacter() {
	this->name = "Wizard";
	++this->wizs;
	this->playerName = playerName;
}

Wizard::~Wizard() {
	
}

void Wizard::use() {
	
}

void Wizard::heal(uint64_t hl) {
	
}

void Wizard::takeDmg(uint64_t dmg) {
	
}
