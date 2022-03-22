#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

namespace draw
{
    void rectangle(u_char x, u_char y, ALLEGRO_COLOR color);

    void texture64 (bool textureMap[64], u_char x, u_char y, ALLEGRO_COLOR color);
}