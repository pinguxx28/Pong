#pragma once

#include <allegro5/allegro5.h>

namespace color
{
    typedef unsigned char u_char;

    ALLEGRO_COLOR rgb(u_char r, u_char g, u_char b);
    ALLEGRO_COLOR rgbf(float r, float g, float b);
    ALLEGRO_COLOR rgb_f(float r, float g, float b);

    typedef enum colorIndex
    {
        darkredI = 1,
        redI,
        orangeI,
        yellowI,
        greenI,
        darkgreenI,
        blueI,
        darkblueI,
        purpleI,
        pinkI,
        lightgrayI,
        grayI,
        darkgrayI,
        whiteI,
        beigeI,
        brownI,
        blackI,
    } colorIndex;
    
    const ALLEGRO_COLOR darkred   = rgb(128,0,0);
    const ALLEGRO_COLOR red       = rgb(255, 0, 0);
    const ALLEGRO_COLOR orange    = rgb(255, 140, 0);
    const ALLEGRO_COLOR yellow    = rgb(255, 255, 0);
    const ALLEGRO_COLOR green     = rgb(0, 255, 0);
    const ALLEGRO_COLOR darkgreen = rgb(0, 128, 0);
    const ALLEGRO_COLOR blue      = rgb(0, 0, 255);
    const ALLEGRO_COLOR darkblue  = rgb(0, 0, 128);
    const ALLEGRO_COLOR purple    = rgb(147, 112, 219);
    const ALLEGRO_COLOR pink      = rgb(255, 20, 147);
    const ALLEGRO_COLOR lightgray = rgb(211, 211, 211);
    const ALLEGRO_COLOR gray      = rgb(127, 127, 127);
    const ALLEGRO_COLOR darkgray  = rgb(105, 105, 105);
    const ALLEGRO_COLOR white     = rgb(250, 250, 250);
    const ALLEGRO_COLOR beige     = rgb(210, 180, 140);
    const ALLEGRO_COLOR brown     = rgb(160, 82, 45);
    const ALLEGRO_COLOR black     = rgb(0, 0 ,0);

    ALLEGRO_COLOR index(u_char index);
}