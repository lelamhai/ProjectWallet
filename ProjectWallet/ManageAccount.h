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
	bool AddPoint(AccountModel model, int point);
	bool DeductPoint(AccountModel model, int point);
	vector<AccountModel> LoadAccount(const string& keyword);
	vector<AccountModel> GetAllAccount();
	string ToLower(const string& str);
	bool ForgotPassword(int userID, string oldPass, string newPass);
	bool ChangePassword(int userID, string newPass);
	bool CheckPhone(string phone);
	void SaveFile();
	bool LoadData();
	AccountModel FindByUserID(int id);
	AccountModel FindByPhone(string phone);
	ManageAccount();
	~ManageAccount();
};
