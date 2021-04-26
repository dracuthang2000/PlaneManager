#pragma once
#include"ctdl.h"
#include"AVLtree.h"
#include"plane.h"
#include"mylib.h"
#include<cstring>
#include<ctime>
#include<time.h>
#include "Box.h"
#include"readandwritefile.h"
void Time();
void trang_thai(int t, int x, int y);
void readfile_cb(DS_CHUYEN_BAY& First);
void writefile_flight(DS_CHUYEN_BAY& first);
void readfile_plane(DS_MAYBAY& mb);
int huy_chuyen(DS_CHUYEN_BAY& First, char* x,char* sh,chuyenbay *ds_cb[]);
void connhay_off();
void connhay_on();
int result_flight(DS_CHUYEN_BAY& First, chuyenbay* ds_cb[]);
char* block_and_char(int a, int x, int y);
char* block_char(int a, int x, int y);
char* block_number(int a, int x, int y);
void result_plane(DS_MAYBAY& mb);
int search_choi(DS_MAYBAY& mb);
void insert_last(DS_CHUYEN_BAY& first, chuyenbay x);
int yes_no_fl(DS_CHUYEN_BAY& First);
//int ve(int i, DS_MAYBAY& mb);
//==========================================Ham=================================================================//
DS_CHUYEN_BAY new_nodecb(void)
{
	DS_CHUYEN_BAY p = new ds_chuyen_bay;
	return p;
}
void initialize(DS_CHUYEN_BAY& First)
{
	First = NULL;
}
void insert_first(DS_CHUYEN_BAY& First, chuyen_bay x)
{
	DS_CHUYEN_BAY p;
	p = new_nodecb();
	p->cb = x;
	p->next = First;
	First = p;
}
int Empty(DS_CHUYEN_BAY First)
{
	return(First == NULL ? TRUE : FALSE);
}
//void Ins_last(DS_CHUYEN_BAY& Last, chuyen_bay x)
//{
//	DS_CHUYEN_BAY p;
//	p = new_nodecb();
//	p->cb = x;
//	if (Empty(Last))
//		p->next = p;
//	else
//	{
//		p->next = Last->next;
//		Last->next = p;
//	}
//	Last = p;
//}
//void Insert_after(DS_CHUYEN_BAY p, chuyen_bay x)
//{
//	DS_CHUYEN_BAY q;
//	if (p == NULL)
//		printf("khong them sinh vien vao danh sach duoc");
//	else
//	{
//		q = new_nodecb();
//		q->cb = x;
//		q->next = p->next;
//		p->next = q;
//	}
//}
void clearlist(DS_CHUYEN_BAY& First)
{
	DS_CHUYEN_BAY p, q;
	p = First;
	while (First != NULL)
	{
		p = First;
		First = First->next;
		free(p);
	}
}
//void insert_oder(DS_CHUYEN_BAY& First, chuyen_bay x)
//{
//	DS_CHUYEN_BAY p, q;
//	q = NULL;
//	for (p = First; p != NULL && _strcmpi(p->cb.sohieu , x.sohieu)==-1; p = p->next)
//		q = p;
//	
//	if (p == First||First==NULL)
//	{
//		insert_first(First, x);
//	}
//	else
//	{
//		Insert_after(q, x);
//	}
//}

