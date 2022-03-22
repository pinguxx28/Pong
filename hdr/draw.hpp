#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

namespace draw
{
    void rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color, float thickness);
    void line(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
    void ellipse(float cx, float cy, float rx, float ry, ALLEGRO_COLOR color, float thickness);
    void circle(float cx, float cy, float r, ALLEGRO_COLOR color, float thickness);

    void texture4x4(bool textureMap[4][4], float x, float y, float w, float h, ALLEGRO_COLOR color);
    void texture16 (bool textureMap[16]  , float x, float y, float w, float h, ALLEGRO_COLOR color);

    void texture8x8(bool textureMap[8][8], float x, float y, float w, float h, ALLEGRO_COLOR color);
    void texture64 (bool textureMap[64]  , float x, float y, float w, float h, ALLEGRO_COLOR color);
}