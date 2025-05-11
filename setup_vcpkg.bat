@echo off
echo =====================================
echo   TU DONG CAI VCPKG VA OPENSSL
echo =====================================

:: Clone vcpkg neu chua co
if not exist "vcpkg" (
    echo Đang clone vcpkg...
    git clone https://github.com/microsoft/vcpkg.git
)

cd vcpkg

:: Build vcpkg.exe neu chua co
if not exist "vcpkg.exe" (
    echo  Đang build vcpkg...
    call bootstrap-vcpkg.bat
)

:: Gan vcpkg vao Visual Studio
echo Gan vcpkg vao Visual Studio...
call vcpkg integrate install

:: Cai thu vien tu vcpkg.json o thu muc goc project
echo Đang cai thu vien vcpkg.json...
call vcpkg install

echo.
echo Cai dat hoan tat. Ban co the mo project .sln va build.
pause
