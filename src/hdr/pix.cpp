#include "pix.hpp"

using namespace pix;

void mustInit(bool test, const char *desc)
{
	if (test) return;

	std::printf("Couldn't initialize %s\n", desc);
	std::exit(1);
}

ALLEGRO_DISPLAY* Pix::getDisp()
{
	return dDisp;
};

bool Pix::running()
{
	return !bDone;
};
bool Pix::dispClosed()
{
	return bDone;
};

void Pix::preDraw()
{
	al_set_target_bitmap(bBuffer);

	al_clear_to_color(cBackgroundColor);
};
void Pix::postDraw()
{
	al_set_target_backbuffer(dDisp);
	al_draw_scaled_bitmap(bBuffer, 0, 0, sBufferW, sBufferH, 0, 0, sDispW, sDispH, 0);

	al_flip_display();
};

Pix::Pix(short sBufferW, short sBufferH, float fDispScale, ALLEGRO_COLOR cBackgroundColor)
{
	// set display variables
	this->sBufferW = sBufferW;
	this->sBufferH = sBufferH;
	this->sDispW = fDispScale * sBufferW;
	this->sDispH = fDispScale * sBufferH;
	this->fDispScale = fDispScale;

	this->cBackgroundColor = cBackgroundColor;

	// initialize allegro
	mustInit(al_init(), "allegro");

	// create timer
	tTimer = al_create_timer(1.0 / 60);
	mustInit(tTimer, "timer");

	// create event queue
	qQueue = al_create_event_queue();
	mustInit(qQueue, "queue");

	// create the display
	dDisp = al_create_display(sDispW, sDispH);
	mustInit(dDisp, "display");

	// create the bitmap buffer
	bBuffer = al_create_bitmap(sBufferW, sBufferH);
	mustInit(bBuffer, "bitmap buffer");

	// initialize primitives
	mustInit(al_init_primitives_addon(), "primitives");

	// initialize images
	mustInit(al_init_image_addon(), "image addon");

	// event queues?
	al_register_event_source(qQueue, al_get_display_event_source(dDisp));
	al_register_event_source(qQueue, al_get_timer_event_source(tTimer));


	// clear keyboard array
	memset(ucKey, 0, sizeof(ucKey));

	// set variables
	lFrames = 0;
	bDone = false;
	bRedraw = true;

	// start the timer
	al_start_timer(tTimer);
};
Pix::~Pix()
{
	al_destroy_bitmap(bBuffer);
	al_destroy_display(dDisp);

	al_destroy_timer(tTimer);
	al_destroy_event_queue(qQueue);
};

void Pix::keyboardInit()
{
	mustInit(al_install_keyboard(), "keyboard");

	al_register_event_source(qQueue, al_get_keyboard_event_source());
};
void Pix::mouseInit()
{
	mustInit(al_install_mouse(), "mouse");

	al_register_event_source(qQueue, al_get_mouse_event_source());
};

void Pix::hideMouse()
{
	al_hide_mouse_cursor(dDisp);
};

void Pix::waitForEvent()
{
	al_wait_for_event(qQueue, &eEvent);
};
ALLEGRO_EVENT_TYPE Pix::getEvent()
{
	return eEvent.type;
};

void Pix::updateFrame()
{
	if (ucKey[ALLEGRO_KEY_ESCAPE]) bDone = true;
	bRedraw = true;
	lFrames++;
};
void Pix::closeDisp()
{
	bDone = true;
};

bool Pix::nextFrame()
{
	return (bRedraw && al_is_event_queue_empty(qQueue));
};

void Pix::keyboardUpdate()
{
	switch (eEvent.type)
	{
	case NEW_FRAME:
		for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
			ucKey[i] &= KEY_SEEN;
		break;

	case KEY_DOWN:
		ucKey[eEvent.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
		break;

	case KEY_UP:
		ucKey[eEvent.keyboard.keycode] &= KEY_RELEASED;
		break;
	};
};
void Pix::mouseUpdate()
{
	switch (eEvent.type)
	{
	case MOUSE_MOVE:
		fMouseX = eEvent.mouse.x;
		fMouseY = eEvent.mouse.y;
		fMouseZ = eEvent.mouse.z;
		break;
	};
};
bool Pix::keyPressed(u_char keycode)
{
	return ucKey[keycode];
};
