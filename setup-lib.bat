@echo off
REM ==============================================
REM  setup-vcpkg.bat — install vcpkg + OpenSSL
REM  This version extracts vcpkg.rar with WinRAR
REM ==============================================
setlocal enabledelayedexpansion

REM ---- 1. Đường dẫn gốc & biến tiện ích ----
set "ROOT=%~dp0"
set "ARCHIVE=%ROOT%vcpkg.rar"
set "VCPKG_DIR=%ROOT%vcpkg"

echo --------------------------------------------
echo  [VCPKG-SETUP] Starting…
echo --------------------------------------------

REM ---- 2. Nếu vcpkg\bootstrap chưa tồn tại thì giải nén ----
if not exist "%VCPKG_DIR%\bootstrap-vcpkg.bat" (

    REM ---- 2a. Xác định WinRAR.exe / UnRAR.exe ----
    set "WINRAR="
    for %%P in ("%ProgramFiles%" "%ProgramFiles(x86)%") do (
        if exist "%%~P\WinRAR\WinRAR.exe" (
            set "WINRAR=%%~P\WinRAR\WinRAR.exe"
            goto :found
        )
        if exist "%%~P\WinRAR\UnRAR.exe" (
            set "WINRAR=%%~P\WinRAR\UnRAR.exe"
            goto :found
        )
    )
    REM Nếu trong PATH đã có lệnh thì WinRAR gọi thẳng được
    where /Q winrar.exe && set "WINRAR=winrar.exe"
    where /Q unrar.exe   && if not defined WINRAR set "WINRAR=unrar.exe"

:found
    if not defined WINRAR (
        echo [ERROR] Không tìm thấy WinRAR trong Program Files hoặc PATH.
        echo         Vui lòng cài WinRAR hoặc thêm nó vào biến PATH.
        exit /b 1
    )

    if not exist "%ARCHIVE%" (
        echo [ERROR] Không tìm thấy %ARCHIVE%
        exit /b 1
    )

    echo [INFO] Extracting vcpkg.rar with WinRAR…
    "%WINRAR%" x -o+ -ibck -y "%ARCHIVE%" "%VCPKG_DIR%\" >nul

    REM ---- 2b. Sửa trường hợp nén lồng vcpkg\vcpkg\... ----
    if exist "%VCPKG_DIR%\vcpkg\bootstrap-vcpkg.bat" (
        echo [INFO] Fixing nested folder structure…
        robocopy "%VCPKG_DIR%\vcpkg" "%VCPKG_DIR%" /E >nul
        rmdir /s /q "%VCPKG_DIR%\vcpkg"
    )
)

REM ---- 3. Chạy bootstrap, cài OpenSSL, integrate ----
pushd "%VCPKG_DIR%"
if exist "bootstrap-vcpkg.bat" (
    echo [INFO] Bootstrapping vcpkg…
    call bootstrap-vcpkg.bat -disableMetrics
) else (
    echo [ERROR] bootstrap-vcpkg.bat not found even after extraction.
    popd & exit /b 1
)

echo [INFO] Installing openssl:x64-windows…
call vcpkg install openssl:x64-windows

echo [INFO] Integrating vcpkg with Visual Studio…
call vcpkg integrate install

popd
echo --------------------------------------------
echo  Đã cài đặt thư viện thành công!
echo --------------------------------------------
REM === GIỮ CỬA SỔ LẠI ===
echo.
echo Nhấn phím bất kỳ để thoát cửa sổ này!
pause >nul
endlocal
