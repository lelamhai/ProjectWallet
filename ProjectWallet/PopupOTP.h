#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "InputField.h"
#include "Text.h"
#include "otpService.h"
#include <iostream>
using namespace std;

class PopupOTP
{
private:
	OtpService otp;
	int posX = 65, posY = 0;
	int width = 30, height = 10;
	int color = ColorCode_DarkBlue;
	InputField inputfield;
	Text txtMessage;

public:
	bool result;
	void main();
	void setUI();
	void handle();
	void clean();
	PopupOTP();
	~PopupOTP();
};