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
		ManageTransaction t;
		ManageAccount a;
		PagingData<TransactionModel> page(t.GetAllTransaction(userID), 5);
		auto info = page.getPageInfo(pageNumber);
		vector<TransactionModel> data = info.items;

		int posX = 4;
		int posY = PADDING_TOP + 5;

		int hover = 0;
		int lastHover = -1;
		while (true)
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (pageNumber > 1)
				{
					hover = 0;
					lastHover = -1;
					pageNumber -= 1;

					PagingData<TransactionModel> page(t.GetAllTransaction(userID), 5);
					auto info = page.getPageInfo(pageNumber);
					data = info.items;
					cleanDataUI();
				}
				Sleep(150);
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				PagingData<TransactionModel> page(t.GetAllTransaction(userID), 5);
				int totalPage = page.getTotalPages();
				if (pageNumber < totalPage)
				{
					hover = 0;
					lastHover = -1;
					pageNumber += 1;
					auto info = page.getPageInfo(pageNumber);
					data = info.items;
					cleanDataUI();
				}

				Sleep(150);
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
			{
				nextPage = PageType::PAGE_CUSTOMER;
				return;
			}

			if (hover != lastHover)
			{
				for (int i = 0; i < data.size(); i++)
				{
					setColorText(ColorCode_DarkGreen);
					string status = "Tien Vao";
					if (userID == data[i].getSenderUserID())
					{
						setColorText(ColorCode_DarkRed);
						status = "Tien Ra";
					}

					gotoXY(posX, posY + (2 * i));
					cout << status;

					gotoXY(posX + 15, posY + (2 * i));
					cout << data[i].getPoint();

					gotoXY(posX + 15 + 10, posY + (2 * i));
					cout << data[i].getDatime();

					gotoXY(posX + 15 + 10 + 20, posY + (2 * i));
					cout << a.FindByUserID(data[i].getReceiverUserID()).getNumberPhone();
				}
				lastHover = hover;
				paging();
			}
		}
	}
}

void PageHistoryTransaction::paging()
{
	ManageTransaction t;
	PagingData<TransactionModel> page(t.GetAllTransaction(userID), 5);

	string sPaging = "Trang " + to_string(pageNumber) + '/' + to_string(page.getTotalPages());

	txtPagging.setContent(sPaging);
	txtPagging.display();
}

void PageHistoryTransaction::cleanDataUI()
{
	int posX = 3;
	int posY = PADDING_TOP + 5;

	string blankFill;
	blankFill.resize(60 - 1, ' ');
	for (int i = 0; i < 9; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
}