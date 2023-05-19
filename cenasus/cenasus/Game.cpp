#include "Game.h"

Game::Game() {}
void Game::init() {
	background = new Background("res/Fundo.png");
	player.init();
}
void Game::update() {
	background->update();
	player.update();
}
void Game::handleInput() {
	player.handleInput();
}
void Game::render() {
	background->render();
	player.render();
}
void Game::dispose() {
	background->dispose();
	player.dispose();

}