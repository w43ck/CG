#include "../inc/char_select_state.hpp"
#include "../inc/char_view_state.hpp"

CharacterSelectState::CharacterSelectState(Game * game) {
	setOutputStr(game);
}

CharacterSelectState::~CharacterSelectState() {
	
}


void CharacterSelectState::update(Game * game) {
	this->input = _getch();
	switch (this->input) {
		case 27: {
			this->st = '1';
			// setOutputStr(game);
			break;
		}
		case '1': {
			setCharSelected(game, 1);
			break;
		}
		case '2': {
			setCharSelected(game, 2);
			break;
		}
		case '3': {
			setCharSelected(game, 3);
			break;
		}
		case '4': {
			setCharSelected(game, 4);
			break;
		}
		case '5': {
			setCharSelected(game, 5);
			break;
		}
		default:
		break;
	}
}

void CharacterSelectState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void CharacterSelectState::endState() {
	
}

void CharacterSelectState::setOutputStr(Game * game) {
	this->output = "Нажмите Escape для выхода\nНажмите цифру, соответствующую персонажу, для выбора персонажа\n";
	for(int i = 0; i < game->characters.size(); ++i) {
		this->output += fmt::format("\n={}=: {} named {}\n", i + 1, game->characters[i]->name.data(), game->characters[i]->playerName.data());
	}
}

void CharacterSelectState::setCharSelected(Game * game, uint8_t n) {
	if(game->characters.size() >= n) {
		game->activeCharacter = game->characters[n - 1];
		this->output = fmt::format("Выбран персонаж {}, класс {}\nНажмите Escape для выхода\n", game->activeCharacter->playerName.data(),
																game->activeCharacter->name.data());
	} else {
		setOutputStr(game);
		this->output += "Нет такого персонажа в списке\n";
	}
}