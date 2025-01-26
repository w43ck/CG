#include "../inc/menu_state.hpp"
#include "../inc/game_state.hpp"
#include "../inc/char_state.hpp"
#include "../inc/char_select_state.hpp"

MenuState::MenuState() {
	this->output = "=====МЕНЮ=====\n\nНажмите Escape для выхода\nНажмите 1 для начала игры\nНажмите 2 для создания персонажа\nНажмите 3 для выбора персонажа\n";
}

MenuState::~MenuState() {
	
}

void MenuState::update(Game * game) {
	this->input = _getch();
	this->output = "=====МЕНЮ=====\n\nНажмите Escape для выхода\nНажмите 1 для начала игры\nНажмите 2 для создания персонажа\nНажмите 3 для выбора персонажа\n";
	switch (this->input) {
		case 27: {
			this->st = 1;
			break;
		}
		case '1': {
			if(game->activeCharacter != nullptr) {
				game->states.push(new GameState());
			} else {
				this->output += "\nНе выбран персонаж\n";
			}
			break;
		}
		case '2': {
			game->states.push(new CharacterState());
			break;
		}
		case '3': {
			game->states.push(new CharacterSelectState(game));
			break;
		}
		default:
		break;
	}
}

void MenuState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void MenuState::endState() {
	
}