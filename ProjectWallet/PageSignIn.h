#pragma once
#include "BasePage.h"
#include "ManageAccount.h"

class PageSignIn:public BasePage
{
private:
	enum StateInputLogin
	{
		USERNAME = 0,
		PASSWORD = 1,
		ENTER = 2,

		EXIT = -1
	};
	StateInputLogin currentPageLogin;

	vector<Text> listText;
	vector<InputField> listInput;
	Text txtMessage;
	ManageAccount a;

public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageSignIn();
	~PageSignIn();
};