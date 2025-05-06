#include "PageHistoryTransaction.h"


PageHistoryTransaction::PageHistoryTransaction()
{
}

PageHistoryTransaction::~PageHistoryTransaction()
{
}

void PageHistoryTransaction::main()
{
	BasePage::header();
	BasePage::setTitlePage("LICH SU GIAO DICH");
	BasePage::main();
}

void PageHistoryTransaction::setUI()
{
	box(0, 0, 64, 21);
	box(2, PADDING_TOP + 2, 60, 12);
	lineX(2, PADDING_TOP + 4, 60);
	gotoXY(2, PADDING_TOP + 4);
	cout << char(195);
	gotoXY(60 + 2, PADDING_TOP + 4);
	cout << char(180);


	// Column Left
	int posX = 4;
	for (int i = 0; i < titleGrid.size(); i++)
	{
		listTitle.push_back(Text());
		listTitle[i].setPosition(posX, PADDING_TOP + 3);
		listTitle[i].setContent(titleGrid[i]);
		listTitle[i].display();
		if (i == 0)
		{
			posX += 15;
		}

		if (i == 1)
		{
			posX += 10;
		}

		if (i == 2)
		{
			posX += 20;
		}
	}

	txtPagging.setPosition(60 - 6, 20);
}

void PageHistoryTransaction::handle()
{
	while (true)
	{

	}
}