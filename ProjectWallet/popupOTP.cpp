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
	cout << "Ma OTP:" + otp.generateCurrentOTP();

	box(posX + 4, posY + 2, WIDTH_INPUT+1, HEIGHT_INPUT);
	inputfield.setInputType(InputType::NUMBER);
	inputfield.setPosition(posX+4, posY+2);
	inputfield.setMaxLen(5);
	inputfield.display();

	textbk(color);
	box(posX + 4, posY + 6, 6, 2);
	gotoXY(posX + 2 + 4, posY + 7);
	cout << "ESC";

	textbk(color);
	box(posX + 4 + 13, posY + 6, 8, 2);
	gotoXY(posX + 8 + 11, posY + 7);
	cout << "ENTER";
}

void PopupOTP::handle()
{
	showCur(1);
	while (true)
	{
		inputfield.handleInput();
		switch (inputfield.getEndKey())
		{
		case  KeyState::ENTER:
			if (otp.verifyOTP(inputfield.getText()))
			{
				clean();
				result = true;
				return;
			}
			else {
				setColorText(ColorCode_DarkRed);
				textbk(color);
				gotoXY(posX, posY + 5);
				cout << "      OTP khong hop le.";
				setColorText(ColorCode_DarkWhite);
			}
			break;
		
		case KeyState::ESC:
			result = false;
			clean();
			return;

		default:
			break;
		}
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