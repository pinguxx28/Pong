#include "gameengine.hpp"

ALLEGRO_DISPLAY* GameEngine::getDisp()
{
	return disp;
};

bool GameEngine::running()
{
	return !done;
};
bool GameEngine::disp_closed()
{
	return done;
};

void GameEngine::pre_draw()
{
	al_set_target_bitmap(buffer);

	al_clear_to_color(background_color);
};
void GameEngine::post_draw()
{
	al_set_target_backbuffer(disp);
	al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISP_W, DISP_H, 0);

	al_flip_display();
};

GameEngine::GameEngine(unsigned short BUFFER_W, unsigned short BUFFER_H, unsigned char DISP_SCALE,
					   ALLEGRO_COLOR background_color,
					   unsigned short multisampling)
{
	// set display variables
	this->BUFFER_W = BUFFER_W;
	this->BUFFER_H = BUFFER_H;
	this->DISP_W = DISP_SCALE * BUFFER_W;
	this->DISP_H = DISP_SCALE * BUFFER_H;
	this->DISP_SCALE = DISP_SCALE;

	this->background_color = background_color;

	// initialize allegro
	must_init(al_init(), "allegro");

	// create timer
	timer = al_create_timer(1.0 / 60);
	must_init(timer, "timer");

	// create event queue
	queue = al_create_event_queue();
	must_init(queue, "queue");

	// create the display
	disp = al_create_display(DISP_W, DISP_H);
	must_init(disp, "display");

	// create the bitmap buffer
	buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
	must_init(buffer, "bitmap buffer");

	// initialize primitives
	must_init(al_init_primitives_addon(), "primitives");

	// initialize images
	must_init(al_init_image_addon(), "image addon");

	// event queues?
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	if (multisampling > 0)
	{
		al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
		al_set_new_display_option(ALLEGRO_SAMPLES, multisampling, ALLEGRO_SUGGEST);
	};

	// clear keyboard array
	memset(key, 0, sizeof(key));

	// set variables
	frames = 0;
	score = 0;
	done = false;
	redraw = true;

	// start the timer
	al_start_timer(timer);
};
GameEngine::~GameEngine()
{
	al_destroy_bitmap(buffer);
	al_destroy_display(disp);

	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
};

void GameEngine::keyboard_init()
{
	must_init(al_install_keyboard(), "keyboard");

	al_register_event_source(queue, al_get_keyboard_event_source());
};
void GameEngine::mouse_init()
{
	must_init(al_install_mouse(), "mouse");

	al_register_event_source(queue, al_get_mouse_event_source());
};

void GameEngine::hide_mouse()
{
	al_hide_mouse_cursor(disp);
};

void GameEngine::wait_for_event()
{
	al_wait_for_event(queue, &event);
};
ALLEGRO_EVENT_TYPE GameEngine::get_event()
{
	return event.type;
};

void GameEngine::update_frame()
{
	if (key[ALLEGRO_KEY_ESCAPE]) done = true;
	redraw = true;
	frames++;
};
void GameEngine::close_disp()
{
	done = true;
};

bool GameEngine::next_frame()
{
	return (redraw && al_is_event_queue_empty(queue));
};

void GameEngine::keyboard_update()
{
	switch (event.type)
	{
	case NEW_FRAME:
		for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
			key[i] &= KEY_SEEN;
		break;

	case KEY_DOWN:
		key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
		break;

	case KEY_UP:
		key[event.keyboard.keycode] &= KEY_RELEASED;
		break;
	};
};
void GameEngine::mouse_update()
{
	switch (event.type)
	{
	case MOUSE_MOVE:
		mouse_x = event.mouse.x;
		mouse_y = event.mouse.y;
		mouse_z = event.mouse.z;
		break;
	};
};
bool GameEngine::key_pressed(unsigned char keycode)
{
	return key[keycode];
};
