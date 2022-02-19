#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include "gameengine.hpp"
#include "sprite.hpp"

int main()
{
	// initialize an the game engine
	GameEngine engine(360, 272, 3, al_map_rgb_f(0, 0, 0), 1);

	// gameloop
	while (engine.running())
	{
		engine.wait_for_event(); // wait until we receive an event

		// check what the event was
		switch (engine.get_event())
		{
			case NEW_FRAME: // new frame

				engine.update_frame(); // update frame
				break;
			case DISP_CLOSE:		 // display close button pressed
				engine.close_disp(); // close the display
				break;
		};

		if (engine.disp_closed()) break; // exit gameloop if display closed
		engine.keyboard_update(); // update keyboard

		// if we can draw the next frame
		if (engine.next_frame())
		{
			engine.pre_draw(); // prepare the drawing environment

			engine.post_draw(); // render
		};
	};

	return 0;
};
