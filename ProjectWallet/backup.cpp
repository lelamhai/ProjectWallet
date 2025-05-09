#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include "ConfigApp.h"

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

void backupJsonFile(const std::string& fileBackup) {
    std::string exeDir = getExeDirectory();
    std::string srcPath = exeDir + "\\..\\..\\ProjectWallet\\" + fileBackup;
    std::string backupFolder = exeDir + "\\Backup\\";

    // Tạo folder backup nếu chưa có
    CreateDirectoryA(backupFolder.c_str(), NULL);

    // Lấy thời gian hiện tại
    time_t now = time(nullptr);
    struct tm tstruct;
    localtime_s(&tstruct, &now);

    char timeStr[80];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%H-%M-%S", &tstruct);

    // Tạo đường dẫn backup file
    std::string fileName = fileBackup.substr(0, fileBackup.find_last_of('.'));
    std::string destPath = backupFolder + "\\" + fileName + "_backup_" + timeStr + ".json";

    // Thực hiện copy
    BOOL copyResult = CopyFileUnicode(srcPath, destPath);

    // Ghi log
    std::string logPath = exeDir + "\\backup_log.txt";
    std::ofstream log(logPath, std::ios::app);

    // Kiểm tra xem file nguồn có tồn tại không
    DWORD attrs = GetFileAttributesA(srcPath.c_str());
    if (attrs == INVALID_FILE_ATTRIBUTES || (attrs & FILE_ATTRIBUTE_DIRECTORY)) {
        log << "[" << timeStr << "] File nguồn không tồn tại: " << srcPath << std::endl;
        std::cerr << "File nguồn không tồn tại: " << srcPath << std::endl;
        return;
    }

    if (!log) {
        std::cerr << "Khong the mo file log " << std::endl;
        return;
    }

    if (copyResult) {
        log << "[" << timeStr << "] Backup " + fileBackup + " thanh cong toi : " << destPath << std::endl;
    }
    else {
        DWORD errorCode = GetLastError();
        log << "[" << timeStr << "] Backup that bai! Ma loi: " << errorCode << std::endl;
    }

    log.close();
}

void waitUntilTime(const std::string& fileBackup, int targetHour, int targetMin) {
    while (true) {
        time_t now = time(0);
        struct tm local;
        localtime_s(&local, &now);

        if (local.tm_hour == targetHour && local.tm_min == targetMin) {
            backupJsonFile(fileBackup);
            std::this_thread::sleep_for(std::chrono::minutes(1));
        }
        else {
            std::this_thread::sleep_for(std::chrono::seconds(30));
        }
    }
}

void startBackupThread(const std::string& fileBackup) {
    std::thread([fileBackup]() {
        waitUntilTime(fileBackup, hourBackup, minuteBackup);
        }).detach(); // tách hẳn ra để không cần join
}

