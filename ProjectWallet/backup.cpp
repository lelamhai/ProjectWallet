#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
#include <thread>

// Hàm lấy thư mục chứa file .exe
std::string getExeDirectory() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string fullPath(buffer);
    size_t pos = fullPath.find_last_of("\\/");
    return fullPath.substr(0, pos);
}

BOOL CopyFileUnicode(const std::string& src, const std::string& dest)
{
    std::wstring wsrc(src.begin(), src.end());
    std::wstring wdest(dest.begin(), dest.end());
    return CopyFileW(wsrc.c_str(), wdest.c_str(), FALSE);
};

void backupJsonFile() {
    std::string exeDir = getExeDirectory();
    std::string srcPath = exeDir + "\\..\\..\\ProjectWallet\\DataAccount.json";
    std::string backupFolder = exeDir + "\\Backup";

    // Tạo folder backup nếu chưa có
    CreateDirectoryA(backupFolder.c_str(), NULL);

    // Lấy thời gian hiện tại
    time_t now = time(nullptr);
    struct tm tstruct;
    localtime_s(&tstruct, &now);

    char timeStr[80];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%H-%M-%S", &tstruct);

    // Tạo đường dẫn backup file
    std::string destPath = backupFolder + "\\DataAccount_backup_" + timeStr + ".json";

    // Thực hiện copy
    BOOL copyResult = CopyFileUnicode(srcPath, destPath);

    // Ghi log
    std::string logPath = exeDir + "\\backup_log.txt";
    std::ofstream log(logPath, std::ios::app);

    if (!log) {
        std::cerr << "Khong the mo file log " << std::endl;
        return;
    }

    if (copyResult) {
        log << "[" << timeStr << "] Backup thanh cong toi: " << destPath << std::endl;
    }
    else {
        DWORD errorCode = GetLastError();
        log << "[" << timeStr << "] Backup that bai! Ma loi: " << errorCode << std::endl;
    }

    log.close();
}

void waitUntilTime(int targetHour, int targetMin) {
    while (true) {
        time_t now = time(0);
        struct tm local;
        localtime_s(&local, &now);

        if (local.tm_hour == targetHour && local.tm_min == targetMin) {
            backupJsonFile();
            std::this_thread::sleep_for(std::chrono::minutes(1));
        }
        else {
            std::this_thread::sleep_for(std::chrono::seconds(30));
        }
    }
}

