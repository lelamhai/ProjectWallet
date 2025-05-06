#include "PageSignIn.h"
PageSignIn::PageSignIn()
{
	userID = -1;
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
	txtTitlePage.setContent("DANG NHAP");
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
	listInput[1].setInputType(InputType::PASSWORD);
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
		if (currentPageLogin == StateInputLogin::USERNAME)
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

				currentPageLogin = StateInputLogin::PASSWORD;
				break;

			case KeyState::UP:
				currentPageLogin = StateInputLogin::PASSWORD;
				break;

			case KeyState::DOWN:
				currentPageLogin = StateInputLogin::PASSWORD;
				break;

			default:
				break;
			}

		}

		if (currentPageLogin == StateInputLogin::PASSWORD)
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
				currentPageLogin = StateInputLogin::USERNAME;
				break;

			case KeyState::UP:
				currentPageLogin = StateInputLogin::USERNAME;
				break;

			case KeyState::DOWN:
				currentPageLogin = StateInputLogin::USERNAME;
				break;

			default:
				break;
			}
		}

		if (currentPageLogin == StateInputLogin::ENTER)
		{
			string username = listInput[0].getText();
			string password = listInput[1].getText();

			if (username == "admin" && password == "admin")
			{
				Singleton::getInstance()->Name = username;
				nextPage = PageType::PAGE_ADMIN;
				listInput[0].clean();
				listInput[1].clean();
				return;
			}
			else {
				AccountModel model = a.SignIn(username, password);
				if (model.getNumberPhone() != "")
				{
					Singleton::getInstance()->UserID = model.getUserID();
					Singleton::getInstance()->Name = model.getFirstName();
					
					if (!model.getIsActive())
					{
						nextPage = PageType::PAGE_CUSTOMER;
						return;
					}
					nextPage = PageType::PAGE_CUSTOMER;
					return;
				}
			}

			txtMessage.clean();
			txtMessage.setColor(ColorCode_DarkRed);
			txtMessage.setContent("Tai khoan khong dung.");

			showCur(0);
			txtMessage.display();
			Sleep(5000);
			txtMessage.setColor(ColorCode_DarkYellow);
			currentPageLogin = StateInputLogin::USERNAME;
		}
	}
}