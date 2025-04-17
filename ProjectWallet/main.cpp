#include <iostream>
#include "BasePage.h"
using namespace std;

void main()
{
	PageType currentPage = PAGE_SIGNIN;
	BasePage* page = nullptr;
	
    while (currentPage != EXIT) {
        switch (currentPage) {
        case PAGE_SIGNIN:
      
        default:
            page = nullptr;
            break;
        }
    }
}