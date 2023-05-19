#include "Background.h"
#include "constants.h"
Background::Background(std::string filename) {
	backgroundImage = al_load_bitmap(filename.c_str());
	if (!backgroundImage) {
		std::cout << "Could not load the background image. Please check your image path correctly : " << filename << std::endl;
	}
}
void Background::update() {
	x -= 2;
	if (x < -GAME_WIDTH) x = 0;
}
void Background:: render(){}
void Background::dispose() {

al_destroy_bitmap(backgroundImage);
}