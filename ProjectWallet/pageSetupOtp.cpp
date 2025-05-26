#include "PageSetupOtp.h"
#include "otpService.h"

PageSetupOtp::PageSetupOtp()
{

}

PageSetupOtp::~PageSetupOtp()
{

}

void PageSetupOtp::main()
{
	BasePage::setUIButtonBack();
	BasePage::setTitlePage("Huond dan lay ma OTP");
	BasePage::main();
}

void PageSetupOtp::setUI()
{
    OtpService otp;
    string uri = otp.getOTPAuthURI();

    int boxLeft = 10;
    int boxRight = 90;
    int boxTop = PADDING_TOP;
    int maxLineLength = boxRight - boxLeft - 4;

    vector<string> guide = {
        "1. Cai dat extension: https://chromewebstore.google.com/detail/authenticator/bhghoamapcdpbohphigoooaddinpkbai?hl=en",
        "2. Pin extension tren thanh cong cu de de su dung.",
        "3. Nhan chon vao extension, sau do nhan Edit.",
        "4. Nhan chon icon dau + (Add account) > Sau do chon dong Import OTP URLs.",
        "5. Copy doan nay: " + uri,
        "6. Dan ma vua copy vao khung chat > chon Import Text Backup > Trinh duyet se thong bao Success > thanh cong!",
        "7. Nhan chon bieu tuong extension se hien ma OTP tuong ung."
    };

    int totalLines = 0;
    for (auto& line : guide)
        totalLines += (line.length() / maxLineLength) + 1;

    int boxBottom = boxTop + totalLines + guide.size() ;


    box(boxLeft, boxTop, boxRight, boxBottom);


    Text title;
    title.setPosition(boxLeft + 3, boxTop + 1);
    title.setContent("Huong dan lay ma OTP");
    title.display();


    int posY = boxTop + 3;
    for (const auto& line : guide)
    {
        int start = 0;
        while (start < line.length())
        {
            string sub = line.substr(start, maxLineLength);
            Text t;
            t.setPosition(boxLeft + 2, posY++);
            t.setContent(sub);
            t.display();
            start += maxLineLength;
        }
        posY++;
    }
}


void PageSetupOtp::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			nextPage = PageType::PAGE_CUSTOMER;
			return;
		}
	}
}
