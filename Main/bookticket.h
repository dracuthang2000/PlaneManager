#pragma once
#include<iostream>
#include"H:\Thang\CTDL\DETAI\mylib.h"
#include<iomanip>
#include"flight.h"
#include"thongke.h"
string cmnd_trong(tree root,string t);
int insert_hanhkhach_datve(DS_HANH_KHACH& ds_hk, string cmnd);
int same_testcmnd(tree t, string key);
int yes_no_ve();
int lua_chon_gt();
using namespace std;
void in_ds(int a,int *b)
{
	int j=1;
	int k = 6;
	int *f=new int[a];
	gotoxy(1, 5);
	for (int i = 1; i <= a; i++)
	{
		if (b[j] == i)
		{
			SetBGColor(12);
			cout << setw(4) <<i;
			//b[i] = b[j];
			//f[j] = b[j];
			j++;
		}
		else
		{
			SetBGColor(0);
			cout << setw(4) << i;	
		}
		if (i % 10 == 0)
		{
			gotoxy(1, k);
			k++;
		}
	}
}
void ktra_trung(int x, int y, chuyenbay ds_cb[], tree t)
{
	int i = 10 * (y - 1) + x;
	if (t != NULL)
	{
		if (ds_cb->ds_ve.cmnd[i] == t->cmnd)
		{
			gotoxy(70, 12);
			cout << "Chung Minh Nhan dan: " << t->cmnd;
			gotoxy(70, 13);
			cout <<"Ho: "<< t->ho;
			gotoxy(70, 14);
			cout <<"Ten: "<< t->ten;
			gotoxy(70, 15);
			cout << "Gioi tinh: " << t->sex;
		}
		ktra_trung(x, y, ds_cb, t->pLeft);
		ktra_trung(x, y, ds_cb, t->pRight);
	}
}
void ktra_lay(string cmnd,tree t)
{
	if (t != NULL)
	{
		if (cmnd == t->cmnd)
		{
			gotoxy(70, 12);
			cout << "Chung Minh Nhan dan: " << t->cmnd;
			gotoxy(70, 13);
			cout << "Ho: " << t->ho;
			gotoxy(70, 14);
			cout << "Ten: " << t->ten;
			gotoxy(70, 15);
			cout << "Gioi tinh: " << t->sex;
		}
		ktra_lay(cmnd, t->pLeft);
		ktra_lay(cmnd, t->pRight);
	}
}
void thongtin(int x, int y,chuyenbay ds_cb[],tree t)
{
	Time();
	int i = 0;
	int j = 0;
		while (i < 12)
		{
			gotoxy(61 + j, 9 + i);
			cout << " ";
			j++;
			if (j == 40)
			{
				i++;
				j = 0;
			}
		}
		ktra_trung(x, y, ds_cb, t);
}
void clear_nho()
{
	int i = 0;
	int j = 0;
	while (i < 12)
	{
		gotoxy(61 + j, 9 + i);
		cout << " ";
		j++;
		if (j == 40)
		{
			i++;
			j = 0;
		}
	}
}
int dieu_khien(int x, int y, int a,int *b, chuyenbay ds_cb[],DS_HANH_KHACH &ds_hk,DS_CHUYEN_BAY &First)
{
	main:
	x = wherex();
	y = wherey();
	int x1 = 1, y1 = 1, j = 1;
	int key;
	string cmnd;
	do
	{
		key = _getch();
		if ((int)key == 72 && y > 5)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j=j-10;
				gotoxy(x - 4, y);
				SetBGColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4;
				y = wherey() - 1;
				y1--;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb,ds_hk.TREE);
				gotoxy(x, y);
			}
			else
			{
				j = j - 10;
				gotoxy(x - 4, y);
				SetBGColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4;
				y = wherey() - 1;
				y1--;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
		}
		if ((int)key == 80 && y < a / 10 + 5 && 10 * (y1 - 1) + x1 + 9 < a)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j = j + 10;
				gotoxy(x - 4, y);
				SetBGColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4;
				y = wherey() + 1;
				y1++;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
			else 
			{
				j = j + 10;
				gotoxy(x - 4, y);
				SetBGColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4;
				y = wherey() + 1;
				y1++;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
		}
		if ((int)key == 75 && x > 5)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j--;
				gotoxy(x - 4, y);
				SetBGColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4 - 4;
				y = wherey();
				x1--;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
			else
			{
				j--;
				gotoxy(x - 4, y);
				SetBGColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex() - 4 - 4;
				y = wherey();
				x1--;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
		}
		if ((int)key == 77 && x < (4 * 10) && 10 * (y1 - 1) + x1 < a)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j++;
				gotoxy(x - 4, y);
				SetBGColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex();
				y = wherey();
				x1++;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
			else
			{
				j++;
				gotoxy(x - 4, y);
				SetBGColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = wherex();
				y = wherey();
				x1++;
				gotoxy(x, y);
				SetBGColor(13);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = wherey();
				x = wherex();
				SetBGColor(0);
				thongtin(x1, y1,ds_cb, ds_hk.TREE);
				gotoxy(x, y);
			}
		}
		if (key == 27)
		{
			system("cls");
			return 1;
		}
	} while (key != 13|| b[j]== 10 * (y1 - 1) + x1);
	int i = 10 * (y1 - 1) + x1;
	gotoxy(66, 11);cout << "Ban co chung minh nhan dan khong!";
	if (yes_no_ve() == 0)
	{
		clear_nho();
		string cmnd;
		cmnd=cmnd_trong(ds_hk.TREE, "000000000");
		if (insert_hanhkhach_datve(ds_hk, cmnd) == 0)return 0;
		ds_cb->ds_ve.cmnd[i] = cmnd;
		ds_cb->ds_ve.sl_da_ban = ds_cb->ds_ve.sl_da_ban + 1;
		ds_cb->ds_ve.sl_con = ds_cb->ds_ve.sl_con - 1;
		if (ds_cb->ds_ve.sl_con != 0)// hieu chinh trang thai.
		{
			ds_cb->trangthai = 1;
		}
		else if (ds_cb->ds_ve.sl_con == 0)
		{
			ds_cb->trangthai = 2;
		}
	}
	else
	{
		int u = 0;
		clear_nho();
		gotoxy(70, 12);
		cout << "Chung Minh Nhan Dan: ";
		do {
			for (int i = 1;i <= 9;i++)
			{
				gotoxy(89 + i, 12);
				cout << " ";
			}
			cmnd = block_number(8, 90, 12);
			if (cmnd[u] == '.')
			{
				system("cls");
				return 0;
			}
			if (cmnd.length() != 9)
			{
				gotoxy(90, 12);
				cout << "khong hop le";
				_getch();
			}
			u++;
		} while (cmnd[0] == '\0' || cmnd.length() != 9);
		for (int k = 0;k < ds_cb->ds_ve.n + 1;k++)//kiem tra xem co cmnd nay tren chuyen bay chua
		{
			if (ds_cb->ds_ve.cmnd[k] == cmnd)
			{
				system("cls");
				box_nho(10, 13, 100, 3);
				gotoxy(30, 14);cout << "Quy khach da dat ve tren chuyen bay nay roi!";
				_getch();
				system("cls");
				return 1;
			}
		}
		DS_CHUYEN_BAY v = First;
		while (v != NULL)
		{
			if (v->cb.trangthai != 3 || v->cb.trangthai != 0)
			{
				for (int i = 0;i <= v->cb.ds_ve.n;i++)
				{
					if (cmnd == v->cb.ds_ve.cmnd[i])
					{
						if (v->cb.ngay == ds_cb->ngay && abs(v->cb.gio - ds_cb->gio < 10))
						{
							system("cls");
							box_nho(10, 13, 100, 3);
							gotoxy(15, 14);cout << "Quy Khac da co chuyen bay khac o 10 gio truoc, xin vui long huy ve truoc va dat lai sau!";
							_getch();
							return 1;
						}
					}
				}
			}
			v = v->next;
		}
		if (same_testcmnd(ds_hk.TREE, cmnd) == 1)// kiem tra xem cmnd co ton tai hay chua
		{
			clear_nho();
			ktra_lay(cmnd, ds_hk.TREE);
			_getch();
			system("cls");
			ds_cb->ds_ve.cmnd[i] = cmnd;                         //ghi vao chuyen bay
			ds_cb->ds_ve.sl_da_ban = ds_cb->ds_ve.sl_da_ban + 1;
			ds_cb->ds_ve.sl_con = ds_cb->ds_ve.sl_con - 1;
			if (ds_cb->ds_ve.sl_con != 0)// hieu chinh trang thai.
			{
				ds_cb->trangthai = 1;
			}
			else if (ds_cb->ds_ve.sl_con == 0)
			{
				ds_cb->trangthai = 2;
			}
		}
		else
		{
			//clear_nho();
			if(insert_hanhkhach_datve(ds_hk, cmnd)==0)return 0;
			ds_cb->ds_ve.cmnd[i] = cmnd;
			ds_cb->ds_ve.sl_da_ban = ds_cb->ds_ve.sl_da_ban + 1;
			ds_cb->ds_ve.sl_con = ds_cb->ds_ve.sl_con - 1;
			if (ds_cb->ds_ve.sl_con != 0)// hieu chinh trang thai.
			{
				ds_cb->trangthai = 1;
			}
			else if (ds_cb->ds_ve.sl_con == 0)
			{
				ds_cb->trangthai = 2;
			}
		}
	}
	system("cls");
	return 1;
}
void datve(DS_CHUYEN_BAY& First, chuyenbay* ds_cb[], DS_HANH_KHACH& ds_hk, DS_MAYBAY& mb)
{
back:
	system("cls");
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	Time();
	readfile_cb(First);
	readfile_plane(mb);
	read_hk(ds_hk.TREE);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);gotoxy(90, 3);cout << "TINH NANG DAT VE";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	connhay_on();
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
	gotoxy(101, 28);
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search_CB:";
	//result_flight(First);
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
	} while (c != 13|| ds_cb[a[p]]->trangthai == 3 || ds_cb[a[p]]->trangthai == 0);

	system("cls");
	chuyenbay cb;
		int k, x, y;
		k = ds_cb[a[p]]->ds_ve.n;
		int* v = new int[k];
		int* ft = new int[k];
		int o = 1;
		for (int j = 1;j < ds_cb[a[p]]->ds_ve.n + 1;j++)
		{
			if (ds_cb[a[p]]->ds_ve.cmnd[j].length() == 9)
			{
				v[o] = j;
				o++;
			}
		}
		back1:
		system("cls");
		box_nho(5, 27, 15, 2);
		gotoxy(6, 28);printf("<ESC> Quay lai");
		box_nho(22, 27, 16, 2);
		gotoxy(24, 28);cout << "<ENTER> de chon";
		cout << endl;
		box_nho(0, 0, 41, 25);
		box_kexy(0, 3, 41);
		box_nho(60, 5, 41, 20);
		box_kexy(60, 8, 41);
		gotoxy(75, 7);cout << "THONG TIN";
		gotoxy(1, 1);cout << "DAT VE CUA CHUYEN BAY: " << ds_cb[a[p]]->machuyenbay;
		gotoxy(1, 5);
		x = wherex();
		y = wherey();
		in_ds(k, v);
		int j = 1;
		for (int i = 1;i <= k;i++)
		{
			if (v[j] == i)
			{
				ft[i] = v[j];
				j++;
			}
		}
		gotoxy(x, y);
		SetBGColor(13);
		cout << setw(4) << (y - 5) * 10 + x;
		SetBGColor(0);
		thongtin(x , y-4, ds_cb[a[p]], ds_hk.TREE);
		gotoxy(x, y);
		int dk=dieu_khien(x, y, k, ft, ds_cb[a[p]], ds_hk, First);
		if (dk == 0)
		{
			system("cls");
			goto back1;
		}
		else
		{
			gotoxy(0, 25);
			int fi = dem(First);
			clearlist(First);
			for (int i = 0;i < fi;i++)
			{
				cb.ds_ve.cmnd = new string[ds_cb[i]->ds_ve.n + 1];
				strcpy_s(cb.machuyenbay, ds_cb[i]->machuyenbay);
				strcpy_s(cb.sohieu, ds_cb[i]->sohieu);
				strcpy_s(cb.sanbay, ds_cb[i]->sanbay);
				cb.ngay = ds_cb[i]->ngay;
				cb.thang = ds_cb[i]->thang;
				cb.nam = ds_cb[i]->nam;
				cb.gio = ds_cb[i]->gio;
				cb.phut = ds_cb[i]->phut;
				cb.ds_ve.n = ds_cb[i]->ds_ve.n;
				cb.trangthai = ds_cb[i]->trangthai;
				cb.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
				cb.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
				for (int k = 1;k < ds_cb[i]->ds_ve.n + 1;k++)
				{
					cb.ds_ve.cmnd[k] = ds_cb[i]->ds_ve.cmnd[k];
				}
				insert_last(First, cb);
			}
			system("cls");
			//gotoxy(50, 11);cout << "DAT THANH CONG";
			writefile_flight(First);
			write_hk(ds_hk.TREE);
			system("cls");
			goto back;
		}
}
int insert_hanhkhach_datve(DS_HANH_KHACH& ds_hk, string cmnd)
{
	hanh_khach* p;
	char* tmp;
	int i = 0;
	p = new_node(cmnd);
	gotoxy(70, 13);
	cout << "Nhap ho: ";
	do
	{ 
		tmp = block_char(21, 80, 13);
		if (tmp[0] == '.')return 0;
	} while (tmp[0] =='\0');
	while (tmp[i] != '\0')
	{
		p->ho[i] = tmp[i];
		i++;
		p->ho[i] = '\0';
	}
	gotoxy(70, 14);
	cout << "Nhap ten: ";
	do
	{
		tmp = block_char(21, 80, 14);
		if (tmp[0] == '.')return 0;
	} while (tmp[0] == '\0');
	i = 0;
	while (tmp[i] != '\0')
	{
		p->ten[i] = tmp[i];
		i++;
		p->ten[i] = '\0';
	}
	gotoxy(70, 15);
	cout << "Nhap gioi tinh: ";
	if (lua_chon_gt() == 1)
	{
		p->sex[0] = 'N';
		p->sex[1] = 'a';
		p->sex[2] = 'm';
		p->sex[3] = '\0';
	}
	else
	{
		p->sex[0] = 'N';
		p->sex[1] = 'u';
		p->sex[2] = '\0';
	}
	gotoxy(86, 15);cout << p->sex;
	gotoxy(70, 16);
	cout << "<ENTER> Tiep tuc";
	_getch();
	insert_tree(ds_hk.TREE, p);
	ds_hk.sl++;
	system("cls");
	return 1;
}
int yes_no_ve()
{
	box_nho(64, 10, 34, 5);
	gotoxy(78, 12);cout << "YES";
	gotoxy(78, 13);cout << "NO";
	gotoxy(74, 12);cout << "=>";
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
			gotoxy(74, k - 1);
			printf("  ");
		}
		if (k < 13)
		{
			gotoxy(74, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoxy(74, k);
		cout << "=>";
	} while (c != 13);
	switch (k)
	{
	case 12:
	{
		return 1;
	}
	case 13:
	{
		return 0;
	}
	}
}
string cmnd_trong(tree root,string t)
{
	string result;
	int number;

	int i = 0;
	string k;
	char* tmp = new char[9];
	while (t[i] != '\0')
	{
		tmp[i] = t[i];
		i++;
		tmp[i] = '\0';
	}
	number = atoi(tmp);
	do
	{
		ostringstream convert;
		number++;
		if (number < 10)
		{
			//result = "00000000";
			//convert << 0;
			convert << number;
			result = "00000000" + convert.str();
		}
		else if (number >= 10)
		{
			//result = "0000000";
			convert << number;
			result = "0000000" + convert.str();
		}
		else if (number >= 100)
		{
			//result = "000000";
			convert << number;
			result = "000000" + convert.str();
		}
	}while(same_testcmnd(root, result)==1);
	return result;
}
void huy_ve(DS_CHUYEN_BAY& First, DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_MAYBAY& mb, chuyenbay* ds_cb[])
{
back:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	system("cls");
	Time();
	readfile_cb(First);
	readfile_plane(mb);
	read_hk(ds_hk.TREE);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	gotoxy(90, 3);cout << "TINH NANG HUY VE";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
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
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
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
	} while (c != 13|| ds_cb[a[p]]->trangthai == 3 || ds_cb[a[p]]->trangthai == 0);
	system("cls");
	//==================================================================================================================================//
