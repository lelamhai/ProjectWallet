#include "PopupOTP.h"

PopupOTP::PopupOTP()
{
}

PopupOTP::~PopupOTP()
{
}

void PopupOTP::main()
{
	setUI();
	handle();
}

void PopupOTP::setUI()
{
	setColorText(color);
	drawColorBg(width, height, posX, posY);

	setColorText(ColorCode_White);
	textbk(color);

	textbk(color);
	gotoXY(posX + 8, posY + 1);
	cout << "Ma OTP: 111111";


	box(posX + 4, posY + 2, WIDTH_INPUT+1, HEIGHT_INPUT);
	inputfield.setPosition(posX+4, posY+2);
	inputfield.display();

	textbk(color);
	box(posX + 4, posY + 6, 8, 2);
	gotoXY(posX + 2 + 4, posY + 7);
	cout << "Thoat";

	textbk(color);
	box(posX + 4 + 10, posY + 6, 11, 2);
	gotoXY(posX + 6 + 10, posY + 7);
	cout << "Xac Nhan";
}

void PopupOTP::handle()
{
	showCur(1);
	while (true)
	{
		inputfield.handleInput();
	}
}

void PopupOTP::clean()
{
	setColorText(ColorCode_Back);
	string blankFill;
	blankFill.resize(width, char(219));
	for (int i = 0; i < height; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
	setColorText(ColorCode_White);
}