#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

enum ColorState {
	ColorCode_Back			= 0,
	ColorCode_DarkBlue		= 1,
	ColorCode_DarkGreen		= 2,
	ColorCode_DarkCyan		= 3,
	ColorCode_DarkRed		= 4,
	ColorCode_DarkPink		= 5,
	ColorCode_DarkYellow	= 6,
	ColorCode_DarkWhite		= 7,
	ColorCode_Grey			= 8,
	ColorCode_Blue			= 9,
	ColorCode_Green			= 10,
	ColorCode_Cyan			= 11,
	ColorCode_Red			= 12,
	ColorCode_Pink			= 13,
	ColorCode_Yellow		= 14,
	ColorCode_White			= 7//15
};

void setColorText(int ColorState);
void setDefualtBT();
void drawColorBg(int width, int height, int x, int y);
void textbk(WORD color);