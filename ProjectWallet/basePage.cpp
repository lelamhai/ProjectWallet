#include "BasePage.h"
BasePage::BasePage()
{
	name = "Xin Chao " + Singleton::getInstance()->Name + "!";
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

void BasePage::setHeader()
{
	setUIButtonBack();
	setUISayHi();
}

void BasePage::setUIButtonBack()
{
	inputBack.setPosition(2, 1);
	inputBack.setFrame(15, 2);
	inputBack.setText(" ESC: Tro Lai");
	inputBack.drawBox();
	inputBack.display();
}

void BasePage::setUISayHi()
{
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