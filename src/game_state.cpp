#include "../inc/game_state.hpp"

GameState::GameState() {
	this->output = "Нажмите Escape для выхода в меню\nНажмите 9 для просмотра информации о персонаже\n";
}

GameState::~GameState() {
	
}

void GameState::update(Game * game) {
	this->input = _getch();
	switch (this->input) {
		case 27: {
			this->st = '1';
			break;
		}
		case '9': {
			this->output = fmt::format("{} named {}:\nHP:{}, MP:{}, Str:{}, Int:{}, Dex:{}\n", game->activeCharacter->name.data(), game->activeCharacter->playerName.data(),
																	game->activeCharacter->hp, game->activeCharacter->mp, game->activeCharacter->strength, game->activeCharacter->intelligence, game->activeCharacter->dexterity);
		}
		default:
		break;
	}
}

void GameState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void GameState::endState() {
	
}
