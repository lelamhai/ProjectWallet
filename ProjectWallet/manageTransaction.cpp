#include "ManageTransaction.h"

ManageTransaction::ManageTransaction()
{
    // Tạo và nạp dữ liệu vào danh sách giao dịch
    LoadData();
}

ManageTransaction::~ManageTransaction()
{}
/*hàm tải dữ liệu từ file json đưa vào danh sác giao dịch*/ 
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
/*Hàm này nhận số điện thoại làm đầu vào*/
string ManageTransaction::GetFullNameByPhone(string phone)
{
    ManageAccount a;
    //Tìm tài khoản có số điện thoại đó
    AccountModel model = a.FindByPhone(phone);
    
    if (model.getNumberPhone() != "")
    {
        //Trả về họ tên đầy đủ của người dùng nếu tìm thấy số điện thoại đó
        return model.getLastName() + " " + model.getFirstName();
    }
    return "";
}

/*Hàm kiểm tra xem người dùng có đủ điểm để thực hiện giao dịch không
duyệt qua tất cả các tài khoản
*/
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

/*Hàm thực hiện chuyển điểm từ người gửi senderUserID sang người nhận Phone,
và ghi nhận giao dịch vào file json nếu chuyển điểm thành công*/
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

/*hàm trả về danh sách các giao dịch mà các userID đã giao dịch*/
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

/*lưu toàn bộ danh sách giao dịch vào file json*/
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