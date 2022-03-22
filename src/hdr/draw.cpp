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


// === TEXTURES ===

void draw::texture4x4(bool textureMap[4][4], float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 4; i++)
        for (register u_char j = 0; j < 4; j++)
            if (textureMap[i][j])
                draw::rectangle(x + j       * (w / 4), y + i       * (h / 4), 
                                x + (j + 1) * (w / 4), y + (i + 1) * (h / 4),
                                color, 0);
}

void draw::texture16(bool textureMap[16], float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 4; i++)
        for (register u_char j = 0; j < 4; j++)
            if (textureMap[i * 4 + j])
                draw::rectangle(x + j       * (w / 4), y + i       * (h / 4), 
                                x + (j + 1) * (w / 4), y + (i + 1) * (h / 4),
                                color, 0);
}

void draw::texture8x8(bool textureMap[8][8], float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 8; i++)
        for (register u_char j = 0; j < 8; j++)
            if (textureMap[i][j])
                draw::rectangle(x + j       * (w / 8), y + i       * (h / 8), 
                                x + (j + 1) * (w / 8), y + (i + 1) * (h / 8),
                                color, 0);
}
void draw::texture64 (bool textureMap[64], float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 8; i++)
        for (register u_char j = 0; j < 8; j++)
            if (textureMap[i * 8 + j])
                draw::rectangle(x + j       * (w / 8), y + i       * (h / 8), 
                                x + (j + 1) * (w / 8), y + (i + 1) * (h / 8),
                                color, 0);
}

