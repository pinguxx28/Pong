#pragma once

namespace vec
{
    typedef struct vec2D { float x, y; } vec2D;

    vec2D addVec2D(vec2D vec1, vec2D vec2);
    vec2D subVec2D(vec2D vec1, vec2D vec2);
    vec2D multVec2D(vec2D vec1, vec2D vec2);
    vec2D divVec2D(vec2D vec1, vec2D vec2);
};