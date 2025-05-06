#include "PageCustomer.h"
PageCustomer::PageCustomer()
{
}

PageCustomer::~PageCustomer()
{
}

void PageCustomer::main()
{
	BasePage::header();
	BasePage::setTitlePage("CHUC NANG");
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
	int hover = 0;
	int lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (hover == 0)
			{
				continue;
			}
			hover--;
			lastHover = -1;
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (hover == menu.size() - 1)
			{
				continue;
			}
			hover++;
			lastHover = -1;
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			nextPage = PageType::PAGE_SIGNIN;
			return;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			switch (hover)
			{
			case PagesOfCustomer::PAGE_PROFILE:

				return;

			case PagesOfCustomer::PAGE_CHANGEPASSWORD:
				nextPage = PageType::PAGE_CHANGEPASSWORD;
				return;

			case PagesOfCustomer::PAGE_HISTORYTRANSACTION:
				nextPage = PageType::PAGE_HISTORYTRANSACTION;
				return;

			case PagesOfCustomer::PAGE_POINTTRANSACTION:
				nextPage = PageType::PAGE_POINTRANSACTION;
				return;

			default:
				break;
			}
		}

		if (hover != lastHover)
		{
			for (int i = 0; i < menu.size(); i++)
			{
				if (hover == i)
				{
					listText[i].setColor(ColorCode_DarkGreen);
					listText[i].clean();
				}
				else {
					listText[i].setColor(ColorCode_White);
				}

				listText[i].setContent(menu[i]);
				listText[i].display();
			}

			lastHover = hover;
		}
	}
}