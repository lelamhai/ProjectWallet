#include "BasePage.h"
#include "PageSignIn.h"
#include "PageCustomer.h"

#include "PageAdmin.h"
#include "PageManageAccount.h"
#include "PageManageWallet.h"
#include "PageSignUp.h"
#include "PageForgotPassword.h"

#include <iostream>
using namespace std;

void main()
{
	PageType currentPageType = PageType::PAGE_MANAGEWALLET;
	BasePage* page = nullptr;
	
    while (currentPageType != EXIT) {
        switch (currentPageType) {
            case PageType::PAGE_SIGNIN:
                page = new PageSignIn();
                page->main();
                break;

            case PageType::PAGE_CUSTOMER:
                showCur(0);
                page = new PageCustomer();
                page->main();
                break;


      

            case PageType::PAGE_ADMIN:
                showCur(0);
                page = new PageAdmin();
                page->main();
                break;

            case PageType::PAGE_MANAGEACCOUNT:
                showCur(0);
                page = new PageManageAccount();
                page->main();
                break;

            case PageType::PAGE_MANAGEWALLET:
                showCur(0);
                page = new PageManageWallet();
                page->main();
                break;

            case PageType::PAGE_FORGOTPASSWORD:
                page = new PageForgotPassword();
                page->main();
                break;

            case PageType::PAGE_SIGNUP:
                page = new PageSignUp();
                page->main();
                break;

            

            default:
                page = nullptr;
                break;
        }

        if (page)
        {
            currentPageType = page->getNextPage();
            delete page;
        }
    }
}