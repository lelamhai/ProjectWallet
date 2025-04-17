#pragma once
#include <vector>
#include <iostream>
using namespace std;
const int MAX_PAGE = 10;

template<typename T>
class PagingData
{
private:
    int currentPage;
    int totalPage;
    vector<T> currentItems;
    vector<T> allItems;
    int itemsPerPage;

public:
    PagingData(const vector<T>& items, int itemsPerPage = MAX_PAGE)
        : allItems(items), currentPage(1), itemsPerPage(itemsPerPage) {
        if (itemsPerPage <= 0) {
            throw invalid_argument("Items per page must be positive");
        }

        calculateTotalPages();
        goToPage(1);
    }

    int getTotalPages() const {
        return totalPage;
    }

    const vector<T>& getAllItems() const {
        return allItems;
    }

    int getCurrentPage() const {
        return currentPage;
    }

    const vector<T>& getCurrentItems() const {
        return currentItems;
    }

    struct PageInfo {
        int pageNumber;
        vector<T> items;
        bool isValid;
    };

    PageInfo getPageInfo(int pageNumber) const {
        PageInfo info;
        info.pageNumber = pageNumber;
        info.isValid = (pageNumber >= 1 && pageNumber <= totalPage);

        if (info.isValid) {
            int start = (pageNumber - 1) * itemsPerPage;
            int end = min(static_cast<int>(allItems.size()), start + itemsPerPage);
            info.items = vector<T>(allItems.begin() + start, allItems.begin() + end);
        }
        else {
            info.items = {};
        }

        return info;
    }

    bool goToPage(int page) {
        if (page < 1 || page > totalPage) {
            return false;
        }

        currentPage = page;
        updateCurrentItems();
        return true;
    }

    bool nextPage() {
        return goToPage(currentPage + 1);
    }

    bool previousPage() {
        return goToPage(currentPage - 1);
    }

    bool hasNextPage() const {
        return currentPage < totalPage;
    }

    bool hasPreviousPage() const {
        return currentPage > 1;
    }

    void setItemsPerPage(int newItemsPerPage) {
        if (newItemsPerPage <= 0) {
            throw invalid_argument("Items per page must be positive");
        }
        itemsPerPage = newItemsPerPage;
        calculateTotalPages();
        goToPage(1);
    }

    int getItemsPerPage() const {
        return itemsPerPage;
    }

private:
    void calculateTotalPages() {
        totalPage = (allItems.size() + itemsPerPage - 1) / itemsPerPage;
        if (totalPage == 0) totalPage = 1;
    }

    void updateCurrentItems() {
        int start = (currentPage - 1) * itemsPerPage;
        int end = min(static_cast<int>(allItems.size()), start + itemsPerPage);
        currentItems = vector<T>(allItems.begin() + start, allItems.begin() + end);
    }
};