#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

class Nave {
public:
    Nave(int x, int y, int speed);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    int get_x();
    int get_y();
    void set_x(int xnovo);
    void set_y(int ynovo);
   
private:
    int x_;
    int y_;
    int speed_;
}; 
