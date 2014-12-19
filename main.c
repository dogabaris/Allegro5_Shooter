#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const int FPS = 60;

int main (void)
{
al_init();
al_init_primitives_addon();
al_init_image_addon();
al_install_keyboard();
al_install_mouse();
al_init_font_addon();
al_init_ttf_addon();

int width = 800;
int height = 600;
int x = width/2;
int y = height/2;
bool quit = false;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *queue,*event;
ALLEGRO_TIMER *timer = 0;
ALLEGRO_SAMPLE *hitSound;
ALLEGRO_FONT *Font;
ALLEGRO_BITMAP *image;
	
Font = al_load_font("HOOG0555.ttf", 35, 0);
queue = al_create_event_queue();
display = al_create_display(width, height);
image = al_load_bitmap("background.jpg");

al_register_event_source(queue, al_get_keyboard_event_source());
al_register_event_source(queue, al_get_display_event_source(display));


al_draw_bitmap(image, 0, 0, 0);
al_flip_display();

while(!quit)
{
ALLEGRO_EVENT e;
al_wait_for_event(queue, &e);

if(e.type == ALLEGRO_EVENT_KEY_DOWN)
{
switch(e.keyboard.keycode)
{
case ALLEGRO_KEY_W:
	y -= 10;
	break;

case ALLEGRO_KEY_S:
	y += 10;
	break;

case ALLEGRO_KEY_A:
	x -= 10;
	break;

case ALLEGRO_KEY_D:
	x += 10;
	break;
}
}

else if (e.type == ALLEGRO_EVENT_KEY_UP)
{
if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
	quit = true;
}

else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
{
	quit = true;
}

else if(x <= 0)
{
	x += 10;
}

else if(y >= height - 15)
{
	y = height - 15;
}

else if(x >= width - 5)
{
	x = width-15;
}

else if(y <= 15)
{
	y += 10;
}


al_draw_triangle(x,y-15,x-15,y+15,x+15,y+15,al_map_rgb(0,255,0),2.0);
al_flip_display();
al_draw_bitmap(image, 0, 0, 0);
al_draw_text(Font,al_map_rgb(0,0,255),300,400,0,"Merhaba");


}


al_destroy_bitmap(image);
al_destroy_display(display);

return 0;
}
