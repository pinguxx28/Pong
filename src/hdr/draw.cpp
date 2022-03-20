#include "draw.hpp"

void draw::rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_rectangle(x1, y1, x2, y2, color);
    else al_draw_rectangle(x1, y1, x2, y2, color, thickness);
}

void draw::triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
    else al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness);
}

void draw::line(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness)
{
    al_draw_line(x1, y1, x2, y2, color, thickness);
}

void draw::ellipse(float cx, float cy, float rx, float ry, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_ellipse(cx, cy, rx, ry, color);
    else al_draw_ellipse(cx, cy, rx, ry, color, thickness);
}

void draw::circle(float cx, float cy, float r, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_circle(cx, cy, r, color);
    else al_draw_circle(cx, cy, r, color, thickness);
}