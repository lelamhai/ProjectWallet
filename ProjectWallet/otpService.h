#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "ConfigApp.h"
#include <iostream>
using namespace std;

class OtpService
{
private:
	string secret = SECRETKEY;
	int digits = OTPLENGTH;
	int interval = EXPIREDTIME;

	string accountName = ACCOUNTNAME;
	string issuer = ISSUER;

	string base32Decode(const std::string& encoded) const;
	string hotp(const std::string& key, unsigned long long counter) const;

public:
	string generateCurrentOTP() const;
	bool verifyOTP(const std::string& userOTP, int allowedDrift = 1) const;
	void printUriToConsole();
	string getOTPAuthURI();

	OtpService();
	~OtpService();
};
