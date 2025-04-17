#pragma once
#include <conio.h>
#include <windows.h>
enum KeyState
{
    // Common
    DEL         = 83,
    INSERT      = 82,
    END         = 79,
    HOME        = 71,
    SPACEBAR    = 32,
    ESC         = 27,
    ENTER       = 13,
    TAB         = 9,
    BACKSPACE   = 8,


    //Number
    NUM_0   = 48,
    NUM_1   = 49,
    NUM_2   = 50,
    NUM_3   = 51,
    NUM_4   = 52,

    // Arrow
    DOWN    = 80,
    RIGHT   = 77,
    LEFT    = 75,
    UP      = 72,


    PGUP    = 73,
    PGDN    = 81,
    
    // System
    F1 = 59,
    F2 = 60,
    F3 = 61,
    F4 = 62,
    F5 = 63,
    F12= 70,

    DEFAULT = -1
};
int keySpecial(int key);
void showCur(bool CursorVisibility);
bool checkKey(int key);