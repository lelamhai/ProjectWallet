#include "TransactionModel.h"

int TransactionModel::NextID = 0;

TransactionModel::TransactionModel()
{
	TransactionID = NextID++;
}

TransactionModel::~TransactionModel()
{
}

int TransactionModel::getTransactionID()
{
	return TransactionID;
}

int TransactionModel::getSenderUserID()
{
	return SenderUserID;
}

void TransactionModel::setSenderUserID(int id)
{
	SenderUserID = id;
}

int TransactionModel::getReceiverUserID()
{
	return ReceiverUserID;
}

void TransactionModel::setReceiverUserID(int id)
{
	ReceiverUserID = id;
}

int TransactionModel::getPoint()
{
	return Point;
}

void TransactionModel::setPoint(int point)
{
	Point = point;
}

string TransactionModel::getDatime()
{
	return Datetime;
}

void TransactionModel::setDatime(string datetime)
{
	Datetime = datetime;
}

json TransactionModel::toJson()
{
	return {
		{"TransactionID", TransactionID},
		{"SenderUserID", SenderUserID},
		{"ReceiverUserID", ReceiverUserID},
		{"Point", Point},
		{"Datetime", Datetime}
	};
}

void TransactionModel::fromJson(const json& j)
{
	TransactionID = j.at("TransactionID").get<int>();
	SenderUserID = j.at("SenderUserID").get<int>();
	ReceiverUserID = j.at("ReceiverUserID").get<int>();
	Point = j.at("Point").get<int>();
	Datetime = j.at("Datetime").get<string>();
}
