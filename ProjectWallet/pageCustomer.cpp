#include "PageCustomer.h"
PageCustomer::PageCustomer()
{
}

PageCustomer::~PageCustomer()
{
}

void PageCustomer::main()
{
	BasePage::setUIInfo();
	BasePage::main();
}

void PageCustomer::setUI()
{
	box(0, 0, 60, 20);

	int posY = PADDING_TOP + 2;
	for (int i = 0; i < menu.size(); i++)
	{
		listText.push_back(Text());
		listText[i].setPosition(25, posY + 1);


		posY += 2;
	}
}

void PageCustomer::handle()
{
	while (true)
	{
		_getch();
	}
}