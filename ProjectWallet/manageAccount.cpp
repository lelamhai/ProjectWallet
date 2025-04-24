#include "ManageAccount.h"

ManageAccount::ManageAccount()
{
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
            pw = first + phone;
        }
        model.setPassword(sha256(pw));

        listAccount.push_back(model);
        SaveFile();
        return true;
    }
    
    return false;
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