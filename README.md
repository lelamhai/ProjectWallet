# Hệ thống đăng nhập, đăng ký và quản lý ví điểm thưởng

## 🚀 Giới thiệu dự án

Đây là dự án bài tập lớn môn Ngôn ngữ C++. Dự án mô phỏng một hệ thống quản lý tài khoản người dùng, bao gồm:

- Đăng ký và đăng nhập tài khoản,
- Quản lý mật khẩu và xác thực bằng OTP,
- Theo dõi và cập nhật thông tin tài khoản,
- Quản lý ví điểm thưởng,
- Chuyển điểm giữa các ví và ghi lịch sử giao dịch.

Tất cả thao tác được thực hiện thông qua giao diện dòng lệnh (CLI).

## 👥 Thành viên nhóm và phân công công việc

| STT | Họ và tên              | MSSV       | Lớp         | Công việc đảm nhiệm                                                                                                                                    | Tỷ lệ % hoàn thành |
| --- | ---------------------- | ---------- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------ |
| 1   | **Lê Lam Hải**         | K23DTCN426 | D23TXCN04-K | Phát triển giao diện dòng lệnh; xử lý chức năng Đăng ký (Sign Up) và Đăng nhập (Sign In).                                                              | 25%                |
| 2   | **Nguyễn Công Thịnh**  | K23DTCN314 | D23TXCN06-K | Triển khai chức năng OTP xác thực; sao lưu & phục hồi dữ liệu.                                                                                         | 25%                |
| 3   | **Huỳnh Thanh Phương** | B24DTCN063 | D24TXCN06-B | Xây dựng chức năng chuyển điểm giữa các ví; hiển thị danh sách tài khoản (ShowListAccount); xử lý danh sách ví (ShowListWallet); nhập dữ liệu ban đầu. | 25%                |
| 4   | **Đoàn Đại Long Vũ**   | B24DTCN026 | D24TXCN02-B | Phát triển chức năng Quên mật khẩu (Forgot Password), Đổi mật khẩu (Change Password); kiểm thử chương trình và trình bày repo GitHub.                  | 25%                |

## 📁 Cấu trúc thư mục

```
/ProjectWallet
│
├── ProjectWallet.sln                 # Tập tin solution chính
├── ProjectWallet/
│   ├── ProjectWallet.vcxproj         # File cấu hình project C++
│   ├── main.cpp                      # Hàm main
│   ├── AccountManager.cpp/.h         # Quản lý tài khoản người dùng
│   ├── WalletManager.cpp/.h          # Quản lý ví điểm thưởng
│   ├── OTPUtils.cpp/.h               # OTP và bảo mật
│   └── backup.cpp/.h                 # Sao lưu và phục hồi dữ liệu
│
└── README.md                         # Tập tin mô tả dự án
```

## ⚙️ Cài đặt và sử dụng

### 🧰 Yêu cầu:

- Visual Studio 2022 trở lên (có cài đặt C++ Development)
- Hoặc g++ hỗ trợ C++17 nếu dùng dòng lệnh

### 🛠️ Cài đặt thư viện cho OTP

- Tải file vcpkg.rar tại đây: https://drive.google.com/file/d/1b6v7ZPZdyljKGFD7R7cbgvnjukZjRdNy/view (Lưu trong repo /ProjectWallet)
- Chuột phải thư mục setup-lib.bat chọn open để cài đặt tự động, không cần thao tác gì thêm. Màn hình console chạy xong hiển thị Đã cài đặt thư viện thành công! và nhấn phím bất kỳ để thoát.

### 🛠️ Biên dịch & chạy:

**Cách 1: Dùng Visual Studio**

1. Mở `ProjectWallet.sln`
2. Nhấn **F5** để biên dịch và chạy chương trình

**Cách 2: Dòng lệnh**

```bash
g++ -std=c++17 -o ProjectWallet.exe src/*.cpp
./ProjectWallet.exe
```

## 📘 Tài liệu dự án

### 🧩 Giới thiệu dự án

Dự án xây dựng hệ thống quản lý tài khoản và ví điểm thưởng bằng ngôn ngữ C++, thông qua giao diện dòng lệnh. Người dùng có thể đăng ký tài khoản, xác thực OTP, đổi mật khẩu, chuyển điểm, xem giao dịch. Dữ liệu được lưu dưới dạng JSON và có cơ chế sao lưu tự động.

### 📝 Phân tích và đặc tả chức năng

### 📄 Phân tích và Đặc tả chức năng chi tiết

#### 1. Đăng ký tài khoản (Sign Up)

- **Input:** Tên đăng nhập, mật khẩu, họ tên, số điện thoại,- **Output:** Tài khoản mới được tạo nếu hợp lệ
- **Xử lý:**
  - Kiểm tra trùng tên đăng nhập
  - Kiểm tra độ dài và định dạng mật khẩu
  - Ghi thông tin người dùng vào `DataAccount.json`
- **Ràng buộc:**
  - Mật khẩu tối thiểu 9 ký tự

#### 2. Đăng nhập (Sign In)

- **Input:** Tên đăng nhập và mật khẩu
- **Output:** Truy cập vào hệ thống nếu hợp lệ
- **Xử lý:**
  - Tìm tên đăng nhập trong dữ liệu
  - So sánh mật khẩu đã mã hóa (SHA256 hoặc tương đương)

