#pragma once
#include <iostream>
using namespace std;


const int PADDING_TOP = 5;
// File
const string FILE_ACCOUNT = "DataAccount.json";
const string FILE_TRANSACTION = "DataTransaction.json";

// Account admin
const string ADMIN = "admin";

// Delay
const int DELAY = 3000;

// Time backup 24h format
const int hourBackup = 9;
const int minuteBackup = 14;

// Max point
const int MAX_POINT = 2000000000;

// otpService
const std::string secretKey = "JBSWY3DPEHPK3PXPAAAAA"; // de nguoi dung nhap 1 scretkey
const int otpLength = 6; // neu dat nho hon 6 thi se lay so luong chu so tinh tu ben phai
//	cua ma otp duoc sinh tu ung dung Google Authenticator9
// vidu: ma otp cua Google la 123456 neu dat otpLength la 5 thi se lay 23456
// otpLength la 4 thi se lay 3456
const int expiredTime = 30; // don vi la giay 30s la mac dinh cung voi Google Authenticator
const std::string userEmail = "useremail1@gmail.com";  // email cua nguoi dung
const std::string issuer = "ProjectWallet"; // ten ung dung