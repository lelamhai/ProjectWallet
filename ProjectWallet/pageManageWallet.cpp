#include "PageManageWallet.h"

PageManageWallet::PageManageWallet()
{
}

PageManageWallet::~PageManageWallet()
{
}

void PageManageWallet::main()
{
	BasePage::setUIButtonBack();

	txtSayHi.setContent(name);
	txtSayHi.setPosition(90 - 18, 2);
	txtSayHi.display();

	BasePage::setTitlePage("TRA CUU VI");
	BasePage::main();
}

void PageManageWallet::setUI()
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

		if (i == 1)
		{
			posX += 10;
		}
		else {
			posX += 15;
		}
	}

	//
	txtPagging.setPosition(60 - 6, 20);
}

void PageManageWallet::handle()
{
	while (true)
	{
		if (currentFunction == Function::SELECT)
		{
			showCur(false);
			selectData();
		}

		if (currentFunction == Function::SEARCH)
		{
			showCur(true);
			searchData();
		}

		if (currentFunction == Function::USERTRANSACTION)
		{
			nextPage = PageType::PAGE_USERTRANSACTION;
			return;
		}

		if (currentFunction == Function::BACK)
		{
			nextPage = PageType::PAGE_ADMIN;
			return;
		}
	}
}
void PageManageWallet::selectData()
{
	PagingData<AccountModel> page(a.LoadAccount(search), 5);
	auto info = page.getPageInfo(pageNumber);
	vector<AccountModel> data = info.items;

	int posX = 4;
	int posY = PADDING_TOP + 5;

	int hover = 0;
	int lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			currentFunction = Function::BACK;
			return;
		}

		if (GetAsyncKeyState(VK_F1) & 0x8000)
		{
			currentFunction = Function::SEARCH;
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x8000)
		{
			currentFunction = Function::USERTRANSACTION;
			return;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (0 < hover)
			{
				hover -= 1;
			}
			else {
				hover = 0;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (data.size() - 1 > hover)
			{
				hover += 1;
			}
			else {
				hover = data.size() - 1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (pageNumber > 1)
			{
				hover = 0;
				lastHover = -1;
				pageNumber -= 1;

				PagingData<AccountModel> page(a.LoadAccount(search), 5);
				auto info = page.getPageInfo(pageNumber);
				data = info.items;
				cleanDataUI();
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			PagingData<AccountModel> page(a.LoadAccount(search), 5);
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

		if (hover != lastHover)
		{
			for (int i = 0; i < data.size(); i++)
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
					userID = data[i].getUserID();
				}

				string full = data[i].getLastName() + " " + data[i].getFirstName();

				gotoXY(posX, posY + (2 * i));
				cout << full;

				gotoXY(posX + 15, posY + (2 * i));
				cout << data[i].getPoint();

				gotoXY(posX + 15 + 10, posY + (2 * i));
				cout << data[i].getNumberPhone();

				gotoXY(posX + 15 + 10 + 15, posY + (2 * i));

				string active = "Chua Dang Nhap";
				if (data[i].getIsActive())
				{
					active = "Dang Nhap";
				}
				cout << active;
			}
			paging();
			lastHover = hover;
		}
	}
}

void PageManageWallet::searchData()
{
	int cursorPosition = search.length();
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			currentFunction = BACK;
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x8000)
		{
			currentFunction = Function::SELECT;
			return;
		}

		gotoXY(69 + cursorPosition, PADDING_TOP);
		char s = _getch();
		int key = keySpecial(s);
		switch (s)
		{
		case BACKSPACE:
			if (search.length() <= 0 || cursorPosition <= 0)
			{
				break;
			}

			if (cursorPosition == search.length())
			{
				search.erase(search.length() - 1, 1);
				cursorPosition--;
				cout << "\b \b";
			}
			else {
				search.erase(--cursorPosition, 1);
				gotoXY(whereX() - 1, whereY());
				for (int i = cursorPosition; i < search.length(); i++)
				{
					cout << search[i];
				}
				gotoXY(whereX(), whereY());
				cout << " ";
				gotoXY(whereX() - 1 - (search.length() - cursorPosition), whereY());
			}
			cleanDataUI();
			loadData();
			paging();
			break;

		default:
			if (search.length() > 14)
			{
				break;
			}

			if (s >= 32 && s <= 126)
			{
				search.insert(search.begin() + cursorPosition, s);
				cursorPosition++;
				cout << s;

				if (cursorPosition != search.length())
				{
					for (int i = cursorPosition; i <= search.length(); i++)
					{
						cout << search[i];
					}
					gotoXY(whereX() - (search.length() - cursorPosition), whereY());
				}
				cleanDataUI();
				loadData();
				paging();
			}

			break;
		}
	}
}
void PageManageWallet::loadData()
{
	PagingData<AccountModel> page(a.LoadAccount(search), 5);
	auto info = page.getPageInfo(pageNumber);
	vector<AccountModel> data = info.items;

	int posX = 4;
	int posY = PADDING_TOP + 5;

	int hover = 0;
	for (int i = 0; i < data.size(); i++)
	{
		string full = data[i].getLastName() + " " + data[i].getFirstName();

		gotoXY(posX, posY + (2 * i));
		cout << full;

		gotoXY(posX + 15, posY + (2 * i));
		cout << data[i].getPoint();

		gotoXY(posX + 10 + 15, posY + (2 * i));
		cout << data[i].getNumberPhone();

		gotoXY(posX + 10 + 15 + 15, posY + (2 * i));

		string active = "Chua Dang Nhap";
		if (data[i].getIsActive())
		{
			active = "Dang Nhap";
		}
		cout << active;
	}
}

void PageManageWallet::paging()
{
	PagingData<AccountModel> page(a.LoadAccount(search), 5);

	string sPaging = "Trang " + to_string(pageNumber) + '/' + to_string(page.getTotalPages());

	txtPagging.setContent(sPaging);
	txtPagging.display();
}

void PageManageWallet::cleanDataUI()
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