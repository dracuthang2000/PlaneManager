#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include "plane.h"
#include "mylib.h"
#include "AVLtree.h"
#include"flight.h"
#include"bookticket.h"
#include"Box.h"
void in_ds(int x, int* b);
void in(tree& t, string key, int l)
{
	tree p = t;
	do
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			if (p->cmnd == key)
			{
				gotoxy(50, 7 + l);cout << p->ho << " " << p->ten;
				gotoxy(106, 7 + l);cout << p->sex;
				return;
			}
			else if (p->cmnd < key)
			{
				p = p->pRight;
			}
			else if (p->cmnd > key)
			{
				p = p->pLeft;
			}
		}
	} while (1);
}
void in_cb(DS_CHUYEN_BAY& First, DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_MAYBAY& mb, chuyenbay* ds_cb[])
{
back:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	system("cls");
	box_nho(5, 27, 11, 2);
	gotoxy(6, 28);printf("<ESC> thoat");
	Box_tong();
	box_key(4);
	box_key(6);
	box_kex(9,4);
	box_noih(9, 4);
	box_noio(9, 6);
	box_kex(24,4);
	box_noih(24, 4);
	box_noio(24, 6);
	box_kex(38,4);
	box_noih(38,4);
	box_noio(38, 6);
	box_kex(47, 4);
	box_noih(47, 4);
	box_noio(47, 6);
	box_kex(68, 4);
	box_noih(68, 4);
	box_noio(68, 6);
	box_kex(74, 4);
	box_noih(74, 4);
	box_noio(74, 6);
	box_kex(80, 4);
	box_noih(80, 4);
	box_noio(80, 6);
	box_kex(86, 4);
	box_noih(86, 4);
	box_noio(86, 6);
	box_kex(91, 4);
	box_noih(91, 4);
	box_noio(91, 6);
	box_kex(96, 4);
	box_noih(96, 4);
	box_noio(96, 6);
	box_kex(102, 4);
	box_noih(102, 4);
	box_noio(102, 6);
	Time();
	readfile_cb(First);
	readfile_plane(mb);
	read_hk(ds_hk.TREE);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search_CB:";
	connhay_on();
	do
	{
		c = _getch();
		connhay_on();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoxy(27 + i, 3);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoxy(27 + i, 3);
				b[i] = c;
				cout << c;
			}
			i++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 7;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26)break;
						gotoxy(5, l);
						cout << i;
						for (int j = 0;j < mb.sl - 1;j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoxy(10, l);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
						gotoxy(25, l);
						cout << ds_cb[i]->machuyenbay;
						gotoxy(40, l);
						cout << ds_cb[i]->sohieu;
						gotoxy(55, l);
						cout << ds_cb[i]->sanbay;
						gotoxy(70, l);
						cout << ds_cb[i]->ngay;
						gotoxy(77, l);
						cout << ds_cb[i]->thang;
						gotoxy(81, l);
						cout << ds_cb[i]->nam;
						gotoxy(88, l);
						cout << ds_cb[i]->gio;
						gotoxy(93, l);
						cout << ds_cb[i]->phut;
						gotoxy(98, l);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104, l);
						l++;
					}
				}
			}
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
			int k = 7;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26)break;
						gotoxy(5, k);
						cout << i;
						for (int j = 0;j < mb.sl - 1;j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoxy(10, k);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoxy(25, k);
						cout << ds_cb[i]->machuyenbay;
						gotoxy(40, k);
						cout << ds_cb[i]->sohieu;
						gotoxy(55, k);
						cout << ds_cb[i]->sanbay;
						gotoxy(70, k);
						cout << ds_cb[i]->ngay;
						gotoxy(77, k);
						cout << ds_cb[i]->thang;
						gotoxy(81, k);
						cout << ds_cb[i]->nam;
						gotoxy(88, k);
						cout << ds_cb[i]->gio;
						gotoxy(93, k);
						cout << ds_cb[i]->phut;
						gotoxy(98, k);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104, k);
						k++;
					}
				}
				//gotoxy(27 + i, 3);
				//connhay_on();
			}
			if (b[0] == '\0')
			{
				result_flight(First, ds_cb);
				connhay_off();
			}
			gotoxy(27 + i, 3);
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = dem(First);
		for (int i = 0;i < u;i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;
	box_nho(100, 27, 15, 2);
key://============================================================================================================//
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
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			k = 7;
			for (int i = trang * 18 + 0;i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, k);
				cout << i;
				for (int j = 0;j < mb.sl - 1;j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoxy(10, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoxy(25, k);
				cout << ds_cb[i]->machuyenbay;
				gotoxy(40, k);
				cout << ds_cb[i]->sohieu;
				gotoxy(55, k);
				cout << ds_cb[i]->sanbay;
				gotoxy(70, k);
				cout << ds_cb[i]->ngay;
				gotoxy(77, k);
				cout << ds_cb[i]->thang;
				gotoxy(81, k);
				cout << ds_cb[i]->nam;
				gotoxy(88, k);
				cout << ds_cb[i]->gio;
				gotoxy(93, k);
				cout << ds_cb[i]->phut;
				gotoxy(98, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104, k);
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
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			k = 7;
			for (int i = trang * 18 + 0;i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, k);
				cout << i;
				for (int j = 0;j < mb.sl - 1;j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoxy(10, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoxy(25, k);
				cout << ds_cb[i]->machuyenbay;
				gotoxy(40, k);
				cout << ds_cb[i]->sohieu;
				gotoxy(55, k);
				cout << ds_cb[i]->sanbay;
				gotoxy(70, k);
				cout << ds_cb[i]->ngay;
				gotoxy(77, k);
				cout << ds_cb[i]->thang;
				gotoxy(81, k);
				cout << ds_cb[i]->nam;
				gotoxy(88, k);
				cout << ds_cb[i]->gio;
				gotoxy(93, k);
				cout << ds_cb[i]->phut;
				gotoxy(98, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104, k);
				k++;
			}
			goto key;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13||ds_cb[a[p]]->trangthai == 3 || ds_cb[a[p]]->trangthai == 0);
	//========================================================================================================
	system("cls");
	Time();
	Box_tong();
	box_key(4);
	box_key(6);
	box_kex(9, 4);
	box_noih(9, 4);
	box_noio(9, 6);
	box_kex(16, 4);
	box_noih(16, 4);
	box_noio(16, 6);
	box_kex(38, 4);
	box_noih(38, 4);
	box_noio(38, 6);
	box_kex(100, 4);
	box_noih(100, 4);
	box_noio(100, 6);
	gotoxy(40, 2);cout << "DANH SACH HANH KHACH THUOC CHUYEN BAY " << ds_cb[a[p]]->machuyenbay;
	gotoxy(40, 3);cout << "Ngay gio khoi hanh: " << ds_cb[a[p]]->ngay << "/" << ds_cb[a[p]]->thang << "/" << ds_cb[a[p]]->nam << " " << ds_cb[a[p]]->gio << ":" << ds_cb[a[p]]->phut << "." << "  " << "Noi den: " << ds_cb[a[p]]->sanbay;
	gotoxy(5, 5);
	cout << "STT";
	gotoxy(10, 5);
	cout << "So ve";
	gotoxy(18, 5);
	cout << "Chung minh nhan dan";
	gotoxy(60, 5);
	cout << "Ho va ten";
	gotoxy(106, 5);
	cout << "Phai";
	box_nho(5, 27, 11, 2);
	box_nho(20, 27, 6, 2);gotoxy(23, 28);cout << "<-";
	gotoxy(6, 28);printf("<ESC> thoat");
	box_nho(30, 27, 6, 2);gotoxy(33, 28);cout << "->";

	//===============================================================================================//
	int trang1 = 0;
	int tongt = 0;
	if (ds_cb[a[p]]->ds_ve.sl_da_ban == 18)
	{
		tongt = 1;
	}
	else
	{
		tongt = (ds_cb[a[p]]->ds_ve.sl_da_ban)/18 + 1;
	}
	int lt = 0;
	int* tam = new int[ds_cb[a[p]]->ds_ve.sl_da_ban];
	for (int i = 1;i <= ds_cb[a[p]]->ds_ve.n;i++)
	{
		if (ds_cb[a[p]]->ds_ve.cmnd[i].length() == 9)
		{
			tam[lt] = i;
			lt++;
		}
	}
back1:
	int dem = 0;
	for (int i = trang1*18;i < ds_cb[a[p]]->ds_ve.sl_da_ban && i <= trang1 * 18 + 18; i++)
	{
		if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam[i]]) == 1)
		{
			gotoxy(5, 7 + dem);cout << i;
			gotoxy(19, 7 + dem);cout << ds_cb[a[p]]->ds_ve.cmnd[tam[i]];
			in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam[i]], dem);
			gotoxy(11, 7 + dem);cout << tam[i];
			dem++;
		}
	}
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang1 + 1 << "/" << tongt;
	while (1)
	{
		c = _getch();
		if(c==77)
		{
			if (tongt > 1 && trang1 + 1 < tongt)
			{
				int j = 0;
				trang1++;
				while (j <= 18)
				{
					for (int i = 0;i < 4;i++)
					{
						gotoxy(5 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 5;i++)
					{
						gotoxy(11 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 21;i++)
					{
						gotoxy(17 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 61;i++)
					{
						gotoxy(39 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 10;i++)
					{
						gotoxy(101 + i, j + 7);
						cout << " ";
					}
					j++;
				}
				goto back1;
			}
		}
		else if (c == 75)
		{
			if (tongt > 1 && trang1 > 0)
			{
				int j = 0;
				trang1--;
				while (j <= 18)
				{
					for (int i = 0;i < 4;i++)
					{
						gotoxy(5 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 5;i++)
					{
						gotoxy(11 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 21;i++)
					{
						gotoxy(17 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 61;i++)
					{
						gotoxy(39 + i, j + 7);
						cout << " ";
					}
					for (int i = 0;i < 10;i++)
					{
						gotoxy(101 + i, j + 7);
						cout << " ";
					}
					j++;
				}
				goto back1;
			}
		}
		else if (c == 27)
		{
			goto back;
		}
	}
}
void in_date(DS_CHUYEN_BAY& First)
{
	box_nho(5, 27, 11, 2);
	gotoxy(6, 28);printf("<ESC> thoat");
	Box_tong();
	box_key(4);
	box_key(6);
	box_kex(9, 4);
	box_noih(9, 4);
	box_noio(9, 6);
	box_kex(24, 4);
	box_noih(24, 4);
	box_noio(24, 6);
	box_kex(40, 4);
	box_noih(40, 4);
	box_noio(40, 6);
	box_kex(100, 4);
	box_noih(100, 4);
	box_noio(100, 6);
	gotoxy(5, 5);cout << "STT";
	gotoxy(11, 5);cout << "Ma chuyen Bay";
	gotoxy(25, 5);cout << "So ve con trong";
	gotoxy(50, 5);cout << "Noi den";
	gotoxy(101, 5);cout << "Gio:Phut";
	readfile_cb(First);
	//gotoxy()
	char* tam = new char[20];
	int n, t, m;
	int i = 0;
	gotoxy(40, 3);
	cout << "Ngay: ";
	gotoxy(50, 3);
	cout << "Thang: ";
	gotoxy(62, 3);
	cout << "Nam: ";
	tam = block_number(1, 47, 3);
	if (tam[0] == '.')return;
	gotoxy(47, 3);cout << tam;
	n = atoi(tam);
	tam = block_number(1, 58, 3);
	gotoxy(58, 3);cout << tam;
	t = atoi(tam);
	tam = block_number(3, 67, 3);
	gotoxy(67, 3);cout << tam;
	m = atoi(tam);
	DS_CHUYEN_BAY p;
	p = First;
	i = 0;
	box_nho(5, 27, 11, 2);
	box_nho(20, 27, 6, 2);gotoxy(23, 28);cout << "<-";
	gotoxy(6, 28);printf("<ESC> thoat");
	box_nho(30, 27, 6, 2);gotoxy(33, 28);cout << "->";
	chuyenbay* tim1[MAX];
	while (p != NULL)
	{
		if (p->cb.ngay == n && p->cb.thang == t && p->cb.nam == m && p->cb.trangthai != 0)
		{
			tim1[i] = new chuyenbay;
			strcpy_s(tim1[i]->machuyenbay, p->cb.machuyenbay);
			strcpy_s(tim1[i]->sanbay, p->cb.sanbay);
			tim1[i]->ds_ve.sl_con = p->cb.ds_ve.sl_con;
			tim1[i]->gio = p->cb.gio;
			tim1[i]->phut = p->cb.phut;
			i++;
		}
		p = p->next;
	}
	if (i > 0)
	{
		int trang = 0;int tong = 0;
		if (i == 18)
		{
			tong = 1;
		}
		else
		{
			tong = i / 18 + 1;
		}
	back1:
		int k = 0;
		for (int j = trang * 18 + 0;j < i && j <= trang * 18 + 18;j++)
		{
			gotoxy(6, 7 + k);cout << j;
			gotoxy(11, 7 + k);cout << tim1[j]->machuyenbay;
			gotoxy(25, 7 + k);cout << tim1[j]->ds_ve.sl_con;
			gotoxy(42, 7 + k);cout << tim1[j]->sanbay;
			gotoxy(102, 7 + k);cout << tim1[j]->gio << ":" << tim1[j]->phut;
			k++;
		}
		box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		char c;
		while (1)
		{
			c = _getch();
			if (c == 77)
			{
				if (tong > 1 && trang + 1 < tong)
				{
					int j = 0;
					trang++;
					while (j <= 18)
					{
						for (int i = 0;i < 4;i++)
						{
							gotoxy(5 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 14;i++)
						{
							gotoxy(10 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 15;i++)
						{
							gotoxy(25 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 59;i++)
						{
							gotoxy(41 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 10;i++)
						{
							gotoxy(101 + i, j + 7);
							cout << " ";
						}
						j++;
					}
					goto back1;
				}
			}
			else if (c == 75)
			{
				if (tong > 1 && trang > 0)
				{
					int j = 0;
					trang--;
					while (j <= 18)
					{
						for (int i = 0;i < 4;i++)
						{
							gotoxy(5 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 14;i++)
						{
							gotoxy(10 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 15;i++)
						{
							gotoxy(25 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 59;i++)
						{
							gotoxy(41 + i, j + 7);
							cout << " ";
						}
						for (int i = 0;i < 10;i++)
						{
							gotoxy(101 + i, j + 7);
							cout << " ";
						}
						j++;
					}
					goto back1;
				}
			}
			else if (c == 27)
			{
				break;
			}
		}
		for (int j = 0;j < i;j++)
		{
			delete tim1[j];
			tim1[j] = NULL;
		}
	}
	else
	{
		system("cls");
		box_nho(10, 13, 100, 3);
		gotoxy(12, 14);cout << "Khong co chuyen bay nao trong ngay: " << n << " thang: " << t << " nam: " << m;
		_getch();
		system("cls");
	}
}
void in_ve(DS_CHUYEN_BAY& First, DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_MAYBAY& mb, chuyenbay* ds_cb[])
{
back:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	Time();
	box_nho(5, 27, 11, 2);
	gotoxy(6, 28);printf("<ESC> thoat");
	readfile_cb(First);
	readfile_plane(mb);
	read_hk(ds_hk.TREE);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search_CB:";
	connhay_on();
	do
	{
		c = _getch();
		connhay_on();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoxy(27 + i, 3);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoxy(27 + i, 3);
				b[i] = c;
				cout << c;
			}
			i++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int l = 7;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26)break;
						gotoxy(5, l);
						cout << i;
						for (int j = 0;j < mb.sl - 1;j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoxy(10, l);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
						gotoxy(25, l);
						cout << ds_cb[i]->machuyenbay;
						gotoxy(40, l);
						cout << ds_cb[i]->sohieu;
						gotoxy(55, l);
						cout << ds_cb[i]->sanbay;
						gotoxy(70, l);
						cout << ds_cb[i]->ngay;
						gotoxy(77, l);
						cout << ds_cb[i]->thang;
						gotoxy(81, l);
						cout << ds_cb[i]->nam;
						gotoxy(88, l);
						cout << ds_cb[i]->gio;
						gotoxy(93, l);
						cout << ds_cb[i]->phut;
						gotoxy(98, l);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104, l);
						l++;
					}
				}
			}
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
			int k = 7;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26)break;
						gotoxy(5, k);
						cout << i;
						for (int j = 0;j < mb.sl - 1;j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoxy(10, k);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoxy(25, k);
						cout << ds_cb[i]->machuyenbay;
						gotoxy(40, k);
						cout << ds_cb[i]->sohieu;
						gotoxy(55, k);
						cout << ds_cb[i]->sanbay;
						gotoxy(70, k);
						cout << ds_cb[i]->ngay;
						gotoxy(77, k);
						cout << ds_cb[i]->thang;
						gotoxy(81, k);
						cout << ds_cb[i]->nam;
						gotoxy(88, k);
						cout << ds_cb[i]->gio;
						gotoxy(93, k);
						cout << ds_cb[i]->phut;
						gotoxy(98, k);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104, k);
						k++;
					}
				}
				//gotoxy(27 + i, 3);
				//connhay_on();
			}
			if (b[0] == '\0')
			{
				result_flight(First, ds_cb);
				connhay_off();
			}
			gotoxy(27 + i, 3);
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off();
	if (u == 0)
	{
		u = dem(First);
		for (int i = 0;i < u;i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;
	//int tr = 0;
key://============================================================================================================//
	f = 7;
	box_nho(100, 27, 15, 2);
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f == 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang--;
			//tr--;
			//gotoxy(108, 28);cout << tr;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			k = 7;
			for (int i = trang * 18 + 0;i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, k);
				cout << i;
				for (int j = 0;j < mb.sl - 1;j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoxy(10, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoxy(25, k);
				cout << ds_cb[i]->machuyenbay;
				gotoxy(40, k);
				cout << ds_cb[i]->sohieu;
				gotoxy(55, k);
				cout << ds_cb[i]->sanbay;
				gotoxy(70, k);
				cout << ds_cb[i]->ngay;
				gotoxy(77, k);
				cout << ds_cb[i]->thang;
				gotoxy(81, k);
				cout << ds_cb[i]->nam;
				gotoxy(88, k);
				cout << ds_cb[i]->gio;
				gotoxy(93, k);
				cout << ds_cb[i]->phut;
				gotoxy(98, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104, k);
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
		if (f == 25 && tong > 1 && trang + 1 < tong&&c==80)
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
				for (int i = 0;i < 14;i++)
				{
					gotoxy(10 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 13;i++)
				{
					gotoxy(25 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 8;i++)
				{
					gotoxy(39 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 20;i++)
				{
					gotoxy(48 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(69 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(75 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(81 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(87 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(92 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 4;i++)
				{
					gotoxy(97 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 5;i++)
				{
					gotoxy(103 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 12;i++)
				{
					gotoxy(104 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			k = 7;
			for (int i = trang * 18 + 0;i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, k);
				cout << i;
				for (int j = 0;j < mb.sl - 1;j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoxy(10, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoxy(25, k);
				cout << ds_cb[i]->machuyenbay;
				gotoxy(40, k);
				cout << ds_cb[i]->sohieu;
				gotoxy(55, k);
				cout << ds_cb[i]->sanbay;
				gotoxy(70, k);
				cout << ds_cb[i]->ngay;
				gotoxy(77, k);
				cout << ds_cb[i]->thang;
				gotoxy(81, k);
				cout << ds_cb[i]->nam;
				gotoxy(88, k);
				cout << ds_cb[i]->gio;
				gotoxy(93, k);
				cout << ds_cb[i]->phut;
				gotoxy(98, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104, k);
				k++;
			}
			//f = 7;
			goto key;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13 || ds_cb[a[p]]->trangthai == 3 || ds_cb[a[p]]->trangthai == 0);
	system("cls");
	int k, x, y;
	k = ds_cb[a[p]]->ds_ve.n;
	int* v = new int[k];
	int o = 1;
	for (int j = 1;j < ds_cb[a[p]]->ds_ve.n + 1;j++)
	{
		if (ds_cb[a[p]]->ds_ve.cmnd[j].length() == 9)
		{
			v[o] = j;
			o++;
		}
	}
	box_nho(0, 0, 41, 25);
	box_kexy(0, 3, 41);
	box_nho(60, 5, 41, 20);
	box_kexy(60, 8, 41);
	box_nho(5, 27, 11, 2);
	gotoxy(6, 28);printf("<ESC> thoat");
	gotoxy(75, 7);cout << "CHU THICH";
	gotoxy(67, 10);cout << "VE TO MAU DO LA VE DA BAN";
	gotoxy(1, 1);cout << "SO VE CON TRONG CUA CHUYEN BAY: " << ds_cb[a[p]]->machuyenbay;
	gotoxy(14, 2);cout << "VE CON TRONG LA: " << ds_cb[a[p]]->ds_ve.sl_con;
	in_ds(k, v);
	while (c != 27)
	{
		c = _getch();
	}
	system("cls");
	goto back;
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void quickSort(int Data[], int l, int r)
{
	if (l <= r)
	{
		int key = Data[(l + r) / 2];
		int i = l;
		int j = r;

		while (i <= j)
		{
			while (Data[i] > key)
				i++;
			while (Data[j] < key)
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}
		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}
void sap_xep(DS_CHUYEN_BAY& First, DS_MAYBAY& mb)
{
	readfile_cb(First);
	readfile_plane(mb);
	box_nho(5, 27, 11, 2);
	gotoxy(6, 28);printf("<ESC> thoat");
	box_nho(20, 5, 80, 21);
	box_nho(20, 2, 80, 2);gotoxy(35,3);cout << "THONG KE VA SAP XEP SO LUOT THU HIEN CHUYEN BAY";
	gotoxy(60, 5);cout << char(194);
	box_kexy(20, 8, 80);
	gotoxy(60, 8);cout << char(197);
	box_kex(60, 5);
	gotoxy(30, 6);cout << "SO HIEU MAY BAY";
	gotoxy(65, 6);cout << "SO LUOT THUC HIEN CHUYEN BAY";
	box_nho(5, 27, 11, 2);
	box_nho(20, 27, 6, 2);gotoxy(23, 28);cout << "<-";
	gotoxy(6, 28);printf("<ESC> thoat");
	box_nho(30, 27, 6, 2);gotoxy(33, 28);cout << "->";
	DS_CHUYEN_BAY p;
	int k = 0;
	int* a;
	int* tam = new int[MAX];
	a = new int[mb.sl - 2];
	for (int i = 0;i < mb.sl - 1;i++)
	{
		p = First;
		k = 0;
		while (p != NULL)
		{
			if (_strcmpi(mb.dsmaybay[i]->sohieu, p->cb.sohieu) == 0)
			{
				k++;
			}
			p = p->next;
		}
		a[i] = k;
	}
	for (int j = 0;j < mb.sl - 1;j++)
	{
		tam[j] = a[j];
	}
	quickSort(a, 0, mb.sl - 2);
	may_bay* Mtam[MAX];
	for (int i = 0;i < MAX;i++)
	{
		Mtam[i] = new may_bay;
		Mtam[i] = mb.dsmaybay[i];
	}
	int trang = 0;
	int tong = 0;
	if (mb.sl == 15)
	{
		tong = 1;
	}
	else { tong = mb.sl / 15 + 1; }
	int i = 0;
	int j = 0;
	int l = 0;
	char** tam3;
	tam3 = new char*[16];
	while (j < mb.sl - 1)
	{
		if (tam[i] == a[j] && Mtam[i] != NULL)
		{
			tam3[j] = new char[16];
			k = 0;
			while (Mtam[i]->sohieu[k] != '\0')
			{
				tam3[j][k] = Mtam[i]->sohieu[k];
				k++;
				tam3[j][k] = '\0';
			}
			delete Mtam[i];
			Mtam[i] = NULL;
			i = 0;
			j++;
		}
		i++;
	}
	int m = 0;
	connhay_off();
	back1:
	l = 0;
	for (int i = 15 * trang;i < mb.sl - 1 && i <= trang * 15 + 15;i++)
	{
		m = 0;
		gotoxy(40, 9 + l);
		while (tam3[i][m] != '\0')
		{
			cout << tam3[i][m];
			m++;
		}
		gotoxy(80, 9 + l);cout << a[i];
		l++;
	}
	char c;
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	while (1)
	{
		c = _getch();
		if (c == 77)
		{
			if (tong > 1 && trang + 1 < tong)
			{
				int j = 0;
				trang++;
				while (j <= 15)
				{
					for (int i = 21;i < 60;i++)
					{
						gotoxy(i, j + 9);
						cout << " ";
					}
					for (int i = 61;i < 90;i++)
					{
						gotoxy(i, j + 9);
						cout << " ";
					}
					j++;
				}
				goto back1;
			}
		}
		else if (c == 75)
		{
			if (tong > 1 && trang > 0)
			{
				int j = 0;
				trang--;
				while (j <= 15)
				{
					for (int i = 21;i < 60;i++)
					{
						gotoxy(i, j + 9);
						cout << " ";
					}
					for (int i = 61;i < 80;i++)
					{
						gotoxy(i, j + 9);
						cout << " ";
					}
					j++;
				}
				goto back1;
			}
		}
		else if (c == 27)
		{
			break;
		}
	}
}
