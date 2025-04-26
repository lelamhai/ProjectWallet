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

	}
}