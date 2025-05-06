#pragma once
#include "BasePage.h"
#include "PagingData.h"
#include "ManageAccount.h"

class PageManageAccount:public BasePage
{
private:
	enum Function
	{
		SELECT,
		SEARCH,
		FORGOTPASSWORD,
		BACK
	};
	Function currentFunction = Function::SELECT;

	vector<string> titleGrid = {
		"Ho Va Ten", 
		"Diem", 
		"So Dien Thoai", 
		"Trang Thai" 
	};

	vector<Text> listTitle;
	vector<string> titleTutorial = { 
		"Phim Nong", 
		"F1: Tim Kiem", 
		"F2: Thao Tac Du Lieu", 
		"F3: Doi Mat Khau"
	};

	vector<Text> listTextTutorial;

	ManageAccount a;

	Text txtPagging;
	int pageNumber = 1;
	string search = "";

public:
	void main() override;
	void setUI() override;
	void handle() override;
	void selectData();
	void searchData();
	void loadData();
	void paging();
	void cleanDataUI();
	PageManageAccount();
	~PageManageAccount();
};
