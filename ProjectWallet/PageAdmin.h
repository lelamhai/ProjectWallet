#pragma once
#include "BasePage.h"
class PageAdmin:public BasePage
{
private:
	enum PagesOfAdmin
	{
		PAGE_LISTACCOUNT	= 0,
		PAGE_CREATEACCOUNT	= 1,
		PAGE_LISTWALLET		= 2
	};

	vector<string> menu = {
		"DS.Tai Khoan",
		"Them Tai Khoan"
	};
	vector<Text> listText;

public:
	void main() override;
	void setUI() override;
	void handle() override;

	PageAdmin();
	~PageAdmin();
};
