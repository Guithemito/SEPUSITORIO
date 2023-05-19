#pragma once
#include <allegro5/allegro.h>
class player {
public:
	player();
	void init();
	void update();
	void handleInput();
	void render();
	void dispose();

private:
	// Posição e tamanho
	float x;
	float y;
	// vetor
	float dx;
	float dy;
	float speed;
	//movimento
	bool left;
	bool right;
	bool up;
	bool down;

	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_BITMAP* bitmap;
};