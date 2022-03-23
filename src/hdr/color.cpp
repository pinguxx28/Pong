#include "color.hpp"

ALLEGRO_COLOR color::rgb(u_char r, u_char g, u_char b) { return al_map_rgb(r, g, b); }
ALLEGRO_COLOR color::rgbf(float r, float g, float b) { return al_map_rgb_f(r, g, b); }
ALLEGRO_COLOR color::rgb_f(float r, float g, float b) { return al_map_rgb_f(r, g, b);}

ALLEGRO_COLOR color::index(u_char index)
{
    ALLEGRO_COLOR color = color::rgbf(0, 0, 0);
    switch (index)
    {
        case color::redI   : color = color::red   ; break;
        case color::orangeI: color = color::orange; break;
        case color::yellowI: color = color::yellow; break;
        case color::greenI : color = color::green ; break;
        case color::blueI  : color = color::blue  ; break;
        case color::purpleI: color = color::purple; break;
        case color::whiteI : color = color::white ; break;
        case color::blackI : color = color::black ; break;
        case color::greyI  : color = color::grey  ; break;
    }
    return color;
}