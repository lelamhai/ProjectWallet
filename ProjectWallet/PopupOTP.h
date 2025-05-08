#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "InputField.h"
#include "Text.h"
#include <iostream>
using namespace std;

class PopupOTP
{
private:
	int posX = 0, posY = 0;
	int width = 30, height = 10;
	int color = ColorCode_DarkBlue;
	InputField inputfield;

public:
	void main();
	void setUI();
	void handle();
	void clean();
	PopupOTP();
	~PopupOTP();
};