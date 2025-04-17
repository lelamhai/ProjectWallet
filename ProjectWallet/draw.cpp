#include <windows.h>
#include <iostream>
using namespace std;

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void lineX(int x, int y, int w)
{
	if (w < 1)
	{
		return;
	}

	for (int i = x; i <= x + w; i++)
	{
		gotoXY(i, y);
		cout << char(196);
	}
}

void lineXDot(int x, int y, int w)
{
	if (w < 1)
	{
		return;
	}

	for (int i = x; i <= x + w; i++)
	{
		gotoXY(i, y);
		cout << "-";
	}
}

void lineY(int x, int y, int h)
{
	for (int i = y; i <= y + h; i++)
	{
		gotoXY(x, i);
		cout << char(179);
	}
}

void box(int x, int y, int w, int h)
{
	if (h <= 1 || w <= 1)
	{
		return;
	}

	for (int i = x; i <= x + w; i++)
	{
		gotoXY(i, y);
		cout << char(196);
		gotoXY(i, y + h);
		cout << char(196);
	}

	for (int i = y; i <= y + h; i++)
	{
		gotoXY(x, i);
		cout << char(179);
		gotoXY(x + w, i);
		cout << char(179);
	}

	gotoXY(x, y);
	cout << char(218);

	gotoXY(x + w, y);
	cout << char(191);

	gotoXY(x, y + h);
	cout << char(192);

	gotoXY(x + w, y + h);
	cout << char(217);
}