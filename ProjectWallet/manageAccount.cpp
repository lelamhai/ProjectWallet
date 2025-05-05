#include "ManageAccount.h"

ManageAccount::ManageAccount()
{
    LoadData();
}

ManageAccount::~ManageAccount()
{
}

bool ManageAccount::SignUp(string last, string first, string phone, string pass)
{
    if (CheckPhone(phone))
    {
        AccountModel model;
        model.setLastName(last);
        model.setFirstName(first);
        model.setPoint(100);
        model.setNumberPhone(phone);
        string pw = pass;
        if (pass == "")
        {
            pw = phone;
            model.setIsActive(false);
        }
        model.setPassword(sha256(pw));

        listAccount.push_back(model);
        SaveFile();
        return true;
    }
    
    return false;
}

AccountModel ManageAccount::SignIn(string user, string pass)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getNumberPhone() == user && listAccount[i].getPassword() == sha256(pass))
        {
            return listAccount[i];
        }
    }
    return AccountModel();
}

AccountModel ManageAccount::FindByPhone(string phone)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getNumberPhone() == phone)
        {
            return listAccount[i];
        }
    }
    return AccountModel();
}

bool ManageAccount::CheckPhone(string phone)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getNumberPhone() == phone)
        {
            return false;
        }
    }
    return true;
}

string ManageAccount::ToLower(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void ManageAccount::SaveFile()
{
    json jsonAccount = json::array();
    for (int i = 0; i < listAccount.size(); i++)
    {
        jsonAccount.push_back(listAccount[i].toJson());
    }
    json j;
    j["Data"] = jsonAccount;

    ofstream file(path);
    if (file.is_open()) {
        file << j.dump(4) << endl;// 4 space
        file.close();
    }
}

bool ManageAccount::LoadData()
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
            AccountModel model;
            model.fromJson(jsonAccount[i]);
            listAccount.push_back(model);
        }

        return true;
    }
    else {
        return true;
    }
}

AccountModel ManageAccount::FindByUserID(int userID)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getUserID() == userID)
        {
            return listAccount[i];
        }
    }
}

bool ManageAccount::DeductPoint(AccountModel model, int point)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (model.getUserID() == listAccount[i].getUserID())
        {
            int newPoint = listAccount[i].getPoint() - point;
            listAccount[i].setPoint(newPoint);
            SaveFile();
            return true;
        }
    }
    return false;
}

bool ManageAccount::AddPoint(AccountModel model, int point)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (model.getUserID() == listAccount[i].getUserID())
        {
            int newPoint = listAccount[i].getPoint() + point;
            listAccount[i].setPoint(newPoint);
            SaveFile();
            return true;
        }
    }
    return false;
}

vector<AccountModel> ManageAccount::GetAllAccount()
{
    return listAccount;
}