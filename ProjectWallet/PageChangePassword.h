#pragma once
#include "BasePage.h"
#include "ManageAccount.h"

class PageChangePassword:public BasePage
{
private:
	enum StateInputCP
	{
		PASSWORD_OLD	= 0,
		PASSWORD_NEW	= 1,
		PASSWORD_AGAIGN = 2,
		ENTER			= 3,

		EXIT			= -1
	};
	StateInputCP currentFP;

	vector<Text> listText;
	vector<string> listLabel = {
		"Nhap Mat Khau Cu",
		"Nhap Mat Khau Moi",
		"Nhap Lai Mat Khau Moi"
	};

	vector<InputField> listInput;
	Text txtMessage;
public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageChangePassword();
	~PageChangePassword();
};