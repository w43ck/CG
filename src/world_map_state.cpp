#include "../inc/world_map_state.hpp"

WorldMapState::WorldMapState(Game * game) {
	this->output = fmt::format("=====КАРТА=====\n\nВыбранная карта: {}\nНажмите Escape для выхода\nНажмите соответствующую цифру для выбора локации:\n\n",
															game->curMap.size() > 0 ? game->curMap.data() : "Нет");
	for(int i = 0; i < game->maps.size(); ++i) {
		this->output += fmt::format("={}=: {}\n", i + 1, game->maps[i].data());
	}
}

WorldMapState::~WorldMapState() {
	
}

void WorldMapState::update(Game * game) {
	this->input = _getch();
	
	if(!this->isOff) {
		this->output = fmt::format("=====КАРТА=====\n\nВыбранная карта: {}\nНажмите Escape для выхода\nНажмите соответствующую цифру для выбора локации:\n\n",
															game->curMap.size() > 0 ? game->curMap.data() : "Нет");
		for(int i = 0; i < game->maps.size(); ++i) {
			this->output += fmt::format("={}=: {}\n", i + 1, game->maps[i].data());
		}
	}
	
	switch (this->input) {
		case 27: {
			this->st = 1;
			break;
		}
		default: {
			if(!this->isOff) {
				if(this->input >= '0' && this->input <= '9') {
					int d = this->input - '0';
					game->curMap = game->maps[d - 1];
					this->output = fmt::format("=====КАРТА=====\n\nНажмите Escape для выхода\nВыбрана карта {}", game->curMap);
					this->isOff = 1;
				}
			}
		}
		break;
	}
}

void WorldMapState::render() {
	system("cls");
	fmt::print("{}", this->output.data());
}

void WorldMapState::endState() {
	
}
