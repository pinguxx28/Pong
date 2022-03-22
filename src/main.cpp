#include "pix.hpp"
#include "draw.hpp"
#include "colors.hpp"

// === DISPLAY ===
#define dispW (8 * 32)
#define dispH (8 * 30)


int main()
{
	std::printf("Loading...\n");
	// === LOADING ===

	pix::Pix engine(dispW, dispH, 3, color::black);
	engine.keyboardInit();
	engine.mouseInit();

	// ======
	std::printf("Done!\n");

	while (engine.running())
	{
		engine.waitForEvent();
		
		switch (engine.getEvent())
		{
		case pix::NEW_FRAME: 

			engine.updateFrame(); 
			break;
		case pix::DISP_CLOSE:	
			engine.closeDisp(); 
			break;
		};

		if (engine.dispClosed()) break;				 
		engine.keyboardUpdate(); 
		engine.mouseUpdate();	 

		if (engine.nextFrame())
		{
			engine.preDraw(); 


			engine.postDraw(); 
		};
	};

	return 0;
};
