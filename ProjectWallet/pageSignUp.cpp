#include "PageSignUp.h"
PageSignUp::PageSignUp()
{
}

PageSignUp::~PageSignUp()
{
}

void PageSignUp::main()
{
	BasePage::setHeader();
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

	txtMessage.setPosition(20, posY);
	txtMessage.setContent("Tai Khoan Khong Dung.");
	txtMessage.setColor(ColorCode_DarkRed);

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
				bool result = a.SignUp(last, name, phone, pass);
				if (result)
				{
					currentPageSignUp = StateInputSignUp::LASTNAME;
				}
				else {
					txtMessage.display();
				}
			}
		}

		if (currentPageSignUp == StateInputSignUp::EXIT)
		{
			nextPage = PageType::PAGE_ADMIN;
			return;
		}
	}
}