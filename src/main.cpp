#include <cstdlib>
#include <ctime>
#include "pix.hpp"
#include "colors.hpp"
#include "draw.hpp"

int main()
{
	// initialize an the game engine
	pix::Pix engine(480, 320, 1, color::black);
	engine.keyboardInit();
	engine.mouseInit();


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
			case pix::DISP_CLOSE:		 // display close button pressed
				engine.closeDisp(); // close the display
				break;
		};

		if (engine.dispClosed()) break; // exit gameloop if display closed
		engine.keyboardUpdate(); // update keyboard
		engine.mouseUpdate(); // update mouse

		// if we can draw the next frame
		if (engine.nextFrame())
		{
			engine.preDraw(); // prepare the drawing environment

			draw::circle(engine.fMouseX, std::abs(engine.fMouseY), std::abs(engine.fMouseZ), color::red, 0);

			engine.postDraw(); // render
		};
	};

	return 0;
};
