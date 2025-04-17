#include "PageSignIn.h"
PageSignIn::PageSignIn()
{
}

PageSignIn::~PageSignIn()
{
}

void PageSignIn::main()
{
	BasePage::main();
}

void PageSignIn::setUI()
{
	box(0, 0, 60, 17);
	txtTitlePage.setPosition(25, 2);
	txtTitlePage.setContent("Dang Nhap");
	txtTitlePage.display();

	int posY = 5;

	for (int i = 0; i < 2; i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());

		listText[i].setPosition(18, posY + 1);


		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();
		listInput[i].display();

		posY += 3;
	}

	listText[0].setContent("Tai Khoan");
	listText[0].display();

	listText[1].setContent("Mat Khau");
	listText[1].display();

	txtMessage.setPosition(20, posY);
	txtMessage.setContent("Tai Khoan Khong Dung.");
	txtMessage.setColor(ColorCode_DarkRed);

	gotoXY(28, posY + 3);
	cout << "Enter";
	box(26, posY + 2, 8, 2);
}

void PageSignIn::handle()
{
	while (true)
	{
		if (currentPageLogin == USERNAME)
		{
			listInput[0].handleInput();

			switch (listInput[0].getEndKey())
			{
			case KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentPageLogin = StateInputLogin::ENTER;
					break;
				}

				currentPageLogin = PASSWORD;
				break;

			case KeyState::UP:
				currentPageLogin = PASSWORD;
				break;

			case KeyState::DOWN:
				currentPageLogin = PASSWORD;
				break;

			default:
				break;
			}

		}

		if (currentPageLogin == PASSWORD)
		{
			listInput[1].handleInput();

			switch (listInput[1].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentPageLogin = StateInputLogin::ENTER;
					break;
				}
				currentPageLogin = USERNAME;
				break;

			case KeyState::UP:
				currentPageLogin = USERNAME;
				break;

			case KeyState::DOWN:
				currentPageLogin = USERNAME;
				break;

			default:
				break;
			}
		}

		if (currentPageLogin == ENTER)
		{
			Singleton::getInstance()->Name = "LLH";
			nextPage = PageType::PAGE_CUSTOMER;
			return;
		}
	}
}