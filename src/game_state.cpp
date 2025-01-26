#include "../inc/game_state.hpp"
#include "../inc/world_map_state.hpp"

GameState::GameState() {
	setDefOutput();
}

GameState::~GameState() {
	
}

void GameState::update(Game * game) {
	this->input = _getch();
	if(!this->isOff) setDefOutput();
	switch (this->input) {
		case 27: {
			this->st = 1;
			break;
		}
		case '1': {
			game->states.push(new WorldMapState(game));
			break;
		}
		case '9': {
			this->output += fmt::format("Окно персонажа:\n{} named {}:\nHP:{}, MP:{}, Str:{}, Int:{}, Dex:{}\n", game->activeCharacter->name.data(),
																		game->activeCharacter->playerName.data(), game->activeCharacter->hp, game->activeCharacter->mp, game->activeCharacter->strength, game->activeCharacter->intelligence, game->activeCharacter->dexterity);
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

void GameState::setDefOutput() {
	this->output = "=====ИГРА=====\n\nНажмите Escape для выхода в меню\nНажмите 1 для выбора карты\nНажмите 9 для просмотра информации о персонаже\n\n";
}