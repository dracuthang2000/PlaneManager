#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include "plane.h"
#include "mylib.h"
#include "AVLtree.h"
#include"flight.h"
#include"bookticket.h"
#include"thongke.h"
using namespace std;
void connhay_off();
void connhay_on();
int Menu(void) {
	DS_MAYBAY mb;
	hanh_khach* ds_hk[MAX];
	DS_HANH_KHACH hk;
	DS_CHUYEN_BAY First;
	initialize(First);
	chuyen_bay cb;
	chuyenbay* ds_cb[MAX];
main_menu:
	cap_nhat(First);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	system("cls");
	Time();
	char menu_option[9][60] = {
	"1) Quan ly May bay ",
	"2) Quan ly chuyen bay ",
	"3) Quan ly Hanh khach ",
	"4) Dat Ve va Huy ve ",
	"5) Thong ke danh sach chuyen bay ",
	"6) Danh sach cac ve con trong theo ma ",
	"7) in chuyen bay theo ngay ",
	"8) Thong ke va sap xep cac luot thuc hien cua chuyen bay ",
	"9) Thoat khoi phan mem ",

	};
	gotoxy(10, 1);cout << "     __      _         _____  _                        ";
	gotoxy(10, 2);cout << "    /  \\    |_|       |  _  || |                     ";
	gotoxy(10, 3);cout << "   / __ \\    _  ___   | |_| || | __ _ _ __   ___          ";
	gotoxy(10, 4);cout << "  / |__| \\  | || __|  |  __ /| |/ _` | '_ \\ / _ \\         ";
	gotoxy(10, 5);cout << " /   ___  \\ | |||\\ \\  | |    | | (_| | | | |  __/         ";
	gotoxy(10, 6);cout << "/___/   \\__\\|_||| \\_\\ |_|    |_|\\__,_|_| |_|\\___|                  ";
	gotoxy(30, 7); cout << "  __  __                                                   _   ";
	gotoxy(30, 8); cout << " |  \\/  |                                                 | |  ";
	gotoxy(30, 9); cout << " | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ ";
	gotoxy(30, 10);cout << " | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|";
	gotoxy(30, 11);cout << " | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ ";
	gotoxy(30, 12);cout << " |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|";
	gotoxy(30, 13);cout << "                            __/ |                              ";
	gotoxy(30, 14);cout << "                           |___/                               ";
	gotoxy(15, 17);cout << "Chon cac muc duoi: " << endl;
	gotoxy(30, 18);cout << "     ==>" << menu_option[0] << endl;
	gotoxy(30, 19);cout << "        " << menu_option[1] << endl;
	gotoxy(30, 20);cout << "        " << menu_option[2] << endl;
	gotoxy(30, 21);cout << "        " << menu_option[3] <<endl;
	gotoxy(30, 22);cout << "        " << menu_option[4] << endl;
	gotoxy(30, 23);cout << "        " << menu_option[5] << endl;
	gotoxy(30, 24);cout << "        " << menu_option[6] << endl;
	gotoxy(30, 25);cout << "        " << menu_option[7] << endl;
	gotoxy(30, 26);cout << "        " << menu_option[8] << endl;
	//gotoxy(30, 28);cout << "        " << menu_option[7] << endl;
	int key = 1;
	int i = 18;
	char c;
	initialize(First);
	do {
		connhay_off();
		c = _getch();
		if (c==72)
		{
			
			if (key > 1) { key -= 1;i--; }
		}
		else if (c==80)
		{
			if (key < 9) { key += 1;i++; }
		}
		if (key != 1)
		{
			gotoxy(30, i - 1);
			cout << "        ";
			cout << menu_option[key - 2];
		}
		if (key != 9)
		{
			gotoxy(30, i + 1);
			cout << "        ";
			cout << menu_option[key];
		}
		gotoxy(30, i);
		cout << "      ==>";	
		cout << menu_option[key - 1];
		cout << "       ";

		//Sleep(200);
	} while (c!=13);
	switch (key) {
	case 1:
	{
	xuat:
		system("cls");
		result_plane(mb);
		while (1)
		{
			DS_CHUYEN_BAY First;
			initialize(First);
			Time();
			connhay_off();
			gotoxy(45, 3);cout << "QUAN LY MAY BAY";
			box_nho(5, 27, 11, 2);
			box_nho(18, 27, 14, 2);
			box_nho(34, 27, 15, 2);
			box_nho(51, 27, 18, 2);
			gotoxy(6, 28);printf("<ESC> thoat");
			gotoxy(19, 28);printf("Nhan <F1> them");
			gotoxy(35, 28);printf("Nhan <F3> edit");
			gotoxy(52, 28);printf("Nhan <DELETE> xoa");
			c = _getch();
			if (c == 27)
			{
				break;
			}
			else if (c == 59)
			{
				system("cls");
				connhay_on();
				insert_plane(mb);
				xem_maybay(mb);
				goto xuat;
			}
			else if (c == 83)
			{
				//system("cls");
				delete_plane(mb, First);
				goto xuat;
			}
			else if (c == 61)
			{
				search_edit(mb, First);
				goto xuat;
			}
		}
		break;
	}
	case 2:
	xuat1:
		system("cls");
		Print_cb_to_arr(First, ds_cb);
		result_flight(First, ds_cb);
		while (1)
		{
			Time();
			connhay_off();
			box_nho(5, 27, 11, 2);
			box_nho(18, 27, 14, 2);
			box_nho(34, 27, 15, 2);
			box_nho(51, 27, 25, 2);
			gotoxy(45, 3);cout << "QUAN LY CHUYEN BAY";
			gotoxy(6, 28);printf("<ESC> thoat");
			gotoxy(19, 28);printf("Nhan <F1> them");
			gotoxy(35, 28);printf("Nhan <F3> edit");
			gotoxy(52, 28);printf("Nhan <DELETE> huy chuyen");
			c = _getch();
			if (c == 27)
			{
				break;
			}
			else if (c == 59)
			{
				system("cls");
				connhay_on();
				insert_cb(First, cb);
				xem_cb(First, mb, ds_cb);
				goto xuat1;
			}
			else if (c == 83)
			{
				system("cls");
				cancel_flight(First, mb,ds_cb);
				goto xuat1;
			}
			else if (c == 61)
			{
				edit_fl(First,mb,ds_cb);
				goto xuat1;
			}
		}
		break;
	case 3: 
	{
	xuat2:
		system("cls");
		Time();
		hk.sl = 0;
		read_hk(hk.TREE);
		preOrder(hk.TREE, ds_hk, hk.sl);
		result_dshanhkhach(ds_hk, hk.sl);
		while (1)
		{
			connhay_off();
			gotoxy(45, 3);cout << "QUAN LY HANH KHACH";
			box_nho(5, 27, 11, 2);
			box_nho(19, 27, 14, 2);
			box_nho(35, 27, 14, 2);
			box_nho(51, 27, 20, 2);
			gotoxy(6, 28);printf("<ESC> thoat");
			gotoxy(20, 28);printf("<F1>them khach");
			gotoxy(36, 28);printf("<F2> de edit");
			gotoxy(52, 28);printf("<DELETE> xoa khach");
			c = _getch();
			if (c == 27)
			{
				break;
			}
			else if (c == 59)
			{
				system("cls");
				connhay_on();
				insert_hanhkhach(hk);
				xem_hk(hk, ds_hk);
				goto xuat2;
			}
			else if (c == 60)
			{
				edit_hk(hk,ds_hk,First);
				goto xuat2;
			}
			else if (c == 83)
			{
				Delete_hk(hk, ds_hk, First);
				goto xuat2;
			}
		}

	}
		break;
	case 4:
	xuat3:
		system("cls");
		gotoxy(50, 3);cout << "DAT VA HUY VE";
		box_nho(5, 27, 11, 2);gotoxy(6, 28);printf("<ESC> thoat");
		box_nho(19, 27, 14, 2);gotoxy(20, 28);printf("<F1> Dat ve");
		box_nho(35, 27, 14, 2);gotoxy(36, 28);printf("<F2> Huy ve");
		Print_cb_to_arr(First, ds_cb);
		result_flight(First, ds_cb);
		do
		{
			c = _getch();
			if (c == 59)
			{
				system("cls");
				datve(First, ds_cb, hk, mb);
				goto xuat3;
			}
			else if (c == 60)
			{
				system("cls");
				huy_ve(First, hk, ds_hk, mb, ds_cb);
				goto xuat3;
			}
		} while (c != 27);
		break;
	case 5:
		box_nho(5, 27, 11, 2);
		gotoxy(6, 28);printf("<ESC> thoat");
		system("cls");
		in_cb(First, hk, ds_hk, mb, ds_cb);
		break;
	case 6:
		system("cls");
		connhay_off();
		in_ve(First, hk, ds_hk, mb, ds_cb);
		break;
	case 7:
		system("cls");
		in_date(First);
		break;
	case 8:
		system("cls");
		sap_xep(First, mb);
		break;
	case 9:
		return 0;
	}
	goto main_menu;
}
void connhay_off()//con nhay bien mat
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
}
void connhay_on()//con nhay xuat hien
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
}
