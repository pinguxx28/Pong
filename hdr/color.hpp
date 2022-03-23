#pragma once

#include <allegro5/allegro5.h>

namespace color
{
    ALLEGRO_COLOR rgb(u_char r, u_char g, u_char b);
    ALLEGRO_COLOR rgbf(float r, float g, float b);
    ALLEGRO_COLOR rgb_f(float r, float g, float b);

    enum colorIndexes
    {
        whiteI  = 1,
        blackI,
        greyI,
        redI,
        orangeI,
        yellowI,
        greenI,
        blueI,
        purpleI,
    };
    
    const ALLEGRO_COLOR red    = rgbf(1, 0, 0);
    const ALLEGRO_COLOR orange = rgbf(1, 0.5, 0);
    const ALLEGRO_COLOR yellow = rgbf(1, 1, 0);
    const ALLEGRO_COLOR green  = rgbf(0, 1, 0);
    const ALLEGRO_COLOR blue   = rgbf(0, 0, 1);
    const ALLEGRO_COLOR purple = rgbf(1, 0, 1);
    const ALLEGRO_COLOR white  = rgbf(1, 1, 1);
    const ALLEGRO_COLOR black  = rgbf(0, 0, 0);
    const ALLEGRO_COLOR grey   = rgbf(0.5, 0.5, 0.5);

    ALLEGRO_COLOR index(u_char index);
}