#pragma once
#include "BasePage.h"
#include "ManageAccount.h"

class PageProfile : public BasePage
{
private:
	vector<string> listLabel = {
		"Ho",
		"Ten",
		"SDT",
		"Mat Khau"
	};
	vector<Text> listText;
	vector<InputField> listInput;

public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageProfile();
	~PageProfile();
};