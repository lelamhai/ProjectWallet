#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "ConfigApp.h"

using namespace std;

enum class OTPStatus {
    VALID,
    EXPIRED,
    INVALID
};

class OtpService {
private:
    string secret = SECRETKEY;
    int digits = OTPLENGTH;
    int interval = EXPIREDTIME;

    string accountName = ACCOUNTNAME;
    string issuer = ISSUER;

    string base32Decode(const std::string& encoded) const;
    string hotp(const std::string& key, unsigned long long counter) const;

public:
    OtpService();
    ~OtpService();

    string generateCurrentOTP() const;
    bool verifyOTP(const std::string& userOTP, int allowedDrift = 1) const;
    OTPStatus checkOTPStatus(const std::string& userOTP) const;

    void printUriToConsole();
    string getOTPAuthURI();
};
