#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "font.hpp"

namespace draw
{
    void rectangle(u_char x, u_char y, ALLEGRO_COLOR color);

    void texture64 (const bool textureMap[64], u_char x, u_char y, ALLEGRO_COLOR color);
    void string(char *str, u_char x, u_char y, ALLEGRO_COLOR color);
}