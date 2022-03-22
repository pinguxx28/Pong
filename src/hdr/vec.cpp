#include "vec.hpp"

vec::vec2D vec::addVec2D(vec::vec2D vec1, vec::vec2D vec2)
{
    vec::vec2D tempVec = { .x = vec1.x + vec2.x, .y = vec2.y + vec2.y };
    return tempVec;
}
vec::vec2D vec::subVec2D(vec::vec2D vec1, vec::vec2D vec2)
{
    vec::vec2D tempVec = { .x = vec1.x - vec2.x, .y = vec2.y - vec2.y };
    return tempVec;
}
vec::vec2D vec::multVec2D(vec::vec2D vec1, vec::vec2D vec2)
{
    vec::vec2D tempVec = { .x = vec1.x * vec2.x, .y = vec2.y * vec2.y };
    return tempVec;
}
vec::vec2D vec::divVec2D(vec::vec2D vec1, vec::vec2D vec2)
{
    vec::vec2D tempVec = { .x = vec1.x / vec2.x, .y = vec2.y / vec2.y };
    return tempVec;
}