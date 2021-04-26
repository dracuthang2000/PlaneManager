#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
using namespace std;
#define boxx 4 //Vi tri x bat dau cua box
#define boxy 1 //Vi tri y bat dau cua box
#define boxs 111 //Box size
void Box_tong()
{
	SetColor(15);
	gotoxy(boxx, boxy); cout << char(218);
	for (int i = 1; i < boxs + 1; i++) cout << char(196);
	cout << char(191);
	int i = 1;int j = 1;
	for (int i = 1;i < 25;i++)
	{
		gotoxy(boxx, boxy + i);             cout << char(179);
		gotoxy(boxx + boxs + 1, boxy + i);  cout << char(179);
	}
	gotoxy(boxx, boxy + 25);               cout << char(192);
	for (int i = 1; i < boxs + 1; i++)    cout << char(196);
	cout << char(217);
}
void box_kex(int x,int y)
{
	int i = y;
	gotoxy(x, boxy+y);cout << char(194);
	while (i <= 25)
	{
		gotoxy(x, boxy + i);             cout << char(179);
		i++;
	}
	gotoxy(x, boxy + 25);
	cout << char(193);
}
void box_key(int y)
{
	gotoxy(boxx, y);
	for (int i = 1; i <= boxs + 1; i++)    cout << char(196);
	cout << char(180);
	gotoxy(boxx, y);cout << char(195);
}
void box_kexy(int x, int y,int s)
{
	gotoxy(x, y);
	for (int i = 1; i <= s + 1; i++) cout << char(196);
	cout << char(180);
	gotoxy(x, y);cout << char(195);
}
void box_noio(int x, int y)
{
	gotoxy(x, y);cout << char(197);
}
void box_noih(int x, int y)
{
	gotoxy(x, y);cout << char(194);
}
void box_nho(int x, int y, int s, int h)
{
	gotoxy(x, y);cout << char(218);
	for (int i = 1; i < s + 1; i++)
	{
		gotoxy(x + i, y);
		cout << char(196);
	}
	cout << char(191);
	for (int i = 1;i < h;i++)
	{
		gotoxy(x, y + i);             cout << char(179);
		gotoxy(x + s + 1, y + i);  cout << char(179);
	}
	for (int i = 1; i < s + 1; i++)
	{
		gotoxy(x + i, h + y);
		cout << char(196);
	}
	cout << char(217);
	gotoxy(x, y + h);cout << char(192);
}