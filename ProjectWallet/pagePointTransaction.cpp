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
	box(0, 0, 60, 20);

	gotoXY(3, 4);
	cout << "So Diem Du:";

	ManageAccount a;
	AccountModel model = a.FindByUserID(Singleton::getInstance()->UserID);

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

		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();
		listInput[i].display();

		listValidation[i].setPosition(25, posY + 3);
		listValidation[i].setColor(ColorCode_DarkYellow);
		listValidation[i].setContent("LLH");


		posY += 4;
	}

	txtMessage.setPosition(20, posY);
	txtMessage.setColor(ColorCode_DarkRed);

	gotoXY(28, posY + 3);
	cout << "Enter";
	box(26, posY + 2, 8, 2);
}

void PagePointTransaction::handle()
{
	while (true)
	{

	}
}