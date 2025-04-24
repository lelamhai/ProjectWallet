#include "PageForgotPassword.h"

PageForgotPassword::PageForgotPassword()
{
}

PageForgotPassword::~PageForgotPassword()
{
}

void PageForgotPassword::main()
{
	BasePage::setHeader();
	BasePage::setTitlePage("CAP LAI MAT KHAU");
	BasePage::main();
}

void PageForgotPassword::setUI()
{
	box(0, 0, 60, 18);

	int posY = PADDING_TOP + 2;

	for (int i = 0; i < listLabel.size(); i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());

		listText[i].setPosition(10, posY + 1);
		listText[i].setContent(listLabel[i]);
		listText[i].display();

		listInput[i].setInputType(InputType::PASSWORD);
		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();
		listInput[i].setMinLen(9);
		listInput[i].display();

		posY += 3;
	}

	txtMessage.setPosition(20, posY);
	txtMessage.setColor(ColorCode_DarkYellow);

	gotoXY(28, posY + 3);
	cout << "Enter";
	box(26, posY + 2, 8, 2);
}

void PageForgotPassword::handle()
{
	while (true)
	{
		if (currentFP == PASSWORD)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[0].handleInput();

			switch (listInput[0].getEndKey())
			{
			case KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentFP = StateInputFP::ENTER;
					break;
				}

				currentFP = StateInputFP::PASSWORDAGAIGN;
				break;

			case KeyState::UP:
				currentFP = StateInputFP::PASSWORDAGAIGN;
				break;

			case KeyState::DOWN:
				currentFP = StateInputFP::PASSWORDAGAIGN;
				break;

			case KeyState::ESC:
				currentFP = StateInputFP::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentFP == PASSWORDAGAIGN)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[1].handleInput();
			switch (listInput[1].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentFP = StateInputFP::ENTER;
					break;
				}
				currentFP = PASSWORD;
				break;

			case KeyState::UP:
				currentFP = PASSWORD;
				break;

			case KeyState::DOWN:
				currentFP = PASSWORD;
				break;

			case KeyState::ESC:
				currentFP = StateInputFP::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentFP == ENTER)
		{
			if (listInput[0].getText() == listInput[1].getText())
			{

			}
			else {
				txtMessage.clean();
				txtMessage.setColor(ColorCode_DarkRed);
				txtMessage.setContent("Mat khau khong trung nhau.");
			}

			showCur(0);
			txtMessage.display();
			Sleep(5000);
			txtMessage.setColor(ColorCode_DarkYellow);
			currentFP = StateInputFP::PASSWORD;
		}

		if (currentFP == StateInputFP::EXIT)
		{
			nextPage = PageType::PAGE_ADMIN;
			return;
		}
	}
}