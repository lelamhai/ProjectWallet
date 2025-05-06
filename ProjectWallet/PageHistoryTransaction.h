#pragma once
#include "BasePage.h"
#include "PagingData.h"
#include "ManageTransaction.h"
class PageHistoryTransaction : public BasePage
{
private:
	vector<string> titleGrid = {
		"Trang Thai",
		"Diem",
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
	void paging();
	void cleanDataUI();
	PageHistoryTransaction();
	~PageHistoryTransaction();
};