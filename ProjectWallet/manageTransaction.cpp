#include "ManageTransaction.h"

ManageTransaction::ManageTransaction()
{
    LoadData();
}

ManageTransaction::~ManageTransaction()
{}

bool ManageTransaction::LoadData()
{
    ifstream file(path);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();
        json jsonAccount = json::array();
        jsonAccount = j["Data"];

        for (int i = 0; i < jsonAccount.size(); i++)
        {
            TransactionModel model;
            model.fromJson(jsonAccount[i]);
            listTransaction.push_back(model);
        }

        return true;
    }
    else {
        return true;
    }
}

string ManageTransaction::GetFullNameByPhone(string phone)
{
    ManageAccount a;
    AccountModel model = a.FindByPhone(phone);

    if (model.getNumberPhone() != "")
    {
        return model.getLastName() + " " + model.getFirstName();
    }
    return "";
}

bool ManageTransaction::CheckPointOfWallet(int senderUserID, int point)
{
    ManageAccount a;
    for (int i = 0; i < a.GetAllAccount().size(); i++)
    {
        if (a.GetAllAccount()[i].getUserID() == senderUserID && a.GetAllAccount()[i].getPoint() - point > 0)
        {
            return true;
        }
    }
    return false;
}

void ManageTransaction::TransactionPoint(int SenderUserID, string phone, int Point)
{
    ManageAccount a;
    AccountModel senderAccount = a.FindByUserID(SenderUserID);
    AccountModel receiverAccount = a.FindByPhone(phone);

    if (a.DeductPoint(senderAccount, Point) && a.AddPoint(receiverAccount, Point))
    {
        
        auto now = std::chrono::system_clock::now();
        time_t now_time = std::chrono::system_clock::to_time_t(now);

        struct tm timeinfo;
        localtime_s(&timeinfo, &now_time);

        stringstream ss;
        ss << std::put_time(&timeinfo, "%d/%m/%Y %H:%M:%S");
        string datetime = ss.str();

        TransactionModel model;
        model.setSenderUserID(SenderUserID);
        model.setReceiverUserID(a.FindByPhone(phone).getUserID());
        model.setPoint(Point);
        model.setDatime(datetime);

        listTransaction.push_back(model);
        SaveFile();
    }
}

vector<TransactionModel> ManageTransaction::GetAllTransaction(int userID)
{
    vector<TransactionModel> results;
    for (int i = 0; i < listTransaction.size(); i++)
    {
        if (listTransaction[i].getSenderUserID() == userID || listTransaction[i].getReceiverUserID() == userID)
        {
            results.push_back(listTransaction[i]);
        }
    }

    return results;
}

bool ManageTransaction::SaveFile()
{
    json jsonAccount = json::array();
    for (int i = 0; i < listTransaction.size(); i++)
    {
        jsonAccount.push_back(listTransaction[i].toJson());
    }
    json j;
    j["Data"] = jsonAccount;

    ofstream file(path);
    if (file.is_open()) {
        file << j.dump(4) << endl;// 4 space
        file.close();
        return true;
    }
    else {
        return false;
    }
}