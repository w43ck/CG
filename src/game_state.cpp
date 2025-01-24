#include "../inc/game_state.hpp"

GameState::GameState() {
	fmt::print("Hello from GameState!\n");
}

GameState::~GameState() {
	
}

void GameState::update() {
	this->checkInput();
}

void GameState::render() {
	// system("cls");
	fmt::print("Введите 0 для выхода в меню\n");
}

void GameState::checkInput() {
	std::cin >> this->input;
	switch (this->input) {
		case '0': this->st = 0;
		break;
		default:
		break;
	}
}

void GameState::endState() {
	fmt::print("Ending GameState!\n");
}
