#include "../inc/game.hpp"
#include "../inc/game_state.hpp"
#include "../inc/menu_state.hpp"

Game::Game() {
	this->isRunning = 1;
	this->activeCharacter = nullptr;
	this->characters.reserve(5);
	initStates();
}

Game::~Game() {
	while(!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
	
	// system("cls");
	system("pause");
}

void Game::initStates() {
	this->states.push(new MenuState());
}


void Game::update() {
	if(!this->states.empty()) {
		this->states.top()->update(this);
		
		while(!this->states.empty() && this->states.top()->st == '1') {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	} else {
		this->isRunning = 0;
	}
}

void Game::render() {
	if(!this->states.empty()) {
		this->states.top()->render();
	}
}
