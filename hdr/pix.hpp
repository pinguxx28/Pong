#pragma once

#include <cstdio>
#include <cstdlib>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>


void mustInit(bool test, const char *desc);

namespace pix
{
    // Events
    typedef enum EVENT
    {
        NEW_FRAME  = ALLEGRO_EVENT_TIMER,
	    DISP_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE,
	    KEY_DOWN   = ALLEGRO_EVENT_KEY_DOWN,
	    KEY_UP     = ALLEGRO_EVENT_KEY_UP,
	    MOUSE_MOVE = ALLEGRO_EVENT_MOUSE_AXES,
		MOUSE_DOWN = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN,
		MOUSE_UP   = ALLEGRO_EVENT_MOUSE_BUTTON_UP,
		MOUSE_ENTER= ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY,
		MOUSE_LEAVE= ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY,
    } EVENT;

    #define KEY_SEEN 1
    #define KEY_RELEASED 2


    typedef class Pix
    {

	private:
		ALLEGRO_DISPLAY *dDisp;   // Main display
		ALLEGRO_BITMAP  *bBuffer; // Buffer to draw to

		ALLEGRO_COLOR cBackgroundColor; // Background color
		ALLEGRO_TIMER *tTimer;          // Timer
		ALLEGRO_EVENT_QUEUE *qQueue;    // Queue

		ALLEGRO_EVENT eEvent; // Event
    
    public:
		u_short sBufferW, sBufferH;
		u_short sDispW, sDispH;
		float   fDispScale;

		long lFrames;

		bool bDone, bRedraw;

		float fMouseX, fMouseY, fMouseZ;

		u_char ucKey[ALLEGRO_KEY_MAX];

		ALLEGRO_DISPLAY* getDisp();

		bool running();
		bool dispClosed();

		void preDraw();
		void postDraw();

		Pix(short sBufferW, short uBufferH, float fBufferScale, ALLEGRO_COLOR cBackgroundColor);
		~Pix();

		void keyboardInit();
		void mouseInit();

		void hideMouse();

		void waitForEvent();
		ALLEGRO_EVENT_TYPE getEvent();

		void updateFrame();
		void closeDisp();

		bool nextFrame();

		void keyboardUpdate();
		void mouseUpdate();
		bool keyPressed(u_char keycode);

    } Pix;
}