#define OTPMANAGER_H

#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdexcept>

class OtpManager {
public:
    OtpManager(const std::string& secret, int digits = 6, int interval = 30);

    // gen current OTP
    std::string generateCurrentOTP() const;

    // verify OTP
    bool verifyOTP(const std::string& userOTP, int allowedDrift = 1) const;

    // gen QR code
    void printUriToConsole(const std::string& accountName, const std::string& issuer) const;

    // get uri from another tool
    std::string getOTPAuthURI(const std::string& accountName, const std::string& issuer) const;

private:
    std::string base32Decode(const std::string& encoded) const;
    std::string hotp(const std::string& key, unsigned long long counter) const;
    std::string toHex(const std::string& input) const;

    std::string secret;
    int digits;
    int interval;
};
//otpService.h