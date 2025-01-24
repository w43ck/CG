#include "../inc/menu_state.hpp"

MenuState::MenuState() {
	fmt::print("Hello from MenuState!\n");
}

MenuState::~MenuState() {
	
}

void MenuState::update() {
	this->checkInput();
}

void MenuState::render() {
	// system("cls");
	fmt::print("Введите 0 для выхода\nВведите 1 для начала игры\n");
}

void MenuState::checkInput() {
	std::cin >> this->input;
	switch (this->input) {
		case '0': { this->st = 0;
			break;
		}
		case '1': { this->st = 1;
			break;
		}
		default:
		break;
	}
}

void MenuState::endState() {
	fmt::print("Ending MenuState!\n");
}