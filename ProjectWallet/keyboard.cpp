#include "mykeyboard.h"
int keySpecial(int key)
{
    if (_kbhit()) //true
    {
        key = _getch();
        if (key == 224)
        {
            key = _getch();
            return key + 1000;
        }
        return key;
    }
    return DEFAULT;
}

void showCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}

bool checkKey(int key) 
{
    return GetAsyncKeyState(key);
}