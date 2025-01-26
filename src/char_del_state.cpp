#include "../inc/char_del_state.hpp"
#include "../inc/char_view_state.hpp"

CharacterDeleteState::CharacterDeleteState(Game * game, State * stt, uint8_t n) {
	this->n = n;
	this->stt = stt;
	this->output = fmt::format("=====ВЫБОР ПЕРСОНАЖА=====\n\nПерсонаж {} класса {} выбран\nНажмите Escape для выхода\nНажмите Enter для подтверждения выбора персонажа\n"
															"Нажмите '0' для удаления персонажа\n",
															game->characters[this->n - 1]->playerName.data(), game->characters[this->n - 1]->name.data());
}

CharacterDeleteState::~CharacterDeleteState() {
	
}


void CharacterDeleteState::update(Game * game) {
	this->input = _getch();
	switch (this->input) {
		case 27: {
			this->st = 1;
			break;
		}
		case 13: {
			if(!this->isOff) {
				if(game->characters.size() >= this->n) {
					game->activeCharacter = game->characters[this->n - 1];
					this->output = fmt::format("=====ВЫБОР ПЕРСОНАЖА=====\n\nВыбран персонаж {} класса {}\nНажмите Escape для выхода\n", game->activeCharacter->playerName.data(),
																			game->activeCharacter->name.data());
				} else {
					this->output += "Нет такого персонажа в списке\n";
				}
				this->isOff = 1;
				this->stt->st = 1;
			}
			break;
		}
		case '0': {
			if(!this->isOff) {
				if(game->characters.size() >= this->n) {
					this->output = fmt::format("=====ВЫБОР ПЕРСОНАЖА=====\n\nПерсонаж {} класса {} успешно удален\nНажмите Escape для выхода\n",
																			game->characters[this->n - 1]->playerName.data(), game->characters[this->n - 1]->name.data());
					game->characters.erase(game->characters.begin() + (this->n - 1));
				}
				this->isOff = 1;
				this->stt->st = 1;
			}
			break;
		}
		
		default:
		break;
	}
}

void CharacterDeleteState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void CharacterDeleteState::endState() {
	
}
