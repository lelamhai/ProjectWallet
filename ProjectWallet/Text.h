#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Text
{
private:
	int x = 0, y = 0;
	int color = 15;
	string content;

public:
	void setPosition(int posX, int posY);
	void updatePositionX(int posX);
	void updatePositionY(int posY);
	void setContent(string newContent);
	int getLenString();
	void setColor(int color);
	void display();
	void clean();
	Text();
	~Text();
};