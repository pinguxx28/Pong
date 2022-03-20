#pragma once

#include <allegro5/allegro5.h>

namespace color
{
    ALLEGRO_COLOR rgb(u_char r, u_char g, u_char b) { return al_map_rgb(r, g, b); }
    ALLEGRO_COLOR rgbf(float r, float g, float b) { return al_map_rgb_f(r, g, b); }
    ALLEGRO_COLOR rgb_f(float r, float g, float b) { return al_map_rgb_f(r, g, b);}

    ALLEGRO_COLOR red    = rgbf(1, 0, 0);
    ALLEGRO_COLOR orange = rgbf(1, 0.5, 0);
    ALLEGRO_COLOR yellow = rgbf(1, 1, 0);
    ALLEGRO_COLOR green  = rgbf(0, 1, 0);
    ALLEGRO_COLOR blue   = rgbf(0, 0, 1);
    ALLEGRO_COLOR purple = rgbf(1, 0, 1);
    ALLEGRO_COLOR white  = rgbf(1, 1, 1);
    ALLEGRO_COLOR black  = rgbf(0, 0, 0);
    ALLEGRO_COLOR grey   = rgbf(0.5, 0.5, 0.5);
    ALLEGRO_COLOR gray   = rgbf(0.5, 0.5, 0.5);
}