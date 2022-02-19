#pragma once

#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "basic.hpp"

typedef enum EVENTS
{
	NEW_FRAME = ALLEGRO_EVENT_TIMER,
	DISP_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE,
} EVENT;

#define KEY_SEEN 1
#define KEY_RELEASED 2

typedef class GameEngine
{
	private:
		ALLEGRO_DISPLAY *disp;
		ALLEGRO_BITMAP *buffer;

		ALLEGRO_COLOR background_color;
		ALLEGRO_TIMER *timer;
		ALLEGRO_EVENT_QUEUE *queue;

		ALLEGRO_EVENT event;

	public:
		unsigned short BUFFER_W, BUFFER_H;
		unsigned short DISP_W, DISP_H;
		unsigned char DISP_SCALE;

		long frames;
		long score;

		bool done;
		bool redraw;

		unsigned char key[ALLEGRO_KEY_MAX];

		ALLEGRO_DISPLAY* getDisp();

		bool running();
		bool disp_closed();

		void pre_draw();
		void post_draw();

		GameEngine(unsigned short BUFFER_W, unsigned short BUFFER_H, unsigned char DISP_SCALE,
				   ALLEGRO_COLOR background_color,
				   unsigned short multisampling);
		~GameEngine();

		void wait_for_event();
		ALLEGRO_EVENT_TYPE get_event();

		void update_frame();
		void close_disp();

		bool next_frame();

		void keyboard_update();
		bool key_pressed(unsigned char keycode);
} GameEngine;