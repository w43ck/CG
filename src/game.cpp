#include "../inc/game.hpp"

Game::Game() {
	this->isRunning = 1;
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
		this->states.top()->update();
		
		if(this->states.top()->st == 0) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		} else if(this->states.top()->st == 1) {
			this->states.push(new GameState);
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
