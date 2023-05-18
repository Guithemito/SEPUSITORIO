#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include "Nave.h"
#include "Bala.h"
using namespace std;


const int nave_w = 50;
const int nave_h = 50;
const int SCREEN_W = 900;
const int SCREEN_H = 750;
const int speed = 10;
const float speed_bala = 0.3;




int main() {
	// Inicializar Allegro

	if (!al_init()) {
		std::cout << "Falha ao inicializar Allegro!" << std::endl;
		return -1;
	}

	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_init_ttf_addon();


	// Criar janela
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	ALLEGRO_TIMER* bala_timer = al_create_timer(0.5 / 5.0);


	//registar eventos 
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(bala_timer));


	// Variáveis para controlar a lógica do jogo
	bool sair = true;
	bool redraw = true;


	std::vector <bool>Teclas(5, false);//0 corresponde a cima, 1 a baixo,2 a direita,3 a esquerda,4 a disparar
	std::vector <Bala>Balas;



	//iniciar timer
	al_start_timer(timer);
	al_start_timer(bala_timer);


	// Criar janela

	if (!display) {
		std::cerr << "Falha ao criar janela!" << std::endl;
		return -1;
	}
	al_set_window_title(display, "Jogo da Nave");

	// Criação da nave
	Nave nave(SCREEN_W / 2 - nave_w / 2, SCREEN_H / 2, speed);


	// Carregar imagem da nave
	ALLEGRO_BITMAP* Nave_bitmap = al_load_bitmap("Nave.png");
	if (!Nave_bitmap) {
		std::cout << "Falha ao carregar imagem da nave!" << std::endl;
		al_destroy_display(display);
		return -1;
	}

	// Criar fila de eventos

	if (!event_queue) {
		std::cout << "Falha ao criar fila de eventos!" << std::endl;
		al_destroy_display(display);
		al_destroy_bitmap(Nave_bitmap);
		return -1;
	}
	//Criar timer  

	if (!timer) {
		std::cerr << "Falha ao criar timer!" << std::endl;
		al_destroy_display(display);
		al_destroy_bitmap(Nave_bitmap);
		return -1;
	}
	//Bala bala(nave.get_x() + nave_w, nave.get_y() , 0, -10,sprite);
	





	while (sair) {
		ALLEGRO_EVENT ev;
		// Processar eventos
		if (al_get_next_event(event_queue, &ev)) {
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

				sair = false;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					sair = false;
					break;
				case ALLEGRO_KEY_UP:
					Teclas[0] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					Teclas[1] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					Teclas[2] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					Teclas[3] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					Teclas[4] = true;
				
					break;

				}

			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					Teclas[0] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					Teclas[1] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					Teclas[2] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					Teclas[3] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					Teclas[4] = false;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == timer) {
				if (Teclas[0] == true) {
					nave.move_up();
					if (nave.get_y() < -nave_h / 2) {
						nave.set_y(-nave_h / 2);//isto è pra na parte de cima ficar meia nave dentro 
					}
				}
				if (Teclas[1] == true) {
					nave.move_down();
					if (nave.get_y() > SCREEN_H - nave_h / 2) {
						nave.set_y(SCREEN_H - nave_h / 2);//isto è pra na parte de cima ficar meia nave dentro 
					}

				}
				if (Teclas[2] == true) {
					nave.move_right();
					if (nave.get_x() > SCREEN_W / 2 - nave_w / 2) {
						nave.set_x(SCREEN_W / 2 - nave_w / 2);
					}
				}
				if (Teclas[3] == true) {
					nave.move_left();
					if (nave.get_x() < 0) {
						nave.set_x(0);
					}
				}
			}
				
			else if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == bala_timer) {
				if (Teclas[4] == true) {
					Bala bala(nave.get_x() + nave_w, nave.get_y());
					Balas.push_back(bala);

				}
			}
			

		}

		// Limpar a tela e desenhar a nave
		al_clear_to_color(al_map_rgb(47, 123, 100));
		al_draw_scaled_bitmap(Nave_bitmap, 0, 0, al_get_bitmap_width(Nave_bitmap), al_get_bitmap_height(Nave_bitmap), nave.get_x(), nave.get_y(), nave_w, nave_h, 0);
		for (auto &bala : Balas) {
			bala.update(speed_bala);
			bala.draw(bala.getX(),bala.getY()+10);
	
		}

		// Atualizar a tela
		al_flip_display();
	}





	// Destruir objetos do Allegro e encerrar o jogo
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_destroy_bitmap(Nave_bitmap);
	al_destroy_timer(timer);
	al_destroy_timer(bala_timer);


	return 0;
}