#include "BasePage.h"
#include "PageSignIn.h"

#include "PageCustomer.h"
#include "PageProfile.h"
#include "PageChangePassword.h"
#include "PageHistoryTransaction.h"
#include "PagePointTransaction.h"

#include "PageAdmin.h"
#include "PageManageAccount.h"
#include "PageManageWallet.h"
#include "PageSignUp.h"
#include "PageForgotPassword.h"
#include "PageUserTransaction.h"
#include "backup.h"

#include <thread>
#include <iostream>
using namespace std;

void main()
{
    startBackupThread(FILE_ACCOUNT);
    startBackupThread(FILE_TRANSACTION);

	PageType currentPageType = PageType::PAGE_SIGNIN;
	BasePage* page = nullptr;
    int currentUserID = -1;
	
    while (currentPageType != EXIT) {
        switch (currentPageType) {
            case PageType::PAGE_SIGNIN:
                currentUserID = -1;
                page = new PageSignIn();
                page->main();
                currentUserID = Singleton::getInstance()->UserID;
                break;
            
            case PageType::PAGE_CUSTOMER:
                showCur(0);
                page = new PageCustomer();
                page->main();
                currentUserID = Singleton::getInstance()->UserID;
                break;

            case PageType::PAGE_PROFILE:
                page = new PageProfile();
                page->setUserID(currentUserID);
                page->main();
                break;

            case PageType::PAGE_CHANGEPASSWORD:
                showCur(0);
                page = new PageChangePassword();
                page->setUserID(currentUserID);
                page->main();
                break;

            case PageType::PAGE_POINTRANSACTION:
                page = new PagePointTransaction();
                page->setUserID(currentUserID);
                page->main();
                break;

            case PageType::PAGE_HISTORYTRANSACTION:
                page = new PageHistoryTransaction();
                page->setUserID(currentUserID);
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
                currentUserID = page->getUserID();
                break;

            case PageType::PAGE_FORGOTPASSWORD:
                page = new PageForgotPassword();
                page->setUserID(currentUserID);
                page->main();
                break;

            case PageType::PAGE_SIGNUP:
                page = new PageSignUp();
                page->main();
                break;

            case PageType::PAGE_MANAGEWALLET:
                showCur(0);
                page = new PageManageWallet();
                page->main();
                currentUserID = page->getUserID();
                break;

            case PageType::PAGE_USERTRANSACTION:
                showCur(0);
                page = new PageUserTransaction();
                page->setUserID(currentUserID);
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