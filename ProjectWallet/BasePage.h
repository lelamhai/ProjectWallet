#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Text.h"
#include "InputField.h"
#include "Singleton.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum PageType {
    PAGE_SIGNIN,
    PAGE_CUSTOMER,
    PAGE_ADMIN,
    PAGE_MANAGEACCOUNT,

    PAGE_SIGNUP,
    PAGE_FORGOTPASSWORD,
    PAGE_HOME,
    EXIT
};

class BasePage
{
protected:
    string title = "TIEU DE";
    string name = "Xin Chao Ten!";
    Text txtTitlePage;
    Text txtSayHi;
    InputField inputBack;

    PageType nextPage = EXIT;

public:
    void setTitlePage(string title);
    void setHeader();
    void setUIButtonBack();
    void setUISayHi();
    virtual void main();
    virtual void setUI();
    virtual void handle();
    virtual void clean();
    PageType getNextPage();

	BasePage();
	~BasePage();
};