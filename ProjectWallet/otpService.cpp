#include "OtpService.h"

OtpService::OtpService() {
    //printUriToConsole();
}
OtpService::~OtpService() {}

string OtpService::base32Decode(const std::string& encoded) const {
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

string OtpService::hotp(const std::string& key, unsigned long long counter) const {
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

string OtpService::generateCurrentOTP() const {
    time_t now = time(nullptr);
    unsigned long long counter = now / interval;
    return hotp(base32Decode(secret), counter);
}

bool OtpService::verifyOTP(const std::string& userOTP, int allowedDrift) const {
    time_t now = time(nullptr);
    unsigned long long counter = now / interval;
    std::string key = base32Decode(secret);
    for (int i = -allowedDrift; i <= allowedDrift; ++i) {
        if (hotp(key, counter + i) == userOTP)
            return true;
    }
    return false;
}

OTPStatus OtpService::checkOTPStatus(const std::string& userOTP) const {
    time_t now = time(nullptr);
    unsigned long long counter = now / interval;
    std::string key = base32Decode(secret);

    std::string currentOtp = hotp(key, counter);
    if (userOTP == currentOtp)
        return OTPStatus::VALID;

    for (int i = -1; i <= 1; ++i) {
        if (i == 0) continue;
        if (hotp(key, counter + i) == userOTP)
            return OTPStatus::EXPIRED;
    }

    return OTPStatus::INVALID;
}

void OtpService::printUriToConsole() {
    string uri = getOTPAuthURI();
    
    cout << "Huong dan cai dat lay ma OTP, chi cai dat 1 lan!" << std::endl;
    cout << "1: Cai dat extension: https://chromewebstore.google.com/detail/authenticator/bhghoamapcdpbohphigoooaddinpkbai?hl=en" << std::endl;
    cout << "2: Pin enxtension tren thanh cong cu de de su dung" << std::endl;
    cout << "3: Nhan chon vao extension, sau do nhan Edit" << std::endl;
    cout << "4: Nhan chon icon dau + (Add account) > Sau do chon dong Import OTP URLs" << std::endl;
    cout << "5: Copy doan nay: " << uri << std::endl;
    cout << "6: Dan ma vua copy vao khung chat > chon Import Text Backup > Trinh duyet se thong bao Success > thanh cong!" << std::endl;
    cout << "7: Nhan chon bao bieu tuong extension se hien ma OTP tuong ung" << std::endl;
}

string OtpService::getOTPAuthURI() {
    ostringstream oss;
    oss << "otpauth://totp/" << issuer << ":" << accountName
        << "?secret=" << secret << "&issuer=" << issuer;
    return oss.str();
}