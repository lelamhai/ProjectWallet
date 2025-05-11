# ProjectWallet

# 📦 ProjectBank - Setup Hướng Dẫn (Windows)

Dự án này sử dụng `vcpkg` để quản lý thư viện ngoài như `openssl`. Vui lòng làm theo các bước dưới đây để thiết lập môi trường trước khi build hoặc chạy mã nguồn.

## ✅ Bước 1: Chuẩn bị Git & PowerShell

- Đảm bảo bạn đã cài:
  - Git for Windows: https://git-scm.com/download/win
  - PowerShell (Windows mặc định đã có)

## ✅ Bước 2: Cài vcpkg & thư viện cần thiết

Chạy file `.bat` có sẵn để tự động thiết lập:

```sh
setup_vcpkg.bat
```

File này sẽ:

- Clone vcpkg nếu chưa có
- Build vcpkg
- Gắn vcpkg vào Visual Studio
- Cài các thư viện cần thiết từ `vcpkg.json`

## 🧪 Bước 3: Build project

- Mở `ProjectBank.sln` bằng Visual Studio
- Nhấn Ctrl + Shift + B để build
- Nếu không lỗi là setup thành công 🎉

## 📦 Thư viện đang dùng (trong vcpkg.json)

- `openssl`

## ⚠️ Ghi chú:

- Nếu bạn chỉ chạy file `.exe` đã build, bạn KHÔNG cần cài vcpkg hay openssl.
- Chỉ những người build lại mã nguồn mới cần thực hiện các bước trên.

---

## 📂 Cấu trúc thư mục khuyến nghị

```
/ProjectBank
│
├── vcpkg/                   ← Tự động tạo bởi script
├── vcpkg.json               ← File quản lý dependency
├── setup_vcpkg.bat          ← Script tự động cài vcpkg + openssl
├── README.md                ← File này
├── ProjectWallet            ← Code chính của bạn
└── ProjectWallet.sln        ← File solution Visual Studio
```
