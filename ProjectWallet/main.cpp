#include <iostream>
#include "BasePage.h"
#include "PageSignIn.h"
#include "PageCustomer.h"

using namespace std;

void main()
{
	PageType currentPageType = PageType::PAGE_SIGNIN;
	BasePage* page = nullptr;
	
    while (currentPageType != EXIT) {
        switch (currentPageType) {
        case PageType::PAGE_SIGNIN:
            page = new PageSignIn();
            page->main();

        case PageType::PAGE_CUSTOMER:
            page = new PageCustomer();
            page->main();

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