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

	box(posX + 4, posY + 1, WIDTH_INPUT+1, HEIGHT_INPUT);
	inputfield.setInputType(InputType::NUMBER);
	inputfield.setPosition(posX+4, posY+1);
	inputfield.setMaxLen(5);
	inputfield.display();

	textbk(color);
	box(posX + 4, posY + 5, 6, 2);
	gotoXY(posX + 2 + 4, posY + 6);
	cout << "ESC";

	textbk(color);
	box(posX + 4 + 13, posY + 5, 8, 2);
	gotoXY(posX + 8 + 11, posY + 6);
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
		case KeyState::ENTER: {
			OTPStatus status = otp.checkOTPStatus(inputfield.getText());

			if (status == OTPStatus::VALID) {
				clean();
				result = true;
				return;
			}

			setColorText(ColorCode_DarkRed);
			textbk(color);
			gotoXY(posX, posY + 4);

			const char* message =
				(status == OTPStatus::EXPIRED) ? "Ma OTP dung nhung da het han."
				: "Ma OTP khong hop le.";
			cout << "      " << message;

			setColorText(ColorCode_DarkWhite);
			break;
		}

		
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