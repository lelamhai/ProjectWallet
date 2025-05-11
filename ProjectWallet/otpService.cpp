#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "otpService.h"

OtpManager::OtpManager(const std::string& secret, int digits, int interval)
    : secret(secret), digits(digits), interval(interval) {
}

std::string OtpManager::base32Decode(const std::string& encoded) const {
    static const std::string base32Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    std::string binaryStr;
    for (char c : encoded) {
        if (c == '=') break;
        size_t val = base32Chars.find(toupper(c));
        if (val == std::string::npos) throw std::runtime_error("Invalid Base32 character");
        for (int i = 4; i >= 0; --i)
            binaryStr += ((val >> i) & 1) ? '1' : '0';
    }
    std::string decoded;
    for (size_t i = 0; i + 8 <= binaryStr.size(); i += 8) {
        int byte = std::stoi(binaryStr.substr(i, 8), nullptr, 2);
        decoded += static_cast<char>(byte);
    }
    return decoded;
}

// Chuyen doi ma OTP thanh ma hex
std::string OtpManager::hotp(const std::string& key, unsigned long long counter) const {
    unsigned char counterBytes[8];
    for (int i = 7; i >= 0; --i) {
        counterBytes[i] = counter & 0xFF;
        counter >>= 8;
    }

    unsigned char* result;
    unsigned int len;
    result = HMAC(EVP_sha1(), key.c_str(), key.length(), counterBytes, 8, nullptr, &len);
    int offset = result[len - 1] & 0x0F;
    int binaryCode = ((result[offset] & 0x7F) << 24) |
        ((result[offset + 1] & 0xFF) << 16) |
        ((result[offset + 2] & 0xFF) << 8) |
        (result[offset + 3] & 0xFF);

    int otp = binaryCode % static_cast<int>(pow(10, digits));
    std::ostringstream ss;
    ss << std::setw(digits) << std::setfill('0') << otp;
    return ss.str();
}

std::string OtpManager::generateCurrentOTP() const {
    time_t now = time(nullptr);
    unsigned long long counter = now / interval;
    return hotp(base32Decode(secret), counter);
}

// Dung de kiem tra ma OTP
bool OtpManager::verifyOTP(const std::string& userOTP, int allowedDrift) const {
    time_t now = time(nullptr);
    unsigned long long counter = now / interval;
    std::string key = base32Decode(secret);
    for (int i = -allowedDrift; i <= allowedDrift; ++i) {
        if (hotp(key, counter + i) == userOTP)
            return true;
    }
    return false;
}

// Chuyen doi ma OTPP thanh URI cho ung dung Authenticator
std::string OtpManager::getOTPAuthURI(const std::string& accountName, const std::string& issuer) const {
    std::ostringstream oss;
    oss << "otpauth://totp/" << issuer << ":" << accountName
        << "?secret=" << secret << "&issuer=" << issuer;
    return oss.str();
}

void OtpManager::printUriToConsole(const std::string& accountName, const std::string& issuer) const {
    std::string uri = getOTPAuthURI(accountName, issuer);
    std::cout << "URI QR: " << uri << std::endl; // Copy ma URI nay de import vao extension Authenticator tren chrome
}
