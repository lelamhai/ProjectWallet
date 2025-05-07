#include "PageSignUp.h"
PageSignUp::PageSignUp()
{
}

PageSignUp::~PageSignUp()
{
}

void PageSignUp::main()
{
	BasePage::header();
	BasePage::setTitlePage("DANG KY");
	BasePage::main();
}

void PageSignUp::setUI()
{
	box(0, 0, 60, 25);

	int posY = PADDING_TOP + 2;

	for (int i = 0; i < 4; i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());

		listText[i].setPosition(20, posY + 1);
		listText[i].setContent(listLabel[i]);
		listText[i].display();

		
		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();
		listInput[i].display();

		posY += 3;
	}
	listInput[2].setInputType(InputType::NUMBER);
	listInput[3].setInputType(InputType::PASSWORD);


	txtMessage.setPosition(20, posY);
	txtMessage.setContent("Vui long nhap hon 6 ky tu.");
	txtMessage.setColor(ColorCode_DarkYellow);

	gotoXY(28, posY + 3);
	cout << "Enter";
	box(26, posY + 2, 8, 2);
}

void PageSignUp::handle()
{
	while (true)
	{
		if (currentPageSignUp == LASTNAME)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long khong bo trong.");
			txtMessage.display();
			listInput[0].setMinLen(1);
			listInput[0].handleInput();
			switch (listInput[0].getEndKey())
			{
			case KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentPageSignUp = StateInputSignUp::ENTER;
					break;
				}

				currentPageSignUp = StateInputSignUp::FIRSTNAME;
				break;

			case KeyState::UP:
				currentPageSignUp = StateInputSignUp::PASSWORD;
				break;

			case KeyState::DOWN:
				currentPageSignUp = StateInputSignUp::FIRSTNAME;
				break;

			case KeyState::ESC:
				currentPageSignUp = StateInputSignUp::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageSignUp == FIRSTNAME)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long khong bo trong.");
			txtMessage.display();
			listInput[1].setMinLen(1);
			listInput[1].handleInput();
			switch (listInput[1].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentPageSignUp = StateInputSignUp::ENTER;
					break;
				}
				currentPageSignUp = StateInputSignUp::NUMBERPHONE;
				break;

			case KeyState::UP:
				currentPageSignUp = StateInputSignUp::LASTNAME;
				break;

			case KeyState::DOWN:
				currentPageSignUp = StateInputSignUp::NUMBERPHONE;
				break;

			case KeyState::ESC:
				currentPageSignUp = StateInputSignUp::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageSignUp == NUMBERPHONE)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[2].setMinLen(9);
			listInput[2].handleInput();
			switch (listInput[2].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentPageSignUp = StateInputSignUp::ENTER;
					break;
				}
				currentPageSignUp = StateInputSignUp::PASSWORD;
				break;

			case KeyState::UP:
				currentPageSignUp = StateInputSignUp::FIRSTNAME;
				break;

			case KeyState::DOWN:
				currentPageSignUp = StateInputSignUp::PASSWORD;
				break;

			case KeyState::ESC:
				currentPageSignUp = StateInputSignUp::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageSignUp == PASSWORD)
		{
			txtMessage.clean();
			txtMessage.setContent("   Co the bo trong.");
			txtMessage.display();
			listInput[3].handleInput();
			switch (listInput[3].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentPageSignUp = StateInputSignUp::ENTER;
					break;
				}
				currentPageSignUp = StateInputSignUp::LASTNAME;
				break;

			case KeyState::UP:
				currentPageSignUp = StateInputSignUp::NUMBERPHONE;
				break;

			case KeyState::DOWN:
				currentPageSignUp = StateInputSignUp::LASTNAME;
				break;

			case KeyState::ESC:
				currentPageSignUp = StateInputSignUp::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageSignUp == StateInputSignUp::ENTER)
		{
			string last = listInput[0].getText();
			string name = listInput[1].getText();
			string phone = listInput[2].getText();
			string pass = listInput[3].getText();

			if (last != "" && name != "" && phone != "")
			{
				ManageAccount a;
				bool result = a.SignUp(last, name, phone, pass);
				if (result)
				{
					txtMessage.clean();
					txtMessage.setColor(ColorCode_DarkGreen);
					txtMessage.setContent("Dang ky tai khoan thanh cong.");
					cleanInput();
				}
				else {
					txtMessage.clean();
					txtMessage.setColor(ColorCode_DarkRed);
					txtMessage.setContent("SDT da ton tai trong he thong.");
				}

				showCur(0);
				txtMessage.display();
				Sleep(DELAY);
				txtMessage.setColor(ColorCode_DarkYellow);
				currentPageSignUp = StateInputSignUp::LASTNAME;
			}
		}

		if (currentPageSignUp == StateInputSignUp::EXIT)
		{
			nextPage = PageType::PAGE_ADMIN;
			return;
		}
	}
}

void PageSignUp::cleanInput()
{
	for (int i = 0; i < listInput.size(); i++)
	{
		listInput[i].clean();
	}
}