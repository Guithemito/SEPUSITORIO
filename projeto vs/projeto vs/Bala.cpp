
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <vector>


#include "Bala.h"


Bala::Bala (float x, float y) {
    this->x = x;
    this->y = y;
}

void Bala::update(float dt) {
    x += dt;
    
}

void Bala::draw(float a,float b){
    al_draw_circle(a, b, 5, al_map_rgb(169, 0, 0), 25);
}

float Bala::getX() {
    return x;
}

float Bala::getY() {
    return y;
}
