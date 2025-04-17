#include "BasePage.h"
BasePage::BasePage()
{
}

BasePage::~BasePage()
{
}

void BasePage::setTitle(string text)
{
	this->title = text;
}

void BasePage::setSayHi(string name)
{
	this->name = name;
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
	txtTitle.setPosition(25, PADDING_TOP);
	txtTitle.setContent(title);
	txtTitle.display();

}

void BasePage::handle()
{

}

void BasePage::clean()
{
	clrscr();
}