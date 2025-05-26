#pragma once
#include "BasePage.h"

class PageCustomer:public BasePage
{
private:
	enum PagesOfCustomer
	{
		PAGE_PROFILE			= 0,
		PAGE_CHANGEPASSWORD		= 1,
		PAGE_HISTORYTRANSACTION = 2,
		PAGE_POINTTRANSACTION	= 3,
		PAGE_SETUPOTP			= 4
	};

	vector<string> menu = {
		"Thong Tin",
		"Doi Mat Khau",
		"Xem Giao Dich",
		"Chuyen Diem",
		"Cai dat OTP"
	};

	vector<Text> listText;
public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageCustomer();
	~PageCustomer();
};

