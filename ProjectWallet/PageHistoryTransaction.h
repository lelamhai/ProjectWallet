#pragma once
#include "BasePage.h"

class PageHistoryTransaction : public BasePage
{
private:
	vector<string> titleGrid = {
		"Trang Thai",
		"So Diem",
		"Thoi Gian",
		"So Dien Thoai"
	};

	vector<Text> listTitle;
	Text txtPagging;
	int pageNumber = 1;
	string search = "";

public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageHistoryTransaction();
	~PageHistoryTransaction();
};