#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Text.h"
#include "InputField.h"
#include "Singleton.h"

#include <string>
#include <iostream>
using namespace std;

enum PageType {
    PAGE_SIGNIN,
    PAGE_SIGNUP,
    PAGE_FORGOTPASSWORD,
    PAGE_HOME,
    EXIT
};

class BasePage
{
private:
    string title = "TIEU DE";
    string name = "Xin Chao Ten!";
    Text txtTitle;

public:
    Text txtSayHi;
    InputField inputBack;
    void setTitle(string title);
    void setSayHi(string name);
    void setUIInfo();
    virtual void main();
    virtual void setUI();
    virtual void handle();
    virtual void clean();

	BasePage();
	~BasePage();
};