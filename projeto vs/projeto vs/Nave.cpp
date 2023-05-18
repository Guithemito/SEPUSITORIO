#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <vector>


#include "Nave.h"

Nave::Nave(int x, int y, int speed) {
    this->x_ = x;
    this->y_ = y;
    this->speed_ = speed;
    
}

void Nave::move_up() {
    y_ -= speed_;
   
}

void Nave::move_down() {
    y_ += speed_;
}

void Nave::move_left() {
    x_ -= speed_;
}

void Nave::move_right() {
    x_ += speed_;
}

int Nave::get_x() {
    return x_;
}

int Nave::get_y() {
    return y_;
}

void Nave::set_x(int xnovo) {
    this->x_ = xnovo;
}

void Nave::set_y(int ynovo) {
    this->y_ = ynovo;
}