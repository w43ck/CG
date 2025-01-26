#include "../inc/character.hpp"

BaseCharacter::BaseCharacter() {
	this->hp = 100;
	this->mp = 100;
	this->strength = 10;
	this->intelligence = 10;
	this->dexterity = 10;
}

BaseCharacter::~BaseCharacter() {
	
}