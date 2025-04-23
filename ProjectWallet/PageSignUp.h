#pragma once
#include "BasePage.h"
#include "ManageAccount.h"

class PageSignUp:public BasePage
{
private:
	enum StateInputSignUp
	{
		LASTNAME = 0,
		FIRSTNAME = 1,
		NUMBERPHONE = 2,
		PASSWORD = 3,
		ENTER = 4,

		EXIT = -1
	};
	StateInputSignUp currentPageSignUp;
	vector<string> listLabel = {
		"Ho",
		"Ten",
		"SDT",
		"Mat Khau"
	};

	vector<Text> listText;
	vector<InputField> listInput;
	Text txtMessage;
	ManageAccount a;

public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageSignUp();
	~PageSignUp();
};
