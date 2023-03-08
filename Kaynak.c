#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <math.h>
#include <time.h>
#include <allegro5\allegro_image.h>
#include <Windows.h>
 //Color swap kaldý


int k = 0;
int k2 = 0;
int k3 = 0;
int k4 = 0;
int k5 = 0;
int k6 = 0;
int top=0;
int tempk = 0;
int tempk2 = 0;
int tempk3 = 0;
int tempk4 = 0;
int tempk5 = 0;
int tempk6 = 0;
int teo=0;

int a = 10;
int xpos=250;
int ypos=750;
int direction = 1;


char codes[3][3] = {{ 255,0,255 }, { 255,127,80 }, { 0,0,195 }};

int main() {
	

	al_init_primitives_addon();
	ALLEGRO_TIMER* timer;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_BITMAP* bitmap = NULL;
	al_init();

	al_install_keyboard();

	display = al_create_display(500, 1500);   
	al_set_window_position(display, 0, 0);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 10);


	al_draw_filled_circle(xpos, ypos, 10, al_map_rgb(255, 255, 255));	      //top
	al_draw_filled_rectangle(0, 0, 50, 500, al_map_rgb(255, 0, 255));         //1. dikdörtgen sol üst
	al_draw_filled_rectangle(0, 500, 50, 1000, al_map_rgb(255, 127, 80));      //2. dikdörtgen sol orta 
	al_draw_filled_rectangle(0, 1000, 50, 1500, al_map_rgb(255, 0, 255));       //3. dikdörtgen sol alt
	al_draw_filled_rectangle(450, 0, 500, 500, al_map_rgb(0, 0, 195));        //4. dikdörtgen sað üst 
	al_draw_filled_rectangle(450, 500, 500, 1000, al_map_rgb(255 ,127, 80));     //5. dikdörtgen sað orta 
	al_draw_filled_rectangle(450, 1000, 500, 1500, al_map_rgb(0, 0, 195));  //6. dikdörtgen sað alt
	al_start_timer(timer);
	

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));     


	al_init_image_addon();
	
	bitmap = al_load_bitmap("end.jpg");
	assert(bitmap != NULL);

	while (1) {
		al_clear_to_color(al_map_rgb(0, 0, 0));              
		al_draw_filled_circle(xpos, ypos, 10, al_map_rgb(codes[top][0], codes[top][1], codes[top][2]));
		srand(time(NULL));
		
		if (ypos <= 0 || ypos >= 1500) {
			break;
		}
		ALLEGRO_EVENT press;
		al_wait_for_event(queue, &press);

		if (xpos <= 60) {
			direction = 1;
			k = rand() % 3;
			k2 = rand() % 3;
			k3 = rand() % 3;
			k4 = rand() % 3;
			k5 = rand() % 3;
			k6 = rand() % 3;

			if (ypos < 500 && ypos>0) {
				if (top != tempk) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;

			}
			else if (ypos < 1000 && ypos >= 500) {
				if (top != tempk2) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;
			}
			else if (ypos < 1500 && ypos >= 1000) {
				if (top != tempk3) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;
			}
			while ((top != k4 || top != k5 || top != k6) && (k4 == k5 || k5 == k6 || k4 == k6)) {
				k4 = rand() % 3;
				k5 = rand() % 3;
				k6 = rand() % 3;
				
			}
								
		}

		
		if (xpos >= 440) {
			
			direction = 2;
			k = rand() % 3;
			k2 = rand() % 3;
			k3 = rand() % 3;
			k4 = rand() % 3;
			k5 = rand() % 3;
			k6 = rand() % 3;
			if (ypos < 500 && ypos>0) {
				if (top != tempk4) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;

			}
			else if (ypos < 1000 && ypos >= 500) {
				if (top != tempk5) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;
			}
			else if (ypos < 1500 && ypos >= 1000) {
				if (top != tempk6) {
					al_draw_bitmap(bitmap, 0, 0, 0);
					al_flip_display();
					Sleep(3000);
					break;
				}
				else
					top = rand() % 3;
			}  
			
			while ((top != k || top != k2 || top != k3) && (k == k2 || k2 == k3 || k == k3)) {
				k = rand() % 3;
				k2 = rand() % 3;
				k3 = rand() % 3;

			}
		}
		if (press.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			ypos -= 55;
		}
		if (direction== 1) {
			xpos += 10;
			ypos += 20;
		}
		if (direction == 2) {		
			xpos -= 10;
			ypos += 20;
		
		}
		
		
		

		al_draw_filled_rectangle(0, 0, 50, 500, al_map_rgb(codes[k][0], codes[k][1], codes[k][2]));
	
		al_draw_filled_rectangle(0, 500, 50, 1000, al_map_rgb(codes[k2][0], codes[k2][1], codes[k2][2]));
		
		al_draw_filled_rectangle(0, 1000, 50, 1500, al_map_rgb(codes[k3][0], codes[k3][1], codes[k3][2]));
		
		al_draw_filled_rectangle(450, 0, 500, 500, al_map_rgb(codes[k4][0], codes[k4][1], codes[k4][2]));

		al_draw_filled_rectangle(450, 500, 500, 1000, al_map_rgb(codes[k5][0], codes[k5][1], codes[k5][2]));

		al_draw_filled_rectangle(450, 1000, 500, 1500, al_map_rgb(codes[k6][0], codes[k6][1], codes[k6][2]));
		
		al_flip_display();

		tempk = k;
		tempk2 = k2;
		tempk3 = k3;
		tempk4 = k4;
		tempk5 = k5;
		tempk6 = k6;



		
	}
	//al_draw_bitmap(bitmap,  0, 0, 0);
	//al_flip_display();
}