#pragma once
#include "ctdl.h"
#include"readandwritefile.h"
#include <iomanip>
#include<cstring>
#include "Box.h"
char* block_char(int a, int x, int y);
int yes_no(DS_MAYBAY& mb);
char* block_number(int a, int x, int y);
using namespace std;
int same_test(DS_MAYBAY& mb, int a)
{
	for (int i = 0;i < mb.sl - 1;i++)
	{
		if (i != a)
		{
			if (_stricmp(mb.dsmaybay[a]->sohieu, mb.dsmaybay[i]->sohieu) == 0 /*&& _stricmp(mb.dsmaybay[a]->loaimaybay, mb.dsmaybay[i]->loaimaybay) == 0*/)return 1;
		}
	}
	return 0;
}
int insert_plane(DS_MAYBAY& mb)
{
	system("cls");
	Time();
	readfile_plane(mb);
	gotoxy(50, 3);cout << "TINH NANG THEM";
	gotoxy(5, 4);cout << "Nhan <ESC> de quay lai";
	int i = 0;
	int a;
	char c;
	int k = 1;
	char* tmp = new char[100];
	mb.dsmaybay[mb.sl - 1] = new MAY_BAY;
	a = mb.sl - 1;
	box_nho(36, 8, 50, 7);
	box_nho(92, 3, 25, 3);
	box_nho(4, 3, 25, 3);
	gotoxy(45, 10);cout << "Nhap loai may bay ";
	gotoxy(45, 11);cout << "nhap so hieu ";
	gotoxy(45, 12);cout << "Nhap so cho ";
	gotoxy(50, 8);
	do {
		tmp = block_char(41, 63, 10);
	} while (tmp[0] == '\0');
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '.')
		{
			return 0;
		}
		mb.dsmaybay[a]->loaimaybay[i] = tmp[i];
		i++;
		mb.dsmaybay[a]->loaimaybay[i] = '\0';
	}
	gotoxy(50, 9);
	do
	{
		i = 0;
		for (int j = 0;j <= 15;j++)
		{
			gotoxy(62 + j, 11);cout << " ";
		}
		do {
			tmp = block_and_char(15, 62, 11);
		} while (tmp[0] == '\0');
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '.')
			{
				return 0;
			}
			mb.dsmaybay[a]->sohieu[i] = tmp[i];
			i++;
			mb.dsmaybay[a]->sohieu[i] = '\0';
		}
		if (same_test(mb, a) == 1)
		{
			gotoxy(94, 4);
			cout << "nhap lai!";
			_getch();
			gotoxy(94, 4);cout << "           ";
			//gotoxy(50, 9);cout << "           ";
			//gotoxy(50, 9);
		}
	} while (same_test(mb, a) == 1);
	do
	{
		gotoxy(94, 4);
		cout << "So cho >=20";
		for (int j = 0;j <= 15;j++)
		{
			gotoxy(62 + j, 12);cout << " ";
		}
		i = 0;
		do {
			tmp = block_number(15, 62, 12);
		} while (tmp[0] == '\0');
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '.')
			{
				return 0;
			}
			i++;
		}
		mb.dsmaybay[a]->socho = atoi(tmp);
		if (mb.dsmaybay[a]->socho < 20)
		{
			gotoxy(94, 5);
			cout << "nhap lai!";
			_getch();
			gotoxy(94, 5);cout << "           ";
		}
	} while (mb.dsmaybay[a]->socho < 20);
	system("cls");
	writefile_plane(mb);
	return 0;
}
void result_plane(DS_MAYBAY& mb)
{
	connhay_off();
	readfile_plane(mb);
	Time();
	int trang=0;
	int tong=0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	int dem = 0;
	char c;
		Box_tong();
		box_key(4);
		box_key(6);
		box_kex(9, 4);
		box_noih(9, 4);
		box_noio(9, 6);
		box_kex(60, 4);
		box_noih(60, 4);
		box_noio(60, 6);
		box_kex(100, 4);
		box_noih(100, 4);
		box_noio(100, 6);
		gotoxy(5, 5);
		cout << "STT";
		gotoxy(20, 5);
		cout << "Loai may bay";
		gotoxy(74, 5);
		cout << "So hieu";
		gotoxy(101, 5);
		cout << "so cho";
		//while (1)
		//{
		back:
		int j = 6;
		for (int i=0+trang*18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
		{
			j++;
			gotoxy(6, j);
			cout << i;
			gotoxy(20, j);
			cout << mb.dsmaybay[i]->loaimaybay;
			gotoxy(75, j);
			cout << mb.dsmaybay[i]->sohieu;
			gotoxy(103, j);
			cout << mb.dsmaybay[i]->socho;
		}
		/*main:
		do {
			c = _getch();
		} while (c != 77 && c != 75&&c!=27&&c!=83);
		if (c == 27)break;
		if (c == 77)
		{
			if (tong > 1 && trang + 1 < tong)
			{
				j = 0;
				trang++;
				while (j <= 18)
				{
					for (int i = 0;i < 4;i++)
					{
						gotoxy(5 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 50;i++)
					{
						gotoxy(10 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 39;i++)
					{
						gotoxy(61 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 10;i++)
					{
						gotoxy(101 + i, j + 7);
						cout << " ";
					}
					j++;
				}
					
				goto back;
			}
			else
			{
				goto main;
			}
		}
		else if (c == 75)
		{
			if (tong > 1 && trang > 0)
			{
				j = 0;
				trang--;
				while (j <= 18)
				{
					for (int i = 0;i < 4;i++)
					{
						gotoxy(5 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 50;i++)
					{
						gotoxy(10 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 39;i++)
					{
						gotoxy(61 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 10;i++)
					{
						gotoxy(101 + i, j + 7);
						cout << " ";
					}
					j++;
				}
				goto back;
			}
			else
			{
				goto main;
			}
		}
	}*/
}
void delete_plane(DS_MAYBAY& mb, DS_CHUYEN_BAY& First)
{
	char c;
back:
	system("cls");
	gotoxy(90, 3);cout << "TINH NANG XOA";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	result_plane(mb);
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	readfile_cb(First);
	Time();
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search SH:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoxy(27 + i, 3);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoxy(6, l + 7);
						cout << i;
						gotoxy(20, l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoxy(27 + i - 1, 3);
			cout << " ";
			gotoxy(27 + i - 1, 3);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoxy(6, k + 7);
						cout << i;
						gotoxy(20, k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				system("cls");
				result_plane(mb);
				gotoxy(15, 3);cout << "Search SH:";
				goto back;
				connhay_off();
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0;i < u - 1;i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
	//=================================================================================================================//
	box_nho(100, 27, 15, 2);gotoxy(101, 28);
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0&&c==72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u-2)
			{
				f += 1;
				p++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoxy(0, f - 1);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoxy(0, f + 1);
			printf("  ");
		}
		if (f == 25&& tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	system("cls");
	//=============================================================================================================//

	int h = 0;
	char* tmp = new char[16];
	while (mb.dsmaybay[a[p]]->sohieu[h] != '\0')
	{
		tmp[h] = mb.dsmaybay[a[p]]->sohieu[h];
		h++;
		tmp[h] = '\0';
	}
	DS_CHUYEN_BAY v;
	v = First;
	while (v != NULL)
	{
		if (_strcmpi(v->cb.sohieu, tmp) == 0)
		{
			system("cls");
			box_nho(10, 13, 100, 2);
			gotoxy(30, 14);cout << "MAY BAY NAY DA DUOC THANH LAP CHUYEN BAY, NEN BAN KHONG DUOC XOA";
			_getch();
			goto back;
			gotoxy(50, 13);
			v->cb.trangthai = 0;
			//_getch();
			//system("cls");
			//goto main;
		}
		v = v->next;
	}
	for (int j = a[p];j < mb.sl - 1;j++)
	{
		strcpy_s(mb.dsmaybay[j]->loaimaybay, mb.dsmaybay[j + 1]->loaimaybay);
		strcpy_s(mb.dsmaybay[j]->sohieu, mb.dsmaybay[j + 1]->sohieu);
		mb.dsmaybay[j]->socho = mb.dsmaybay[j + 1]->socho;
	}
	MAY_BAY* tam = mb.dsmaybay[mb.sl - 1];
	mb.sl = mb.sl - 2;
	system("cls");
	Time();
	gotoxy(48, 11);cout << "BAN CO CHAC LA XOA KHONG";
	if (yes_no(mb) == 0)
	{
		box_nho(40, 13, 20, 3);
		gotoxy(46, 15);
		cout << "DA XOA XONG";
		writefile_flight(First);
		Sleep(300);
		system("cls");
	}
	goto back;
	system("cls");
}
void search_edit(DS_MAYBAY& mb, DS_CHUYEN_BAY& First)
{
	char c;
back:
	system("cls");
	gotoxy(90, 3);cout << "TINH NANG EDIT";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	result_plane(mb);
	readfile_cb(First);
	Time();
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search SH:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoxy(27 + i, 3);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoxy(6, l + 7);
						cout << i;
						gotoxy(20, l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoxy(27 + i - 1, 3);
			cout << " ";
			gotoxy(27 + i - 1, 3);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoxy(6, k + 7);
						cout << i;
						gotoxy(20, k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				system("cls");
				result_plane(mb);
				gotoxy(15, 3);cout << "Search SH:";
				connhay_off();
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0;i < u - 1;i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
	box_nho(100, 27, 15, 2);
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoxy(0, f - 1);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoxy(0, f + 1);
			printf("  ");
		}
		if (f == 25 && tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	system("cls");
	//================================================================================================================//
	int k = 10;
	system("cls");
	Time();
	readfile_plane(mb);
main:
	box_nho(29, 8, 63, 7);
	box_nho(92, 3, 25, 3);
	box_nho(4, 3, 25, 3);
	gotoxy(50, 3);cout << "TINH NANG EDIT";
	gotoxy(5, 4);cout << "Nhan <ESC>thoat khong luu";
	for (int i = 0;i < 41;i++)
	{
		gotoxy(47 + i, 10);
		cout << " ";
	}
	gotoxy(30, 10);cout << "Nhap loai may bay: " << mb.dsmaybay[a[p]]->loaimaybay;
	for (int i = 0;i < 41;i++)
	{
		gotoxy(47 + i, 11);
		cout << " ";
	}
	gotoxy(30, 11);cout << "nhap so hieu: " << mb.dsmaybay[a[p]]->sohieu;
	for (int i = 0;i < 41;i++)
	{
		gotoxy(47 + i, 12);
		cout << " ";
	}
	gotoxy(30, 12);cout << "Nhap so cho: " << mb.dsmaybay[a[p]]->socho;
	gotoxy(30, 13);cout << "Luu va Thoat";
	gotoxy(25, k);cout << "==>";
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 10)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 13)
			{
				k += 1;
			}

		}
		if (c == 27)
		{
			system("cls");
			goto back;
		}
		if (k != 10)
		{
			gotoxy(25, k - 1);
			printf("   ");
		}
		if (k != 14)
		{
			gotoxy(25, k + 1);
			printf("  ");
		}
		cout << "  ";
		gotoxy(25, k);
		cout << "==>";
		//Sleep(200);
	} while (c != 13);
	fflush(stdin);
	switch (k)
	{
	case 10:
	{
		gotoxy(5, 4);cout << "Nhan <ESC> de quay lai   ";
		int i = 0;
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0;j <= 41;j++)
		{
			gotoxy(47 + j, 10);cout << " ";
		}
		//gotoxy(53, 8);
		do {
			tmp = block_char(41, 48, 10);
		} while (tmp[0] == '\0');
			if (tmp[0] == '.')
			{
				//system("cls");
				goto main;
			}
		while (tmp[i] != '\0')
		{
			mb.dsmaybay[a[p]]->loaimaybay[i] = tmp[i];
			i++;
			mb.dsmaybay[a[p]]->loaimaybay[i] = '\0';
		}
		break;
	}
	case 11:
	{ 
		gotoxy(5, 4);cout << "Nhan <ESC> de quay lai   ";
		char kmp[16];
		strcpy_s(kmp, mb.dsmaybay[a[p]]->sohieu);
		do
		{
			char* cmp = new char[100];
			int i = 0;
			int j = 0;
			for (int j = 0;j <= 41;j++)
			{
				gotoxy(43 + j, 11);cout << " ";
			}
			//gotoxy(53, 9);
			do {
				cmp = block_and_char(14, 48, 11);
			} while (cmp[0] == '\0');
			j = 0;
				if (cmp[0] == '.')
				{
				
					goto main;
				}
			while (cmp[i] != '\0')
			{
				mb.dsmaybay[a[p]]->sohieu[i] = cmp[i];
				i++;
				mb.dsmaybay[a[p]]->sohieu[i] = '\0';
			}
			if (same_test(mb, a[p]) == 1)
			{
				gotoxy(94, 4);
				cout << "nhap lai!";
				_getch();
				gotoxy(94, 4);cout << "           ";
			}
		} while (same_test(mb, a[p]) == 1);
		DS_CHUYEN_BAY v;
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, kmp) == 0)
			{
				//system("cls");
				//gotoxy(50, 13);
				strcpy_s(v->cb.sohieu, mb.dsmaybay[a[p]]->sohieu);
				system("cls");
			}
			v = v->next;
		}
		system("cls");
		break;
	}
	case 12:
	{
		gotoxy(5, 4);cout << "Nhan <ESC> de quay lai   ";
		int i = 0;
		char* kmp = new char[100];
		gotoxy(94, 4);
		cout << "So cho >=20";
		do
		{
			for (int j = 0;j <= 41;j++)
			{
				gotoxy(42 + j, 12);cout << " ";
			}
			//gotoxy(53, 10);
			i = 0;
			do {
				kmp = block_number(15, 53, 12);
			} while (kmp[0] == '\0');;
			int j = 0;
				if (kmp[0] == '.')
				{
					system("cls");
					goto main;
				}

			if (atoi(kmp) < 20)
			{
				gotoxy(94, 5);
				cout << "nhap lai!";
				_getch();
				gotoxy(94, 5);cout << "           ";
			}
		} while (atoi(kmp) < 20);
		mb.dsmaybay[a[p]]->socho = atoi(kmp);
		DS_CHUYEN_BAY v;
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, mb.dsmaybay[a[p]]->sohieu) == 0)
			{
				//system("cls");
				//gotoxy(50, 13);
				v->cb.ds_ve.n = mb.dsmaybay[a[p]]->socho;
				//system("cls");
			}
			v = v->next;
		}
		//system("cls");
		break;
	}
	case 13:
		system("cls");
		mb.sl--;
		gotoxy(48, 11);cout << "BAN CO CHAC LA LUU KHONG";
		if (yes_no(mb) == 0)
		{
			gotoxy(50, 13);
			writefile_flight(First);
			cout << "DA LUU";
			_getch();
			system("cls");
			goto back;
		}
		else { goto back; }
	}
	goto main;
}
int yes_no(DS_MAYBAY& mb)
{

	box_nho(46, 10, 30, 5);
	gotoxy(60, 12);cout << "YES";
	gotoxy(60, 13);cout << "NO";
	gotoxy(56, 12);cout << "=>";
	int k = 12;
	char c;
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 12)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 13)
			{
				k += 1;
			}

		}
		if (k > 12)
		{
			gotoxy(56, k - 1);
			printf("  ");
		}
		if (k < 13)
		{
			gotoxy(56, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoxy(56, k);
		cout << "=>";
		//Sleep(200);
	} while (c != 13);
	switch (k)
	{
	case 12:
		writefile_plane(mb);
		system("cls");
		return 0;
	case 13:
		return 1;
	}
}
char* block_char(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoxy(x, y);
	connhay_on();
	while (1)
	{
		c = _getch();
		if (i <= a && c >= 48 && c <= 122||c==32)
		{
			gotoxy(x + i, y);
			b[i] = c;
			cout << c;
			i++;
		}
		if (c == 8 && i > 0)
		{
			gotoxy(x + i - 1, y);
			cout << " ";
			gotoxy(x + i - 1, y);
			i--;
		}
		if (c == 27)
		{
			connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b;
		}
		if (c == 13)
		{
			connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}
char* block_number(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoxy(x, y);
	connhay_on();
	while (1)
	{
		c = _getch();
		if (i <= a && c >= 48 && c <= 57)
		{
			gotoxy(x + i, y);
			b[i] = c;
			cout << c;
			i++;
		}
		if (c == 8 && i > 0)
		{
			gotoxy(x + i - 1, y);
			cout << " ";
			gotoxy(x + i - 1, y);
			i--;
		}
		if (c == 27)
		{
			connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b;
		}
		if (c == 13)
		{
			connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}
char* block_and_char(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoxy(x, y);
	connhay_on();
	while (1)
	{
		c = _getch();
		if (i <= a && c >= 48 && c <= 122||c==32)
		{
			if (c >= 97 && c <= 122)
			{
				gotoxy(x + i, y);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoxy(x + i, y);
				b[i] = c;
				cout << c;
			}
			i++;
		}
		if (c == 27)
		{
			connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b ;
		}
		if (c == 8 && i > 0)
		{
			gotoxy(x + i - 1, y);
			cout << " ";
			gotoxy(x + i - 1, y);
			i--;
		}
		if (c == 13)
		{
			connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}
int search_choi(DS_MAYBAY& mb)
{
	char c;
back:
	system("cls");
	result_plane(mb);
	Time();
	int i = 0;
	int u = 0;
	int a[MAX];
	char* b = new char[26];
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	gotoxy(15, 3);cout << "Search SH:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoxy(27 + i, 3);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoxy(6, l + 7);
						cout << i;
						gotoxy(20, l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoxy(27 + i - 1, 3);
			cout << " ";
			gotoxy(27 + i - 1, 3);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoxy(6, k + 7);
						cout << i;
						gotoxy(20, k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				system("cls");
				result_plane(mb);
				gotoxy(15, 3);cout << "Search SH:";
				goto back;
				connhay_off();
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 27)
		{
			system("cls");
			return 0;
		}
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0;i < u - 1;i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
	//=================================================================================================================//
	box_nho(100, 27, 15, 2);
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoxy(0, f - 1);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoxy(0, f + 1);
			printf("  ");
		}
		if (f == 25 && tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	system("cls");
	return a[p];
}
void xem_maybay(DS_MAYBAY& mb)
{
	char c;
back:
	system("cls");
	gotoxy(90, 3);cout << "XEM DANH SACH";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	result_plane(mb);
	Time();
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search SH:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoxy(27 + i, 3);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoxy(6, l + 7);
						cout << i;
						gotoxy(20, l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoxy(27 + i - 1, 3);
			cout << " ";
			gotoxy(27 + i - 1, 3);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoxy(6, k + 7);
						cout << i;
						gotoxy(20, k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoxy(75, k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoxy(103, k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				system("cls");
				result_plane(mb);
				gotoxy(15, 3);cout << "Search SH:";
				connhay_off();
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0;i < u - 1;i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
    box_nho(100, 27, 15, 2);
	kay:
	f = 7;box_nho(100, 27, 15, 2);

	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}
		//if (f<=7&&c==72)goto back;
		if (f != 7)
		{
			gotoxy(0, f - 1);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoxy(0, f + 1);
			printf("  ");
		}
		if (f == 25 && tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 50;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 39;i++)
				{
					gotoxy(61 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 10;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18;i < mb.sl - 1 && i <= 18 + trang * 18;i++)
			{
				gotoxy(6, k + 7);
				cout << i;
				gotoxy(20, k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoxy(75, k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoxy(103, k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 27);
	system("cls");
}