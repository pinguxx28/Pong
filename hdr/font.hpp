#pragma once

#include <string>

namespace font
{
    typedef unsigned char u_char;

    const u_char totalLetters = 26;
    const u_char fontWidth = 8;
    const u_char fontSize = fontWidth * fontWidth;

    u_char index(char character) { return toupper(character) - 65; }

    bool font[totalLetters][fontSize] = 
    {
        {
        // A
        0,0,0,1,1,0,0,0,
        0,0,1,1,1,1,0,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // B
        0,1,1,1,1,1,0,0,
        0,1,0,0,0,1,1,0,
        0,1,0,0,0,1,1,0,
        0,1,1,1,1,1,0,0,
        0,1,0,0,0,1,1,0,
        0,1,0,0,0,1,1,0,
        0,1,0,0,0,1,1,0,
        0,1,1,1,1,1,0,0},{
        // C
        0,0,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0,},{
        // D
        0,1,1,1,1,1,0,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,0,0,},{
        // E
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0},{
        // F
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0},{
        // G
        0,0,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0},{
        // H
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // I
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0},{
        // J
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,0,1,1,0,
        0,0,0,0,0,1,1,0,
        0,0,0,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0},{
        // K
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,1,1,0,0,
        0,1,1,1,1,0,0,0,
        0,1,1,1,1,0,0,0,
        0,1,1,0,1,1,0,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // L
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0},{
        // M
        0,1,0,0,0,0,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // N
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,0,1,1,0,
        0,1,1,1,0,1,1,0,
        0,1,1,0,1,1,1,0,
        0,1,1,0,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // O
        0,0,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0},{
        // P
        0,1,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0},{
        // Q
        0,0,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,1,1},{
        // R
        0,1,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,0,0,
        0,1,1,0,1,1,1,0,
        0,1,1,0,0,1,1,0},{
        // S
        0,0,1,1,1,1,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,0,0,
        0,0,1,1,1,1,1,0,
        0,0,0,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0},{
        // T
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0},{
        // U
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0},{
        // V
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,0,1,0,0,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0},{
        // W
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,1,1,0,
        0,1,0,0,0,0,1,0},{
        // X
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,0,1,1,1,1,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,1,1,1,1,0,0,
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0},{
        // Y
        0,1,1,0,0,1,1,0,
        0,1,1,0,0,1,1,0,
        0,0,1,1,1,1,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0},{
        // Z
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,1,1,0,0,
        0,0,0,1,1,0,0,0,
        0,0,1,1,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0}
    };
}