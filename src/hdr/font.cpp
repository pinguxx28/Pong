#include "font.hpp"

u_char font::index(char character)
{
    char ch = toupper(character);
    
    return ch - 32;
}