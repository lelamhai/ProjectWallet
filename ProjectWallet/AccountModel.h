#pragma once
#include "json.hpp"
#include <string>
#include <iostream>
using namespace std;
using json = nlohmann::json;

class AccountModel
{
private:
	static int NextID;
	int UserID;
	string LastName;
	string FirstName;
	int Point;
	string NumberPhone;
	string Password;
	bool IsActive;

public:
	int getUserID();
	string getFirstName();
	void setFirstName(string name);
	string getLastName();
	void setLastName(string last);
	int getPoint();
	void setPoint(int point);
	string getNumberPhone();
	void setNumberPhone(string phone);
	string getPassword();
	void setPassword(string pass);
	bool getIsActive();
	void setIsActive(bool active);

	json toJson();
	void fromJson(const json& j);
	AccountModel();
	~AccountModel();
};