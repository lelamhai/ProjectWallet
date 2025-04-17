#include "BasePage.h"
BasePage::BasePage()
{
}

BasePage::~BasePage()
{
}

PageType BasePage::getNextPage()
{
	return nextPage;
}

void BasePage::setTitlePage(string text)
{
	this->title = text;
	txtTitlePage.setPosition(25, PADDING_TOP);
	txtTitlePage.setContent(title);
	txtTitlePage.display();
}

void BasePage::main()
{
	setUI();
	handle();
	clean();
}

void BasePage::setUIInfo()
{
	name = "Xin Chao " + Singleton::getInstance()->Name + "!";
	inputBack.setPosition(2, 1);
	inputBack.setFrame(15, 2);
	inputBack.setText(" ESC: Tro Lai");
	inputBack.drawBox();
	inputBack.display();

	txtSayHi.setPosition(40, 2);
	txtSayHi.setContent(name);
	txtSayHi.display();
}

void BasePage::setUI()
{
	txtTitlePage.setPosition(25, PADDING_TOP);
	txtTitlePage.setContent(title);
	txtTitlePage.display();
}

void BasePage::handle()
{

}

void BasePage::clean()
{
	clrscr();
}