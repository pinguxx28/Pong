#include "pix.hpp"
#include "draw.hpp"
#include "colors.hpp"
#include "vec.hpp"

// === DISPLAY ===
#define sDispW 720
#define sDispH 540


int main()
{
	// initialize an the game engine
	pix::Pix engine(sDispW, sDispH, 2, color::black);
	engine.keyboardInit();
	engine.mouseInit();

	std::printf("Loading...\n");
	// === LOADING ===
	// ======
	std::printf("Done!\n");

	// gameloop
	while (engine.running())
	{
		engine.waitForEvent(); // wait until we receive an event

		// check what the event was
		switch (engine.getEvent())
		{
		case pix::NEW_FRAME: // new frame
			engine.updateFrame(); // update frame
			break;
		case pix::DISP_CLOSE:	// display close button pressed
			engine.closeDisp(); // close the display
			break;
		};

		if (engine.dispClosed())
			break;				 // exit gameloop if display closed
		engine.keyboardUpdate(); // update keyboard
		engine.mouseUpdate();	 // update mouse

		// if we can draw the next frame
		if (engine.nextFrame())
		{
			engine.preDraw(); // prepare the drawing environment


			engine.postDraw(); // render
		};
	};

	return 0;
};
