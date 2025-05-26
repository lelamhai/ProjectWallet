#pragma once
#include "BasePage.h"

class PageSetupOtp : public BasePage
{
public:
	void main() override;
	void setUI() override;
	void handle() override;
	PageSetupOtp();
	~PageSetupOtp();
};