#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "font.hpp"

namespace draw
{
    void ellipse(float x, float y, float r, ALLEGRO_COLOR color);
    void rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color);

    void texture64 (const bool textureMap[64], float x, float y, float w, float h, ALLEGRO_COLOR color);
    void string(char *str, float x, float y, float w, float h, ALLEGRO_COLOR color);
}