#### 3. Đổi mật khẩu (Change Password)

- **Input:** Mật khẩu cũ, mật khẩu mới, xác nhận lại mật khẩu mới
- **Output:** Đổi thành công nếu mật khẩu cũ đúng và hai mật khẩu mới khớp nhau
- **Xử lý:**
  - Kiểm tra mật khẩu cũ
  - So sánh mật khẩu mới và xác nhận
  - Gửi OTP xác thực, nếu đúng thì lưu mật khẩu mới
- **Ràng buộc:**
  - OTP hợp lệ trong thời gian 30s

#### 4. Đặt lại mật khẩu (Admin)

- **Vai trò:** Quản trị viên hỗ trợ người dùng khi bị mất mật khẩu
- **Input:** Tài khoản người dùng cần đặt lại
- **Output:** Mật khẩu mới được tạo/sửa lại bởi admin
- **Xử lý:**
  - Admin nhập tên tài khoản
  - Hệ thống cho phép thay đổi mật khẩu mới
- **Ràng buộc:**
  - Chỉ admin có quyền thực hiện
  - Tài khoản phải tồn tại

#### 5. Quản lý ví (Wallet)

- **Input:** Không (tự động khởi tạo khi tạo tài khoản)
- **Output:** Ví có mã định danh, số điểm mặc định
- **Xử lý:**
  - Mỗi tài khoản có 1 ví duy nhất
  - Ví lưu trong file riêng hoặc cùng trong `DataAccount.json`

#### 6. Chuyển điểm

- **Input:** Mã ví nhận, số điểm cần chuyển
- **Output:** Cập nhật số dư của hai ví nếu hợp lệ
- **Xử lý:**
  - Kiểm tra tồn tại ví nhận
  - Kiểm tra số dư đủ
  - Giao dịch đảm bảo tính toàn vẹn (atomic)
  - Gửi OTP xác thực
- **Ràng buộc:**
  - Số điểm > 0, không vượt quá số dư
  - OTP bắt buộc cho giao dịch

#### 7. Xem danh sách ví và tài khoản (Chỉ quản trị)

- **Output:** Hiển thị danh sách tất cả tài khoản và số dư ví
- **Xử lý:** Đọc dữ liệu từ file JSON, định dạng và in ra

#### 8. Sao lưu & phục hồi dữ liệu

- **Thời điểm:** Mỗi ngày lúc `hourBackup:minuteBackup`
- **Output:** File sao lưu có tên kèm thời gian lưu trong thư mục `Backup/`
- **Xử lý:**
  - Copy nội dung file gốc sang file backup có timestamp
  - Ghi log tại `backup_log.txt`
- **Quản lý tài khoản người dùng:** đăng ký, đăng nhập, đổi mật khẩu, OTP, quyền người dùng
- **Quản lý ví điểm thưởng:** mỗi người có một ví, có thể chuyển điểm, có log giao dịch
- **Phân quyền:** người dùng thường và quản trị viên
- **Xác thực 2 lớp OTP:** mã OTP được sinh bằng Google Authenticator dựa trên SECRETKEY cố định cho từng người dùng
- **Tự động sao lưu dữ liệu** vào thư mục `Backup/` với log chi tiết

### ⚙️ Tập tin & thư viện kèm theo

- `DataAccount.json`: thông tin người dùng
- `DataTransaction.json`: giao dịch điểm
- Thư viện sử dụng: `<windows.h>`, `<fstream>`, `<ctime>`, `<thread>` và `OTP` mã nguồn mở

### 🧑‍💻 Cách thao tác chương trình

- Di chuyển bằng phím mũi tên ↑ ↓
- Nhập tài khoản, mật khẩu, mã OTP theo yêu cầu
- OTP (sinh từ Google Authenticator) được dùng để xác thực thay đổi thông tin hoặc giao dịch
- Giao dịch chuyển điểm yêu cầu xác minh và đảm bảo toàn vẹn dữ liệu (atomic)

### 🔐 Hướng dẫn lấy mã OTP bằng tiện ích mở rộng Chrome (Authenticator Extension)

1. **Cài đặt extension:**
   [https://chromewebstore.google.com/detail/authenticator/bhghoamapcdpbohphigoooaddinpkbai](https://chromewebstore.google.com/detail/authenticator/bhghoamapcdpbohphigoooaddinpkbai)

2. **Ghim extension lên thanh công cụ** để dễ sử dụng.

3. **Nhấn vào extension**, chọn **Edit**.

4. Nhấn vào dấu **“+” (Add account)** → chọn **“Import OTP URLs”**.

5. **Copy đoạn URL sau** (có thể sửa `useremail1@gmail.com` thành tên tài khoản của bạn):

   ```
   otpauth://totp/ProjectWallet:useremail1@gmail.com?secret=JBSWY3DPEHPK3PXPAAAAA&issuer=ProjectWallet
   ```

6. **Dán vào khung nhập**, chọn **“Import Text Backup”** → Trình duyệt sẽ thông báo **Success** nếu thành công.

7. Khi chọn vào biểu tượng extension, mã OTP sẽ hiển thị và cập nhật mỗi 30 giây.

### 📚 Tài liệu tham khảo

- [CPP_OTP](https://github.com/patzol768/cpp-otp)
- [COTP](https://github.com/tilkinsc/COTP)
- [ACID – 200lab](https://200lab.io/blog/acid-la-gi/)
