#pragma once
#include "BasePage.h"
class PageAdmin:public BasePage
{
private:
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