main:
	system("cls");
	Time();
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
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	gotoxy(15, 3);cout << "Search cmnd: ";
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
	int lt = 0;
	int trang1 = 0;
	int tong1 = 0;
	if (ds_cb[a[p]]->ds_ve.sl_da_ban == 18)
	{
		tong1 = 1;
		trang1 = 0;
	}
	else
	{
		tong1 = (ds_cb[a[p]]->ds_ve.sl_da_ban) / 18 + 1;
	}
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang1 + 1 << "/" << tong1;
	int* tam2 = new int[ds_cb[a[p]]->ds_ve.sl_da_ban];
	for (int i = 1;i <= ds_cb[a[p]]->ds_ve.n;i++)
	{
		if (ds_cb[a[p]]->ds_ve.cmnd[i].length() == 9)
		{
			tam2[lt] = i;
			lt++;
		}
	}
	int k = 0;
	int m = 0;
	int* tam = new int[ds_cb[a[p]]->ds_ve.n + 1];
	for (int i = 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1;i++)
	{
		if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
		{
			//tam[m] = i;
			//m++;
			if (k == 18)break;
			gotoxy(5, 7 + k);cout << k;
			gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
			in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
			gotoxy(11, 7 + k);cout << tam2[i];
			connhay_off();
			k++;
		}
	}
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 57)
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
			k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 6;i++)
				{
					gotoxy(10 + i, j + 7);
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
				for (int i = 0;i < 9;i++)
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
			k = 0;
			string temp;
			for (int i = 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1;i++)
			{
				temp = ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (temp[j] != tim_maybay[j])
						break;
					if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
					{
						if (j == tim_maybay.length() - 1)
						{
							//tam[m] = i;
							//m++;
							if (k == 18)break;
							gotoxy(5, 7 + k);cout << k;
							gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
							in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
							gotoxy(11, 7 + k);cout << tam2[i];
							connhay_off();
							k++;
						}
					}
				}
			}
			gotoxy(27 + i, 3);
			connhay_on();
		}
		if (c == 8 && i > 0)
		{
			//u = 0;
			gotoxy(27 + i - 1, 3);
			cout << " ";
			gotoxy(27 + i - 1, 3);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			k = 0;
			string temp;
			for (int i = 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1;i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					temp = ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
					if (temp[j] != tim_maybay[j])
						break;
					if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
					{
						if (j == tim_maybay.length() - 1)
						{
							//tam[m] = i;
							//m++;
							if (k == 18)break;
							gotoxy(5, 7 + k);cout << k;
							gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
							in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
							gotoxy(11, 7 + k);cout << tam2[i];
							connhay_off();
							k++;
						}
					}
				}
			}
		}
		gotoxy(27 + i, 3);
		connhay_on();
		if (b[0] == '\0')
		{
			k = 0;
			for (int i = 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1;i++)
			{
				if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
				{
					//tam[m] = i;
					//m++;
					if (k == 18)break;
					gotoxy(5, 7 + k);cout << k;
					gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
					in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
					gotoxy(11, 7 + k);cout << tam2[i];
					connhay_off();
					k++;
				}
			}
		}
		gotoxy(27 + i, 3);
		if (c == 27)goto back;
	} while (c != 13);
	connhay_off();
	box_nho(100, 27, 15, 2);
	int j = 0;
	int x = 0;
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang1 + 1 << "/" << tong1;
		c = _getch();
		if (f <= 7 && tong1 > 1 && trang1 > 0 && c == 72)
		{
			gotoxy(0, 7);
			cout << "   ";
			f = 25;
			trang1--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 6;i++)
				{
					gotoxy(10 + i, j + 7);
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
				for (int i = 0;i < 9;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = trang1 * 18 + 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1 && i <= 18 + trang1 * 18; i++)
			{
				if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
				{
					if (k == 18)break;
					gotoxy(5, 7 + k);cout << i;
					gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
					in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
					gotoxy(11, 7 + k);cout << tam2[i];
					connhay_off();
					k++;
				}
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				x--;
			}
		}
		else if (c == 80)
		{
			if (f < lt + 6 && x <= lt - 2)
			{
				f += 1;
				x++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoxy(0, f - 1);
			printf("   ");
		}
		if (f != 7 + lt)
		{
			gotoxy(0, f + 1);
			printf("  ");
		}
		if (f == 25 && tong1 > 1 && trang1 + 1 < tong1)
		{
			trang1++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0;i < 4;i++)
				{
					gotoxy(5 + i, j + 7);
					cout << " ";
				}
				for (int i = 0;i < 6;i++)
				{
					gotoxy(10 + i, j + 7);
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
				for (int i = 0;i < 9;i++)
				{
					gotoxy(101 + i, j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = trang1 * 18 + 0;i <= ds_cb[a[p]]->ds_ve.sl_da_ban-1 && i <= 18 + trang1 * 18; i++)
			{
				if (same_testcmnd(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]]) == 1)
				{
					//tam[m] = i;
					//m++;
					if (k == 18)break;
					gotoxy(5, 7 + k);cout << i;
					gotoxy(19, 7 + k);cout << ds_cb[a[p]]->ds_ve.cmnd[tam2[i]];
					in(ds_hk.TREE, ds_cb[a[p]]->ds_ve.cmnd[tam2[i]], k);
					gotoxy(11, 7 + k);cout << tam2[i];
					connhay_off();
					k++;
				}
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	//=================================================================================================================//
	DS_CHUYEN_BAY v;
	v = First;
	while (v != NULL)
	{
		for (int i = 0;i <= v->cb.ds_ve.n;i++)
		{
			if (v->cb.ds_ve.cmnd[i] == ds_cb[a[p]]->ds_ve.cmnd[tam2[x]])
			{
				v->cb.ds_ve.cmnd[i] = "";
				v->cb.ds_ve.sl_con = v->cb.ds_ve.sl_con + 1;
				v->cb.ds_ve.sl_da_ban = v->cb.ds_ve.sl_da_ban - 1;
			}
		}
		v = v->next;
	}
	system("cls");
	Time();
	gotoxy(49, 11);cout << "Ban co chac huy ve khong";
	yes_no_fl(First);
	goto back;
}
int lua_chon_gt()
{
	box_nho(64, 19, 10, 5);
	gotoxy(66, 20);cout << "Gioi tinh";
	gotoxy(68, 21);cout << "Nam";
	gotoxy(68, 22);cout << "Nu";
	gotoxy(65, 21);cout << "=>";
	int k = 21;
	char c;
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 21)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 22)
			{
				k += 1;
			}

		}
		if (k != 21)
		{
			gotoxy(65, k - 1);
			printf("  ");
		}
		if (k != 23)
		{
			gotoxy(65, k + 1);
			printf(" ");

		}
		cout << "  ";
		gotoxy(65, k);
		cout << "=>";
	} while (c != 13);
	switch (k)
	{
	case 21:
	{
		int i = 0;
		int j = 0;
		while (i <= 5)
		{
			gotoxy(63 + j, 19 + i);
			cout << " ";
			if (j == 12)
			{
				i++;
				j = 0;
			}
			j++;
		}
		return 1;
	}
	case 22:
	{
		int i = 0;
		int j = 0;
		while (i <= 5)
		{
			gotoxy(63 + j, 19 + i);
			cout << " ";
			if (j == 12)
			{
				i++;
				j = 0;
			}
			j++;
		}
		return 0;
	}
	}
}