#pragma once
#include "BasePage.h"
#include "ManageAccount.h"

class PageForgotPassword:public BasePage
{
private:
	enum StateInputFP
	{
		PASSWORD		= 0,
		PASSWORDAGAIGN	= 1,
		ENTER			= 2,

		EXIT			= -1
	};
	StateInputFP currentFP;

	vector<Text> listText;
	vector<string> listLabel = {
		"Mat Khau Moi",
		"Nhap Lai Mat Khau"
	};

	int userID;
	vector<InputField> listInput;
	Text txtMessage;

public:
	void main() override;
	void setUI() override;
	void handle() override;
	void cleanInput();
	PageForgotPassword();
	~PageForgotPassword();
};
