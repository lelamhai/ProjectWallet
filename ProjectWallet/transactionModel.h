#pragma once
#include "json.hpp"
#include <string>
#include <iostream>

using namespace std;
using json = nlohmann::json;

class TransactionModel
{
private:
	static int NextID;
	int TransactionID;
	int UserID;
	int SenderUserID;
	int ReceiverUserID;
	int Point;
	string Datetime;

public:
	int getTransactionID();
	int getSenderUserID();
	void setSenderUserID(int id);
	int getReceiverUserID();
	void setReceiverUserID(int id);
	int getPoint();
	void setPoint(int point);
	string getDatime();
	void setDatime(string datetime);

	json toJson();
	void fromJson(const json& j);
	TransactionModel();
	~TransactionModel();
};

