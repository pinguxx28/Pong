#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "gameengine.hpp"
#include "basic.hpp"

class Sprite
{
	private:
		ALLEGRO_BITMAP *image;
		ALLEGRO_DISPLAY *disp;
	public:
		// source
		int sx, sy; // coords
		int sw, sh; // dimensions
		// destination
		float x, y; // coords
		int w, h; // dimensions

		bool useimg;
		GameEngine *engine;

		Sprite(int sx, int sy, int sw, int sh, float dx, float dy, int dw, int dh, const char *image, ALLEGRO_COLOR c, GameEngine *GameEngine);
		~Sprite();
		
		void draw();
};
