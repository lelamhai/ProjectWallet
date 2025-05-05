#pragma once
#include "configApp.h"
#include "AccountModel.h"
#include "json.hpp"
#include "sha256.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

class ManageAccount
{
private:
	string path = FILE_ACCOUNT;
	vector<AccountModel> listAccount;

public:
	bool SignUp(string last, string first, string mail, string password);
	AccountModel SignIn(string user, string pass);
	string ToLower(const string& str);
	bool CheckPhone(string phone);
	void SaveFile();
	bool LoadData();
	vector<AccountModel> GetAllAccount();
	AccountModel FindByUserID(int id);
	AccountModel FindByPhone(string phone);
	bool DeductPoint(AccountModel model, int point);
	bool AddPoint(AccountModel model, int point);
	ManageAccount();
	~ManageAccount();
};
