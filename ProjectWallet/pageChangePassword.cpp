#include "PageChangePassword.h"
PageChangePassword::PageChangePassword()
{
}

PageChangePassword::~PageChangePassword()
{
}

void PageChangePassword::main()
{
	BasePage::header();
	BasePage::setTitlePage("DOI MAT KHAU");
	BasePage::main();
}

void PageChangePassword::setUI()
{
	box(0, 0, 60, 21);

	int posY = PADDING_TOP + 2;

	for (int i = 0; i < listLabel.size(); i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());

		listText[i].setPosition(8, posY + 1);
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

void PageChangePassword::handle()
{
	while (true)
	{
		if (currentFP == StateInputCP::PASSWORD_OLD)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[0].handleInput();

			switch (listInput[0].getEndKey())
			{
			case KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentFP = StateInputCP::ENTER;
					break;
				}

				currentFP = StateInputCP::PASSWORD_NEW;
				break;

			case KeyState::UP:
				currentFP = StateInputCP::PASSWORD_AGAIGN;
				break;

			case KeyState::DOWN:
				currentFP = StateInputCP::PASSWORD_NEW;
				break;

			case KeyState::ESC:
				currentFP = StateInputCP::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentFP == StateInputCP::PASSWORD_NEW)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[1].handleInput();
			switch (listInput[1].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentFP = StateInputCP::ENTER;
					break;
				}
				currentFP = StateInputCP::PASSWORD_AGAIGN;
				break;

			case KeyState::UP:
				currentFP = StateInputCP::PASSWORD_OLD;
				break;

			case KeyState::DOWN:
				currentFP = StateInputCP::PASSWORD_AGAIGN;
				break;

			case KeyState::ESC:
				currentFP = StateInputCP::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentFP == StateInputCP::PASSWORD_AGAIGN)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[2].handleInput();
			switch (listInput[2].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					currentFP = StateInputCP::ENTER;
					break;
				}
				currentFP = StateInputCP::PASSWORD_OLD;
				break;

			case KeyState::UP:
				currentFP = StateInputCP::PASSWORD_NEW;
				break;

			case KeyState::DOWN:
				currentFP = StateInputCP::PASSWORD_OLD;
				break;

			case KeyState::ESC:
				currentFP = StateInputCP::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentFP == StateInputCP::ENTER)
		{
			if (listInput[1].getText() == listInput[2].getText())
			{
				ManageAccount a;

				PopupOTP popup;
				popup.main();
				if (!popup.result)
				{
					currentFP = StateInputCP::PASSWORD_OLD;
					continue;
				}
				bool result = a.ChangePassword(userID, listInput[0].getText(), listInput[1].getText());
				if (result)
				{
					nextPage = PageType::PAGE_SIGNIN;
					return;
				}
				else {
					txtMessage.clean();
					txtMessage.setColor(ColorCode_DarkRed);
					txtMessage.setContent("Mat khau cu khong dung.");
				}
			}
			else {
				txtMessage.clean();
				txtMessage.setColor(ColorCode_DarkRed);
				txtMessage.setContent("Mat khau khong trung nhau.");
			}

			showCur(0);
			txtMessage.display();
			Sleep(DELAY);
			txtMessage.setColor(ColorCode_DarkYellow);
			currentFP = StateInputCP::PASSWORD_OLD;
		}

		if (currentFP == StateInputCP::EXIT)
		{
			nextPage = PageType::PAGE_CUSTOMER;
			return;
		}
	}
}