void insert_cb(DS_CHUYEN_BAY& First, chuyen_bay &x)
{
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	readfile_cb(First);
	DS_MAYBAY mb;
	int k = 7;
	char c;
	int i = 0;
	char* tmp;
	int n = 0;
	DS_CHUYEN_BAY p;
	tmp = new char[200];
	connhay_off();
	system("cls");
	Time();
	gotoxy(50, 3);
	cout << "CHON SO HIEU";
	int j = 0;
	i = search_choi(mb);
	while (mb.dsmaybay[i]->sohieu[j] != '\0')
	{
		x.sohieu[j] = mb.dsmaybay[i]->sohieu[j];
		j++;
		x.sohieu[j] = '\0';
	}
	system("cls");
xuat:
	box_nho(4, 3, 25, 3);
	box_nho(92, 3, 25, 3);
	//box_nho(92, 8, 25, 5);
	box_nho(30, 7, 60, 17);
	gotoxy(5, 5);cout << "Nhan <ESC> de quay lai";
	Time();
	x.ds_ve.n = mb.dsmaybay[i]->socho;
	gotoxy(45, 12);
	cout << "So hieu: ";
	gotoxy(60, 12);cout << x.sohieu;
	gotoxy(45, 13);
	cout << "Ma chuyen bay: ";
	gotoxy(45, 14);
	cout << "Nhap san bay: ";
	gotoxy(45, 15);
	cout << "Nhap ngay: ";
	gotoxy(45, 16);
	cout << "Nhap thang: ";
	gotoxy(45, 17);
	cout << "Nhap nam: ";
	gotoxy(45, 18);
	cout << "Nhap gio: ";
	gotoxy(45, 19);
	cout << "Nhap phut: ";
	gotoxy(45, 20);
	cout << "so luong ve: ";gotoxy(60, 20);cout << x.ds_ve.n;
	do {
		tmp = block_and_char(15, 60, 13);
	} while (tmp[0] == '\0');
	if (tmp[0] == '.')
	{
		return;
	}
	n = 0;
	while (tmp[n] != '\0')
	{
		x.machuyenbay[n] = tmp[n];
		n++;
		x.machuyenbay[n] = '\0';
	}
	p = First;
	while (p != NULL)
	{
		if (_strcmpi(p->cb.machuyenbay, x.machuyenbay) == 0&& _strcmpi(p->cb.sohieu, x.sohieu) == 0)
		{
			gotoxy(94, 4);
			cout << "Nhap trung";
			gotoxy(94, 5);cout << "Nhap lai";
			_getch();
			for (int i = 0;i <= 10;i++)
			{
				gotoxy(94+i, 4);cout << " ";
				gotoxy(94+i, 5);cout << " ";
				gotoxy(60 + i, 13);cout << " ";
			}
			goto xuat;
		}
		p = p->next;
	}
	Time();
	do {
		tmp = block_char(100, 60, 14);
	} while (tmp[0] == '\0');
	if (tmp[0] == '.')
	{
		return;
	}
	n = 0;
	while (tmp[n] != '\0')
	{
		x.sanbay[n] = tmp[n];
		n++;
		x.sanbay[n] = '\0';
	}
	//gotoxy(45, 11);
	//cout << "Nhap ngay: ";
	do {
		for (int i = 0;i < 10;i++)
		{
			gotoxy(60 + i, 15);cout << " ";
		}
		//gotoxy(15, 3);
		tmp = block_number(1, 60, 15);
	} while (tmp[0] == '\0'||atoi(tmp)>31);
	if (tmp[0] == '.')
	{
		return;
	}
	x.ngay = atoi(tmp);
	//gotoxy(45, 12);
	//cout << "Nhap thang: ";
	do {
		for (int i = 0;i < 10;i++)
		{
			gotoxy(60 + i, 16);cout << " ";
		}
		//gotoxy(15, 4);
		tmp = block_number(1, 60, 16);
	} while (tmp[0] == '\0'|| atoi(tmp) > 12);
	if (tmp[0] == '.')
	{
		n++;
		return;
	}
	x.thang = atoi(tmp);
	//gotoxy(45, 13);
	//cout << "Nhap nam: ";
	do {
		for (int i = 0;i < 10;i++)
		{
			gotoxy(60 + i, 17);cout << " ";
		}
		//gotoxy(15, 5);
		tmp = block_number(3, 60, 17);
	} while (tmp[0] == '\0'||x.thang<months&& atoi(tmp) == years ||atoi(tmp)<years);
	if (tmp[0] == '.')
	{
		return;
	}
	x.nam = atoi(tmp);
	back1:
	//gotoxy(45, 14);
	//cout << "Nhap gio: ";
	do {
		for (int i = 0;i < 10;i++)
		{
			gotoxy(60 + i, 18);cout << " ";
		}
		tmp = block_number(1, 60, 18);
	} while (tmp[0] == '\0'|| days == x.ngay && months == x.thang && years == x.nam && atoi(tmp) - hours < 0 || atoi(tmp)>24);
	n = 0;
	if (tmp[0] == '.')
	{
		return;
	}
	while (p != NULL)
	{
		if (_strcmpi(p->cb.sohieu, x.sohieu) == 0 && _strcmpi(p->cb.machuyenbay, x.machuyenbay) != 0)
		{
			if (p->cb.ngay == x.ngay && p->cb.thang == x.thang && p->cb.nam == x.nam && abs(atoi(tmp) - p->cb.gio) < 4)
			{
				//gotoxy(60, 18);
				gotoxy(94, 4);cout << "Da co chuyen bay";
				gotoxy(94, 4);cout << "cach day 4 gio";
				_getch();
				for (int i = 0;i <= 10;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
					gotoxy(94 + i, 5);cout << " ";
					gotoxy(60 + i, 5);cout << " ";
				}
				goto back1;
			}
		}
		p = p->next;
	}

	x.gio = atoi(tmp);
	//gotoxy(45, 15);
	//cout << "Nhap phut: ";
	do {
		tmp = block_number(1, 60, 19);
	} while (tmp[0] == '\0'|| atoi(tmp)>60);
	if (tmp[0] == '.')return;
	x.phut=atoi(tmp);
	x.ds_ve.cmnd = new string[x.ds_ve.n+1];
	for (int i = 1;i < x.ds_ve.n + 1;i++)
	{
		x.ds_ve.cmnd[i] = "";
	}
	x.trangthai = 1;
	x.ds_ve.sl_con = x.ds_ve.n;
	x.ds_ve.sl_da_ban = 0;
	//insert_oder(First, x);
	insert_last(First, x);
	writefile_flight(First);
}
void Print_cb_to_arr(DS_CHUYEN_BAY& First,chuyenbay *ds_cb[])
{
	DS_MAYBAY mb;
	readfile_cb(First);
	DS_CHUYEN_BAY p;
	p = First;
	int i = 0;
	int stt = 0;
	if (p == NULL)return;
	while (p != NULL)
	{
		ds_cb[stt] = new chuyenbay;
		ds_cb[stt]->ds_ve.cmnd = new string[p->cb.ds_ve.n+1];
		i = 0;
 		while (p->cb.machuyenbay[i] != '\0')
		{
			ds_cb[stt]->machuyenbay[i] = p->cb.machuyenbay[i];
			i++;
			ds_cb[stt]->machuyenbay[i] = '\0';
		}
		p->cb.machuyenbay;
		i = 0;
		while (p->cb.sohieu[i] != '\0')
		{
			ds_cb[stt]->sohieu[i] = p->cb.sohieu[i];
			i++;
			ds_cb[stt]->sohieu[i] = '\0';
		}
		p->cb.sohieu;
		i = 0;
		while (p->cb.sanbay[i] != '\0')
		{
			ds_cb[stt]->sanbay[i] = p->cb.sanbay[i];
			i++;
			ds_cb[stt]->sanbay[i] = '\0';
		}
		p->cb.sanbay;
		ds_cb[stt]->ngay = p->cb.ngay;
		ds_cb[stt]->thang = p->cb.thang;
		ds_cb[stt]->nam = p->cb.nam;
		ds_cb[stt]->gio = p->cb.gio;
		ds_cb[stt]->phut = p->cb.phut;
		ds_cb[stt]->ds_ve.n = p->cb.ds_ve.n;
		ds_cb[stt]->trangthai = p->cb.trangthai;
		ds_cb[stt]->ds_ve.sl_con = p->cb.ds_ve.sl_con;
		ds_cb[stt]->ds_ve.sl_da_ban = p->cb.ds_ve.sl_da_ban;
		for (int k = 1;k < ds_cb[stt]->ds_ve.n+1;k++)
		{
			ds_cb[stt]->ds_ve.cmnd[k] = p->cb.ds_ve.cmnd[k];
		}
		stt++;
		p = p->next;
	}
}
int dem(DS_CHUYEN_BAY& First)
{
	DS_CHUYEN_BAY p;
	int i = 0;
	p = First;
	if (p == NULL)return -1;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
int result_flight(DS_CHUYEN_BAY& First, chuyenbay* ds_cb[])
{
	
	DS_MAYBAY mb;
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
	Box_tong();
	box_key(4);
	box_key(6);
	box_kex(9, 4);
	box_noih(9, 4);
	box_noio(9, 6);
	box_kex(24, 4);
	box_noih(24, 4);
	box_noio(24, 6);
	box_kex(38, 4);
	box_noih(38, 4);
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
	readfile_plane(mb);
	if (First == NULL)
	{
		cout << "chua co chuyen bay nao";
		return 0;
	}
	gotoxy(5, 5);
	cout << "STT";
	gotoxy(10, 5);
	cout << "loai may bay";
	gotoxy(25, 5);
	cout << "Ma chuyen bay";
	gotoxy(40, 5);
	cout << "so hieu";
	gotoxy(55, 5);
	cout << "San bay den";
	gotoxy(70, 5);
	cout << "Ngay";
	gotoxy(75, 5);
	cout << "Thang";
	gotoxy(81, 5);
	cout << "Nam";
	gotoxy(88, 5);
	cout << "Gio";
	gotoxy(92,5);
	cout << "Phut";
	gotoxy(97, 5);
	cout << "So ve";
	gotoxy(104, 5);
	cout << "Trang thai";
	int k = 7;
	for (int i = trang*18+0;i < dem(First)&& i <= 18 + trang * 18; i++)
	{
		gotoxy(5, k);
		cout << i;
		for (int j = 0;j < mb.sl - 1;j++)
		{
			if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu )== 0)
			{
				gotoxy(10, k);
				cout << mb.dsmaybay[j]->loaimaybay;
			}
		}
		//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
		gotoxy(25, k);
		cout << ds_cb[i]->machuyenbay;
		gotoxy(40, k);
		cout<< ds_cb[i]->sohieu;
		gotoxy(55, k);
		cout << ds_cb[i]->sanbay;
		gotoxy(70, k);
		cout <<ds_cb[i]->ngay;
		gotoxy(77, k);
		cout << ds_cb[i]->thang ;
		gotoxy(81, k);
		cout << ds_cb[i]->nam;
		gotoxy(88, k);
		cout << ds_cb[i]->gio;
		gotoxy(93, k);
		cout << ds_cb[i]->phut;
		gotoxy(98, k);
		cout << ds_cb[i]->ds_ve.n;
		gotoxy(108, k);trang_thai(ds_cb[i]->trangthai,104, k);
		//cout << ds_cb[i]->trangthai;
		k++;
	}
	return 0;
}
//int Delete_info_to_cb(DS_CHUYEN_BAY& First, char *x)//xoa tu chuyen bay;
//{
//	system("cls");
//	readfile_cb(First);
//	DS_CHUYEN_BAY p, q;
//		p = First;
//		while (p != NULL)
//		{
//			if (p == First && _strcmpi(p->cb.sohieu, x)==0) {
//				q = p;
//				First = p->next;
//				delete q;
//				break;
//			}
//			else if (_strcmpi(p->cb.sohieu, x) == 0 && p->next == NULL)
//			{
//				q = p;
//				p = NULL;
//				delete q;
//				break;
//			}
//			else if (_strcmpi(p->cb.sohieu, x) == 0)
//			{
//				//p = First;
//				q = p;
//				p = p->next;
//				delete q;
//				break;
//			}
//			p = p->next;
//		}
//	writefile_flight(First);
//	return 0;
//}
void cancel_flight(DS_CHUYEN_BAY& First,DS_MAYBAY &mb, chuyenbay* ds_cb[])
{

	char c;
back:
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
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	system("cls");
	Time();
	DS_CHUYEN_BAY v;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	readfile_cb(First);
	readfile_plane(mb);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	gotoxy(90, 3);cout << "TINH NANG HUY CHUYEN";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	box_nho(100, 27, 15, 2);gotoxy(101, 28);cout << "Trang: " << trang + 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search CB:";
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
						//cout << ds_cb[i]->trangthai;
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
	//================================================================================================================//
	f = 7;
	char* tmp = new char[15];
	int j = 0;
	while (ds_cb[a[p]]->machuyenbay[j] != '\0')
	{
		tmp[j] = ds_cb[a[p]]->machuyenbay[j];
		j++;
		tmp[j] = '\0';
	}
	char* cmp = new char[15];
	j = 0;
	while (ds_cb[a[p]]->sohieu[j] != '\0')
	{
		cmp[j] = ds_cb[a[p]]->sohieu[j];
		j++;
		cmp[j] = '\0';
	}
	huy_chuyen(First, tmp, cmp, ds_cb);
	gotoxy(50, 11);cout << "Ban co chac la huy chuyen!";
	if (yes_no_fl(First) == 0)
	{
		box_nho(10, 13, 100, 3);
		gotoxy(50, 14);cout << "DA HUY CHUYEN";
		Sleep(300);
		goto back;
	}
	else { goto back; }
}
void edit_fl(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[])
{
	char c;
back:
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
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours =  ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	system("cls");
	Time();
	DS_CHUYEN_BAY v;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	readfile_cb(First);
	readfile_plane(mb);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << 1 << "/" << tong;
	gotoxy(15, 3);cout << "Search CB:";
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
				gotoxy(27 + i, 3);
				connhay_on();
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
	
	key://============================================================================================================//
	f = 7;
	gotoxy(0, 7);cout << "==>";
	box_nho(100, 27, 15, 2);
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
	//================================================================================================================//
	f = 13;
main:
	box_nho(4, 3, 25, 3);
	box_nho(92, 3, 25, 3);
	box_nho(30, 7, 60, 17);
	Time();
	gotoxy(5,5);cout << "<ESC> THOAT KHONG LUU";
	for (int i = 0;i < 16;i++)
	{
		gotoxy(49 + i, 13);
		cout << " ";
	}
	gotoxy(35, 13);cout << "Ma chuyen bay: " << ds_cb[a[p]]->machuyenbay;
	for (int i = 0;i < 30;i++)
	{
		gotoxy(47 + i, 14);
		cout << " ";
	}
	gotoxy(35, 14);cout << "San bay den: " << ds_cb[a[p]]->sanbay;
	for (int i = 0;i < 6;i++)
	{
		gotoxy( 42+ i, 15);
		cout << " ";
	}
	gotoxy(35, 15);cout << "Ngay: " << ds_cb[a[p]]->ngay;
	for (int i = 0;i < 6;i++)
	{
		gotoxy(42 + i, 16);
		cout << " ";
	}
	gotoxy(35, 16);cout << "Thang: " << ds_cb[a[p]]->thang;
	for (int i = 0;i < 6;i++)
	{
		gotoxy(40 + i, 17);
		cout << " ";
	}
	gotoxy(35, 17);cout << "Nam: " << ds_cb[a[p]]->nam;
	for (int i = 0;i < 6;i++)
	{
		gotoxy(40 + i, 18);
		cout << " ";
	}
	gotoxy(35, 18);cout << "Gio: " << ds_cb[a[p]]->gio;
	for (int i = 0;i < 6;i++)
	{
		gotoxy(40 + i, 19);
		cout << " ";
	}
	gotoxy(35, 19);cout << "Phut: " << ds_cb[a[p]]->phut;
	gotoxy(35, 20);cout << "Luu va Thoat";
	gotoxy(70, f);cout << " <==";
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (f > 13)
			{
				f = f - 1;
			}
		}
		else if (c == 80)
		{
			if (f < 20)
			{
				f += 1;
			}

		}
		if (c == 27)
		{
			system("cls");
			goto back;
		}
		if (f != 13)
		{
			gotoxy(70, f - 1);
			printf("    ");
		}
		if (f != 20)
		{
			gotoxy(70, f + 1);
			printf("    ");
		}
		cout << "    ";
		gotoxy(70, f);
		cout << " <==";
	} while (c != 13);
	switch (f)
	{
	case 13:
	{
	xuat:
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0;j <= 40;j++)
		{
			gotoxy(49 + j, 13);cout << " ";
		}
		//gotoxy(53, 8);
		int n = 0;
		do {
			tmp = block_and_char(15, 50, 13);
		} while (tmp[0] == '\0');
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (tmp[n] != '\0')
		{
			ds_cb[a[p]]->machuyenbay[n] = tmp[n];
			n++;
			ds_cb[a[p]]->machuyenbay[n] = '\0';
		}
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) == 0 && _strcmpi(v->cb.sohieu, ds_cb[a[p]]->sohieu) == 0)
			{
				gotoxy(94, 4);cout << "Nhap lai";
				_getch();
				for (int i = 0;i <= 10;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
				}
				goto xuat;
			}
			v = v->next;
		}
		break;
	}
	case 14:
	{
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		int n = 0;
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0;j <= 40;j++)
		{
			gotoxy(47 + j, 14);cout << " ";
		}
		do {
			tmp = block_char(100, 48, 14);
		} while (tmp[0] == '\0');
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (tmp[n] != '\0')
		{
			ds_cb[a[p]]->sanbay[n] = tmp[n];
			n++;
			ds_cb[a[p]]->sanbay[n] = '\0';
		}
	}
	break;
	case 15:
	{
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		char* tmp = new char[100];
		do
		{
			for (int j = 0;j <= 35;j++)
			{
				gotoxy(40 + j, 15);cout << " ";
			}
			tmp = block_number(1, 40, 15);
			if (ds_cb[a[p]]->thang == months && ds_cb[a[p]]->nam == years && atoi(tmp) < days || atoi(tmp) > 31)
			{
				gotoxy(94, 4);cout << "khong hop le";
				gotoxy(94, 5);cout << "nhap lai";
				_getch();
				for (int i = 0;i <= 15;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
					gotoxy(94 + i, i);cout << " ";
				}
			}
		} while (tmp[0] == '\0' || ds_cb[a[p]]->thang == months && ds_cb[a[p]]->nam == years && atoi(tmp) < days || atoi(tmp) > 31);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->ngay = atoi(tmp);
		break;
	}
	case 16:
	{
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		char* tmp = new char[100];
		do {
			for (int j = 0;j <= 40;j++)
			{
				gotoxy(41 + j, 16);cout << " ";
			}
			tmp = block_number(1, 41, 16);
			if (atoi(tmp) < months && ds_cb[a[p]]->nam == years || atoi(tmp) > 12)
			{
				gotoxy(94, 4);cout << "khong hop le";
				gotoxy(94, 5);cout << "nhap lai";
				_getch();
				for (int i = 0;i <= 15;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
					gotoxy(94 + i, 5);cout << " ";
				}
			}
		} while (tmp[0] == '\0' || atoi(tmp) < months && ds_cb[a[p]]->nam == years || atoi(tmp) > 12);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->thang = atoi(tmp);
		break;
	}
	case 17:
	{
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		char* tmp = new char[100];
		do {
		
			for (int j = 0;j <= 50;j++)
			{
				gotoxy(40 + j, 17);cout << " ";
			}
			tmp = block_number(3, 40, 17);
			if (tmp[0] == '.')goto main;
			if (atoi(tmp) < years&&tmp[0] !='\0' )
			{
				gotoxy(94, 4);cout << "khong hop le";
				gotoxy(94, 5);cout << "nhap lai";
				_getch();
				for (int i = 0;i <= 15;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
					gotoxy(94 + i, 5);cout << " ";
				}
			}
		} while (tmp[0] == '\0' || atoi(tmp) < years|| atoi(tmp) < 1000);
		ds_cb[a[p]]->nam = atoi(tmp);
		break;
	}
	case 18:
	{
		back1:
		v = First;
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		char* tmp = new char[100];
		do 
		{
		for (int j = 0;j <= 35;j++)
		{
			gotoxy(40 + j, 18);cout << " ";
		}
		tmp = block_number(1, 40, 18);
		if (days == ds_cb[a[p]]->ngay && months == ds_cb[a[p]]->thang && years == ds_cb[a[p]]->nam && atoi(tmp) - hours < 0 || atoi(tmp)>24)
		{
			gotoxy(94, 4);cout << "khong hop le";
			gotoxy(94, 5);cout << "nhap lai";
			_getch();
			for (int i = 0;i <= 15;i++)
			{
				gotoxy(94 + i, 4);cout << " ";
				gotoxy(94 + i, 5);cout << " ";
			}
		}
		} while (tmp[0] == '\0'|| days == ds_cb[a[p]]->ngay && months == ds_cb[a[p]]->thang && years == ds_cb[a[p]]->nam && atoi(tmp) - hours < 0||atoi(tmp)>24);
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, ds_cb[a[p]]->sohieu) == 0&& _strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) != 0 /*|| _strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) == -1*/)
			{
				if (v->cb.ngay == ds_cb[a[p]]->ngay && v->cb.thang == ds_cb[a[p]]->thang && v->cb.nam == ds_cb[a[p]]->nam && abs(atoi(tmp) - v->cb.gio)<4)
				{
					gotoxy(94, 4);cout << "Da co chuyen bay";
					gotoxy(94, 5);cout << "cach day 4 gio";
					_getch();
					for (int i = 0;i <= 17;i++)
					{
						gotoxy(94 + i, 4);cout << " ";
						gotoxy(94 + i, 5);cout << " ";
						gotoxy(60 + i, 5);cout << " ";
					}
					goto back1;
				}
			}
			v = v->next;
		}
		ds_cb[a[p]]->gio = atoi(tmp);
		break;
	}
	case 19:
	{
		gotoxy(5, 5);cout << "<ESC> QUAY LAI       ";
		char* tmp = new char[100];
		do {
			for (int j = 0;j <= 35;j++)
			{
				gotoxy(40 + j, 19);cout << " ";
			}
			tmp = block_number(1, 40, 19);
			if (atoi(tmp) > 60)
			{
				gotoxy(94, 4);cout << "khong hop le";
				gotoxy(94, 5);cout << "nhap lai";
				_getch();
				for (int i = 0;i <= 15;i++)
				{
					gotoxy(94 + i, 4);cout << " ";
					gotoxy(94 + i, 5);cout << " ";
				}
			}
		} while (tmp[0] == '\0' || atoi(tmp) >60);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->phut = atoi(tmp);
		break;
	}
	case 20:
		system("cls");
		int k;
		chuyenbay x;
		k = dem(First);
		clearlist(First);
		for (int i = 0;i < k;i++)
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.trangthai = ds_cb[i]->trangthai;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
		yes_no_fl(First);
		goto back;
	}
	goto main;
}
int huy_chuyen(DS_CHUYEN_BAY& First, char* k,char *sh,chuyenbay *ds_cb[])
{
	
	readfile_cb(First);
	DS_CHUYEN_BAY p, q;
	p = First;
	int n;
	chuyenbay x;
	n = dem(First);
	clearlist(First);
	for (int i = 0;i < n;i++)
	{
		if (_strcmpi(k, ds_cb[i]->machuyenbay)==0&&_strcmpi(sh, ds_cb[i]->sohieu)==0)
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			ds_cb[i]->trangthai = 0;
			x.trangthai = ds_cb[i]->trangthai;
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
		else
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			x.trangthai = ds_cb[i]->trangthai;
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
	}
	//writefile_flight(First);
	return 0;
}
int yes_no_fl(DS_CHUYEN_BAY& First)
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
		writefile_flight(First);
		system("cls");
		return 0;
	case 13:
		return 1;
	}
}
void Time()
{
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	gotoxy(85, 0);cout << hours;
	gotoxy(87, 0);cout << ":" << mins << " ";
	gotoxy(91, 0);cout << days;
	gotoxy(93, 0);cout << "/" << months;
	gotoxy(95, 0);cout << "/" << years;
}
void cap_nhat(DS_CHUYEN_BAY& First)
{
	readfile_cb(First);
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	DS_CHUYEN_BAY p;
	p = First;
	while (p != NULL)
	{
		if (p->cb.nam < years && p->cb.trangthai != 0)
		{
			p->cb.trangthai = 3;
		}
		else if (p->cb.nam == years && p->cb.thang < months&&p->cb.trangthai!=0)
		{
			p->cb.trangthai = 3;
		}
		else if (p->cb.nam == years && p->cb.thang == months && p->cb.gio < hours && p->cb.trangthai != 0)
		{
			p->cb.trangthai = 3;
		}
		else if (p->cb.phut < mins && p->cb.nam == years && p->cb.thang == months && p->cb.gio == hours && p->cb.trangthai != 0)
		{
			p->cb.trangthai = 3;
		}
		p = p->next;
	}
	writefile_flight(First);
}
void trang_thai(int t, int x, int y)
{
	if (t == 0)
	{
		gotoxy(x, y);cout << "0.Huy chuyen";
	}
	else if (t == 1)
	{
		gotoxy(x, y);cout << "1.Con ve";
	}
	else if (t == 2)
	{
		gotoxy(x, y);cout << "0.Het ve";
	}
	else if (t == 3)
	{
		gotoxy(x, y);cout << "3.Hoan tat";
	}
}
void xem_cb(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[])
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
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);
	gotoxy(90, 3);cout << "XEM DANH SACH";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> xuong";
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

key://============================================================================================================//
	f = 7;
	box_nho(100, 27, 15, 2);
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
	} while (c != 27);
	system("cls");
}
