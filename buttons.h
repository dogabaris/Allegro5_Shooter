#include "globals.h"

class Buttons {
private:
	int x;
	int y;
	int boundX;
	int boundY;
	bool hover;
	
	ALLEGRO_FONT *font;


public:
	Buttons():
	  hover(false) {}

	void init(int x, int y, int boundX, int boundY, ALLEGRO_FONT *font) {
		Buttons::x = x;
		Buttons::y = y;
		Buttons::boundX = boundX;
		Buttons::boundY = boundY;
		Buttons::font = font;
	}

	void render(int button) { // 1(play), 2(help), 3(options), 4(back), 5(exit), 6(menu), 7(volumeP), 8(volumeM), 9(difficultyP), 10(difficultyM)
		if(!Buttons::hover) {
			if(button == 1)
				al_draw_text(Buttons::font, al_map_rgb(counter185r,counter185g,counter185b), Buttons::x, Buttons::y, 1, "PLAY");
			else if(button == 2)
				al_draw_text(Buttons::font, al_map_rgb(counter185r,counter185g,counter185b), Buttons::x, Buttons::y, 1, "HIGHSCORE");
			else if(button == 3)
				al_draw_text(Buttons::font, al_map_rgb(counter185r,counter185g,counter185b), Buttons::x, Buttons::y, 1, "EXIT");
		}
		else if(Buttons::hover) {
			if(button == 1)
				al_draw_text(Buttons::font, al_map_rgb(255,255,255), Buttons::x, Buttons::y, 1, "PLAY");
			else if(button == 2)
				al_draw_text(Buttons::font, al_map_rgb(255,255,255), Buttons::x, Buttons::y, 1, "HIGSCORE");
			else if(button == 3)
				al_draw_text(Buttons::font, al_map_rgb(255,255,255), Buttons::x, Buttons::y, 1, "EXIT");
		}
	}

	void hoverDetect() {
		if(mouseX > Buttons::x - Buttons::boundX &&
			mouseX < Buttons::x + Buttons::boundX &&
			mouseY > Buttons::y &&
			mouseY < Buttons::y + Buttons::boundY*2) {
				Buttons::hover = true;
		}
		else
			Buttons::hover = false;
	}

	int getHover() {return Buttons::hover;}
	void setHover(bool hover) {Buttons::hover = hover;}
	int getX() {return Buttons::x;}
	int getY() {return Buttons::y;}
	int getBoundX() {return Buttons::boundX;}
	int getBoundY() {return Buttons::boundY;}
};
