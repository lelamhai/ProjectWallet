#pragma once
#include "configApp.h"
#include "ManageAccount.h"
#include "TransactionModel.h"
#include "json.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <iostream>
#include <chrono>

using namespace std;
using json = nlohmann::json;

class ManageTransaction
{
private:
	string path = FILE_TRANSACTION;
	vector<TransactionModel> listTransaction;

public:
	bool LoadData();
	string GetFullNameByPhone(string phone);
	bool CheckPointOfWallet(int senderUserID, int point);
	void TransactionPoint(int SenderUserID, string phone, int Point);
	vector<TransactionModel> GetAllTransaction(int userID);
	bool SaveFile();
	ManageTransaction();
	~ManageTransaction();
};