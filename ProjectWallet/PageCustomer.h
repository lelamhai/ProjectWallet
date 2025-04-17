#pragma once
#include "BasePage.h"

class PageCustomer:public BasePage
{
private:
	vector<string> menu = {
		"Thong Tin",
		"Doi Mat Khau",
		"Xem Vi",
		"Chuyen Diem"
	};

	vector<Text> listText;
public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageCustomer();
	~PageCustomer();
};

