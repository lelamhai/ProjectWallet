#include "ManageAccount.h"

ManageAccount::ManageAccount()
{
    // Để load dữ liệu tài khoản 
    LoadData();
}

ManageAccount::~ManageAccount()
{
}

/*
Hàm để lưu thông tin cua người dùng xuống file json
*/
bool ManageAccount::SignUp(string last, string first, string phone, string pass)
{
    if (CheckPhone(phone))
    {
        AccountModel model;
        model.setLastName(last);
        model.setFirstName(first);
        model.setPoint(DEFAULT_POINT);
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

/*
Hàm này nhận 2 tham số là user và password
Tìm dữ liệu nào thỏa mãn
Trả về cho FE tài khoản đó
*/
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

/*
Hàm này nhận tham số userID
Để nhận biết người dùng đã hoạt động trong ứng dụng.
*/
void ManageAccount::Active(int userID)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getUserID() == userID)
        {
            listAccount[i].setIsActive(true);
            SaveFile();
            return;
        }
    }
}

/*
Hàm này để tìm kiếm dữ liệu dữ người dùng nhập vào.
Hoạt động tìm kiếm ở tên người dùng -> họ -> Số điện thoại
Trả về danh sách tìm kiếm
*/
vector<AccountModel> ManageAccount::LoadAccount(const string& keyword) {

    if (keyword != "")
    {
        vector<AccountModel> results;
        string lowerKeyword = ToLower(keyword);

        for (int i = 0; i < listAccount.size(); i++)
        {
            string lowerFirstName = ToLower(listAccount[i].getFirstName());
            string lowerLastName = ToLower(listAccount[i].getLastName());
            string lowerNumberPhone = ToLower(listAccount[i].getNumberPhone());
            if (lowerFirstName.find(lowerKeyword) != string::npos ||
                lowerLastName.find(lowerKeyword) != string::npos ||
                lowerNumberPhone.find(lowerKeyword) != string::npos) {
                results.push_back(listAccount[i]);
            }
        }
        return results;
    }
    return listAccount;
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

/*
Hàm này lấy toàn bộ dữ liệu Account
Trả về dữ liệu
*/
vector<AccountModel> ManageAccount::GetAllAccount()
{
    return listAccount;
}

/*
Để kiểm tra số điện thoại có tồn tại không.
*/
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

/*
Hàm này biến đổ text IN HOA thành text chữ thường
Trà về chuỗi
*/
string ManageAccount::ToLower(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

bool ManageAccount::ChangePassword(int userID, string oldPass, string newPass)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getUserID() == userID)
        {
            if (listAccount[i].getPassword() != sha256(oldPass))
            {
                return false;
            }
         
            listAccount[i].setPassword(sha256(newPass));
            SaveFile();
            return true;
        }
    }
    return false;
}

bool ManageAccount::ForgotPassword(int userID, string newPass)
{
    for (int i = 0; i < listAccount.size(); i++)
    {
        if (listAccount[i].getUserID() == userID)
        {
            listAccount[i].setPassword(sha256(newPass));
            SaveFile();
            return true;
        }
    }
    return false;
}

/*
Hàm này để lưu dữ liệu dạng json xuống file
*/
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

/*
Hàm này để đọc dữ liệu dạng json từ file lên hệ thống
*/
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