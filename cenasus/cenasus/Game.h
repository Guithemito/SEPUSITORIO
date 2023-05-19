#pragma once
#include "Background.h"
#include "player.h"
class Game
{
public:
	Game();
	void init();
	void update();
	void render();
	void handleInput();
	void dispose();


private:
	Background* background;
	player player;
};

