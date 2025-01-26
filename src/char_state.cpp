#include "../inc/char_state.hpp"
#include "../inc/char_view_state.hpp"

CharacterState::CharacterState() {
	this->output = "Нажмите Escape для выхода\nНажмите 1 для просмотра информации о Воине\nНажмите 2 для просмотра информации о Маге\n";
}

CharacterState::~CharacterState() {
	
}


void CharacterState::update(Game * game) {
	this->input = _getch();
	switch (this->input) {
		case 27: {
			this->st = '1';
			break;
		}
		case '1': {
			game->states.push(new CharViewState(1));
			this->st = '1';
			break;
		}
		case '2': {
			game->states.push(new CharViewState(2));
			this->st = '1';
			break;
		}
		default:
		break;
	}
}

void CharacterState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void CharacterState::endState() {
	
}