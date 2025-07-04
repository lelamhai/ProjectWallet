#include "PagePointTransaction.h"

PagePointTransaction::PagePointTransaction()
{
}

PagePointTransaction::~PagePointTransaction()
{
}

void PagePointTransaction::main()
{
	BasePage::header();
	BasePage::setTitlePage("GIAO DICH");
	BasePage::main();
}

void PagePointTransaction::setUI()
{
	OtpService otp;
	box(0, 0, 60, 20);

	gotoXY(3, 4);
	cout << "So Diem Du:";

	ManageAccount a;
	AccountModel model = a.FindByUserID(userID);

	txtPoint.setColor(ColorCode_DarkGreen);
	txtPoint.setPosition(3 + 12, 4);
	txtPoint.setContent(to_string(model.getPoint()));
	txtPoint.display();

	int posY = PADDING_TOP + 2;

	for (int i = 0; i < listTitle.size(); i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());
		listValidation.push_back(Text());

		listText[i].setPosition(14, posY + 1);
		listText[i].setContent(listTitle[i]);
		listText[i].display();

		listInput[i].setInputType(InputType::NUMBER);
		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();
		listInput[i].display();

		listValidation[i].setPosition(25, posY + 3);
		listValidation[i].setColor(ColorCode_DarkYellow);

		posY += 4;
	}
	listInput[0].setMinLen(9);

	listInput[1].setMinLen(1);
	listInput[1].setMaxLen(8);
	listValidation[1].setPosition(20, posY - 1);


	txtMessage.setPosition(20, posY);
	txtMessage.setColor(ColorCode_DarkYellow);

	gotoXY(28, posY + 2);
	cout << "Enter";
	box(26, posY + 1, 8, 2);
}

void PagePointTransaction::handle()
{
	while (true)
	{
		if (currentPageTransaction == StateInputTransaction::NUMBERPHONE)
		{
			ManageTransaction t;
			ManageAccount a;

			txtMessage.clean();
			txtMessage.setContent("Vui long nhap hon 9 ky tu.");
			txtMessage.display();
			listInput[0].handleInput();
			listValidation[0].clean();
			listValidation[0].setColor(ColorCode_DarkYellow);

			if (userID != a.FindByPhone(listInput[0].getText()).getUserID())
			{
				if (t.GetFullNameByPhone(listInput[0].getText()) != "")
				{
					listValidation[0].setColor(ColorCode_DarkGreen);
					listValidation[0].setContent(t.GetFullNameByPhone(listInput[0].getText()));
					listValidation[0].display();
				}
				else {
					listValidation[0].setContent("SDT.khong ton tai.");
					listValidation[0].display();
				}
			}
			else {
				listValidation[0].setContent("Khong hop le.");
				listValidation[0].display();
			}


			switch (listInput[0].getEndKey())
			{
			case  KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentPageTransaction = StateInputTransaction::ENTER;
					break;
				}
				currentPageTransaction = StateInputTransaction::POINT;
				break;

			case KeyState::UP:
				currentPageTransaction = StateInputTransaction::POINT;
				break;

			case KeyState::DOWN:
				currentPageTransaction = POINT;
				break;

			case KeyState::ESC:
				currentPageTransaction = StateInputTransaction::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageTransaction == StateInputTransaction::POINT)
		{
			txtMessage.clean();
			txtMessage.setContent("Vui long khong bo trong.");
			txtMessage.display();
			listInput[1].handleInput();
			listValidation[1].clean();

			if (listInput[1].getText() != "")
			{
				int point = stoi(listInput[1].getText());
				if (point <= 0)
				{
					listValidation[1].setContent("So diem phai lon hon 0");
					listValidation[1].display();
				}
			}

			switch (listInput[1].getEndKey())
			{
			case KeyState::ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					currentPageTransaction = StateInputTransaction::ENTER;
					break;
				}

				currentPageTransaction = StateInputTransaction::NUMBERPHONE;
				break;

			case KeyState::UP:
				currentPageTransaction = StateInputTransaction::NUMBERPHONE;
				break;

			case KeyState::DOWN:
				currentPageTransaction = StateInputTransaction::NUMBERPHONE;
				break;

			case KeyState::ESC:
				currentPageTransaction = StateInputTransaction::EXIT;
				break;

			default:
				break;
			}
		}

		if (currentPageTransaction == StateInputTransaction::ENTER)
		{
			ManageTransaction t;
			ManageAccount a;

			if (a.FindByPhone(listInput[0].getText()).getNumberPhone() == "" || a.FindByPhone(listInput[0].getText()).getUserID() == userID)
			{
				txtMessage.setColor(ColorCode_DarkRed);
				txtMessage.clean();
				txtMessage.setContent("   SDT.khong hop le.");
				txtMessage.display();

				showCur(0);
				txtMessage.display();
				Sleep(DELAY);
				txtMessage.setColor(ColorCode_DarkYellow);

				currentPageTransaction = StateInputTransaction::NUMBERPHONE;
				continue;
			}

			if (stoi(listInput[1].getText()) > MAX_POINT)
			{
				txtMessage.setColor(ColorCode_DarkRed);
				txtMessage.clean();
				txtMessage.setContent("So diem qua lon.");
				txtMessage.display();

				showCur(0);
				txtMessage.display();
				Sleep(DELAY);
				txtMessage.setColor(ColorCode_DarkYellow);

				currentPageTransaction = StateInputTransaction::POINT;
				continue;
			}

			if (!t.CheckPointOfWallet(userID, stoi(listInput[1].getText())))
			{
				txtMessage.setColor(ColorCode_DarkRed);
				txtMessage.clean();
				txtMessage.setContent("So diem chuyen khong du.");
				txtMessage.display();

				showCur(0);
				txtMessage.display();
				Sleep(DELAY);
				txtMessage.setColor(ColorCode_DarkYellow);

				currentPageTransaction = StateInputTransaction::POINT;
				continue;
			}
			PopupOTP popup;
			popup.main();
			if (!popup.result)
			{
				currentPageTransaction = StateInputTransaction::NUMBERPHONE;
				continue;
			}

			t.TransactionPoint(userID, listInput[0].getText(), stoi(listInput[1].getText()));
			ManageAccount update;
			AccountModel model = update.FindByUserID(userID);
			txtPoint.clean();
			txtPoint.setContent(to_string(model.getPoint()));
			txtPoint.display();

			txtMessage.clean();
			txtMessage.setColor(ColorCode_DarkGreen);
			txtMessage.setContent("Chuyen diem thanh cong.");
			cleanInput();

			showCur(0);
			txtMessage.display();
			Sleep(DELAY);
			txtMessage.setColor(ColorCode_DarkYellow);

			currentPageTransaction = StateInputTransaction::NUMBERPHONE;
		}

		if (currentPageTransaction == StateInputTransaction::EXIT)
		{
			nextPage = PageType::PAGE_CUSTOMER;
			return;
		}
	}
}

void PagePointTransaction::cleanInput()
{
	for (int i = 0; i < listInput.size(); i++)
	{
		listValidation[i].clean();
		listInput[i].clean();
	}
}