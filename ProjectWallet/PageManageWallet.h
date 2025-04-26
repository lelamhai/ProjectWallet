#pragma once
#include "BasePage.h"

class PageManageWallet:public BasePage
{
private:
	vector<string> titleGrid = { "Ho Va Ten", "Diem", "So Dien Thoai", "Trang Thai" };
	vector<Text> listTitle;

	vector<string> titleTutorial = { "Phim Nong", "F1: Tim Kiem", "F2: Thao Tac Du Lieu", "F3: Tra Cuu Vi" };
	vector<Text> listTextTutorial;

	Text txtPagging;
	int pageNumber = 1;
	string search = "";

public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageManageWallet();
	~PageManageWallet();
};
