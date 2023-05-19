#include "player.h"
#include "constants.h"
#include <allegro5/allegro_primitives.h>
player::player() {};
void player::init() {
	x = 50;
	y = GAME_HEIGHT / 2;
	
	
	speed = 8;
	left = right = up = down = false;
	bitmap=al_load_bitmap("res/aviao.png");

}
void player::update() {
	if (left) {
		dx = -speed;
	}
	else if (right) {
		dx = speed;
	}
	else {
		dx = 0;
	}
	if (up) {
		dy = -speed;
	}
	else if (down) {
		dy = speed;
	}
	else {
		dy = 0;
	}
	x += dx;
	y += dy;
	if (x <= 0)x=0;
	if (y <= 0)y = 0;
	if (y >= GAME_HEIGHT-20)y = GAME_HEIGHT-20;
	if (x >= GAME_WIDTH-50)x =GAME_WIDTH-50;
}
	
void player::handleInput() {
		al_get_keyboard_state(&key_state);
		left = al_key_down(&key_state, ALLEGRO_KEY_LEFT); 
		right =al_key_down(&key_state, ALLEGRO_KEY_RIGHT); 
		up = al_key_down(&key_state, ALLEGRO_KEY_UP); 
		down = al_key_down(&key_state, ALLEGRO_KEY_DOWN);

};
void player::render() {
	al_draw_bitmap(bitmap,x,y,0);

};
void player::dispose() {  };