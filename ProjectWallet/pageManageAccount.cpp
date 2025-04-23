#include "PageManageAccount.h"

PageManageAccount::PageManageAccount()
{

}

PageManageAccount::~PageManageAccount()
{

}

void PageManageAccount::main()
{
	BasePage::setUIButtonBack();

	txtSayHi.setContent(name);
	txtSayHi.setPosition(90 - 18, 2);
	txtSayHi.display();

	BasePage::setTitlePage("QL.Tai Khoan");
	BasePage::main();

}

void PageManageAccount::setUI()
{
	box(0, 0, 90, 21);
	box(2, PADDING_TOP + 2, 60, 12);
	lineX(2, PADDING_TOP + 4, 60);
	gotoXY(2, PADDING_TOP + 4);
	cout << char(195);
	gotoXY(60 + 2, PADDING_TOP + 4);
	cout << char(180);

	// Column Right 
	gotoXY(64, PADDING_TOP);
	cout << "Tim";
	box(68, PADDING_TOP - 1, WIDTH_INPUT, HEIGHT_INPUT);
	//
	int tutorialY = PADDING_TOP + 3;
	for (int i = 0; i < titleTutorial.size(); i++)
	{
		listTextTutorial.push_back(Text());

		if (i == 0)
		{
			listTextTutorial[i].setColor(ColorCode_DarkYellow);
			listTextTutorial[i].setPosition(64 + 10, tutorialY);
		}
		else {
			listTextTutorial[i].setColor(ColorCode_DarkWhite);
			listTextTutorial[i].setPosition(64 + 2, tutorialY);
		}

		listTextTutorial[i].setContent(titleTutorial[i]);
		listTextTutorial[i].display();

		tutorialY += 2;
	}


	// Column Left
	int posX = 4;
	for (int i = 0; i < titleGrid.size(); i++)
	{
		listTitle.push_back(Text());
		listTitle[i].setPosition(posX, PADDING_TOP + 3);
		listTitle[i].setContent(titleGrid[i]);
		listTitle[i].display();
		posX += 15;
	}

	//
	txtPagging.setPosition(60 - 6, 20);
}

void PageManageAccount::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			nextPage = PageType::PAGE_ADMIN;
			return;
		}
	}
}