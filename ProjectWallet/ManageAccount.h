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
	bool SaveFile();
	ManageAccount();
	~ManageAccount();
};
