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
    PAGE_PROFILE,
    PAGE_CHANGEPASSWORD,
    PAGE_HISTORYTRANSACTION,
    PAGE_POINTRANSACTION,

    PAGE_ADMIN,
    PAGE_MANAGEACCOUNT,
    PAGE_MANAGEWALLET,
    PAGE_FORGOTPASSWORD,
    PAGE_USERTRANSACTION,
    PAGE_SIGNUP,
   
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

    int userID = -1;
    PageType nextPage = EXIT;

public:
    void setTitlePage(string title);
    void header();
    void setUIButtonBack();
    void setUISayHi();
    virtual void main();
    virtual void setUI();
    virtual void handle();
    virtual void clean();
    void setUserID(int id);
    int getUserID();
    PageType getNextPage();

	BasePage();
	~BasePage();
};