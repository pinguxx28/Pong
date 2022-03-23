#include "pix.hpp"
#include "draw.hpp"
#include "color.hpp"
#include "font.hpp"

// === DISPLAY ===
#define dispW (8 * 32)
#define dispH (8 * 30)


int main()
{
	std::printf("Loading...\n");
	// === LOADING ===

	char str[] = "\"Hello World!\", says Bandy. Oh no;:@?";

	pix::Pix engine(dispW, dispH, 3, color::black);
	engine.keyboardInit();
	engine.mouseInit();

	for (int i = 32; i < 200; i++)
	printf("%c", i);

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

			char ch;
			for (register int c = 0; c < strlen(str); c++)
			{
				draw::texture64(font::font[font::index(str[c])], c * 8 - u_char(c / 20) * (8 * 20), u_char(c / 20) * 8 + u_char(c / 20), color::white);
			}

			engine.postDraw(); 
		};
	};

	return 0;
};
