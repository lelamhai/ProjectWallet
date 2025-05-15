#pragma once
#include "BasePage.h"
#include "ManageAccount.h"
#include "ManageTransaction.h"
#include "PopupOTP.h"

class PagePointTransaction : public BasePage
{
private:
	enum StateInputTransaction
	{
		NUMBERPHONE = 0,
		POINT		= 1,
		ENTER		= 2,

		EXIT		= -1
	};
	StateInputTransaction currentPageTransaction;

	vector<string> listTitle = {
		"SDT.Nguoi Nhan",
		"Nhap So Diem"
	};

	Text txtPoint;
	vector<InputField> listInput;
	vector<Text> listText;
	vector<Text> listValidation;
	Text txtMessage;

public:
	void main() override;
	void setUI() override;
	void handle() override;
	void cleanInput();
	PagePointTransaction();
	~PagePointTransaction();
};