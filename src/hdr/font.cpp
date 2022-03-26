#include "font.hpp"

u_char font::index(char character)
{
    char ch = std::toupper(character);
    
    return ch - 32;
}