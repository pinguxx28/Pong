#include "sprite.hpp"

Sprite::Sprite(int sx, int sy, int sw, int sh, float dx, float dy, int dw, int dh, const char* image, ALLEGRO_COLOR c, GameEngine *engine)
{
	// source
	// coords
	this->sx = sx;
	this->sy = sy;
	// dimensions
	this->sw = sw;
	this->sh = sh;

	// destination
	// coords
	this->x = dx;
	this->y = dy;
	// dimensions
	this->w = dw;
	this->h = dh;

	// load bitmap
	useimg = true;
	this->engine = engine;
	this->disp = engine->getDisp();

	this->image = al_load_bitmap(image);
	if (!this->image)
	{
		useimg = false;
		this->image = al_create_bitmap(dw, dh);
		al_set_target_bitmap(this->image);
		al_clear_to_color(c);
		al_set_target_backbuffer(disp);
	};
};
Sprite::~Sprite()
{
	al_destroy_bitmap(image);
};

void Sprite::draw()
{
	if (useimg)
		al_draw_scaled_bitmap(image, sx, sy, sw, sh, x, y, w, h, 0);
	else
		al_draw_bitmap(image, x, y, 0); 
};
