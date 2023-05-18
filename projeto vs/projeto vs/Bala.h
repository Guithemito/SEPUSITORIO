#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
using namespace std;



class Bala {
public:
    Bala(float x, float y);
    void update(float dt);
    void draw(float a, float b);
    float getX();
    float getY();
private:
    float x,y;

    
};
