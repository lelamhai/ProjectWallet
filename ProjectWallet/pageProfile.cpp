#include "PageProfile.h"
PageProfile::PageProfile()
{
}

PageProfile::~PageProfile()
{
}

void PageProfile::main()
{
	BasePage::header();
	BasePage::setTitlePage("Thong Tin");
	BasePage::main();
}

void PageProfile::setUI()
{
	box(0, 0, 60, 21);

	int posY = PADDING_TOP + 2;

	for (int i = 0; i < listLabel.size(); i++)
	{
		listText.push_back(Text());
		listInput.push_back(InputField());

		listText[i].setPosition(20, posY + 1);
		listText[i].setContent(listLabel[i]);
		listText[i].display();


		listInput[i].setPosition(30, posY);
		listInput[i].drawBox();

		posY += 3;
	}

	ManageAccount a;
	AccountModel model = a.FindByUserID(userID);

	listInput[0].setText(model.getLastName());
	listInput[0].display();

	listInput[1].setText(model.getFirstName());
	listInput[1].display();

	listInput[2].setText(model.getNumberPhone());
	listInput[2].display();

	listInput[3].setText("******");
	listInput[3].display();
}

void PageProfile::handle()
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