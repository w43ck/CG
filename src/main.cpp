#include "../inc/game.hpp"

int main() {
	
	Game * game = new Game();
	
	game->render();
	while(game->isRunning) {
		game->update();
		game->render();
	}
	
	delete game;
	
	return 0;
}