#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

#define LENGTH_MIN 1
#define LENGTH_CODE 7
#define WIDTH_INPUT 20
#define HEIGHT_INPUT 2
#define LENGTH_INPUT 15

enum class InputType {
	TEXT,
	NUMBER,
	PASSWORD,
	EMAIL
};

class InputField
{
private:
	InputType inputType = InputType::TEXT;

	int x, y;
	int w= WIDTH_INPUT, h = HEIGHT_INPUT;
	int maxLen = 13;
	int minLen = 0;
	string inputString;
	KeyState keyInput;
	int cursorPosition = 0;

public:
	void setInputType(InputType type);
	void setMaxLen(int length);
	void setMinLen(int length);
	void setPosition(int posX, int posY);
	void setFrame(int width, int height);
	void focus();
	void drawBox();
	string getText();
	void setText(string value);
	void handleInput();
	void display();
	KeyState getEndKey();
	void clean();
	
	InputField();
	~InputField();
};