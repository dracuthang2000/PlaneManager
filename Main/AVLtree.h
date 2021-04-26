#pragma once
#include "ctdl.h"
#include "readandwritefile.h"
#include <cstring>
#include"plane.h"
#include"mylib.h"
#include"Box.h"
void Time();
int lua_chon_gt();
char* block_char(int a, int x, int y);
char* block_number(int a, int x, int y);
int getBalance(tree N);
void rightRotate(tree& y);
void leftRotate(tree &x);
string insert_CMND(tree cm);
int hight(hanh_khach N);
int Max(int a, int b);
void insert_hanhkhach(DS_HANH_KHACH& ds_hk);
void insert_tree(tree& t, hanh_khach* p);
hanh_khach* new_node(int key);
int same_testcmnd(tree t, string key);
void result_dshanhkhach(hanh_khach* ds[], int& nds);
void read_hk(tree &t);
int yes_no_hk(tree& t, DS_CHUYEN_BAY& First);
void write_hk(tree& t);
void connhay_on();
void connhay_off();
void writefile_flight(DS_CHUYEN_BAY &First);
void readfile_cb(DS_CHUYEN_BAY &First);
void edit_hk(DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_CHUYEN_BAY& First);
//=============================================================HAM==============================================================================//

int height(tree N)
{
	if (N == NULL)
	{
		return 0;
	}
	return N->hight;
}
int Max(int a, int b)
{
	return( (a > b) ? a : b);
}
hanh_khach* new_node(string key)
{
	hanh_khach* p = new hanh_khach;
	p->cmnd = key;
	p->pLeft = NULL;
	p->pRight = NULL;
	p->hight = 1;
	return p;
}
void insert_hanhkhach(DS_HANH_KHACH& ds_hk)
{
	connhay_off();
	Time();
	hanh_khach* p;
	char* tmp;
	string cmd;
	int i=0;
	box_nho(4, 3, 25, 3);
	box_nho(92, 3, 25, 3);
	//box_nho(92, 8, 25, 5);
	gotoxy(5, 5);cout << "Nhan <ESC> de quay lai";
	box_nho(30, 7, 60, 17);
	//tmp = block_char(21, 30, 1);
	read_hk(ds_hk.TREE);
	cmd = insert_CMND(ds_hk.TREE);
	for (int j = 0;j < 9;j++)
	{
		if (cmd[j] == '.')return;
	}
	p = new_node(cmd);
	//cin.ignore();
	gotoxy(45, 11);
	cout << "Nhap ho: ";
	do {
		tmp = block_char(21, 55, 11);
	} while (tmp[0] == '\0');
	while (tmp[i] != '\0')
	{
		if (tmp[0] == '.')return;
		p->ho[i] = tmp[i];
		i++;
		p->ho[i] = '\0';
	}
	gotoxy(45, 12);
	cout << "Nhap ten: ";
	do {
		tmp = block_char(21, 55, 12);
	} while (tmp[0] == '\0');
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[0] == '.')return;
		p->ten[i] = tmp[i];
		i++;
		p->ten[i] = '\0';
	}
	gotoxy(45, 13);
	cout << "Nhap gioi tinh: ";
	if (lua_chon_gt() == 1)
	{
		p->sex[0] = 'N';
		p->sex[1] = 'a';
		p->sex[2] = 'm';
		p->sex[3] = '\0';
	}
	else if (lua_chon_gt() == 0)
	{
		p->sex[0] = 'N';
		p->sex[1] = 'u';
		p->sex[2] = '\0';
	}
	gotoxy(72, 9);cout << p->sex;
	insert_tree(ds_hk.TREE, p);
	write_hk(ds_hk.TREE);
	ds_hk.sl++;
	system("cls");
}
string insert_CMND(tree cm)
{
	connhay_off();
	//Time();
	string cmnd;
	do
	{
		//system("cls");
		//Time();
		gotoxy(45, 10);
		cout << "Nhap chung minh nhan dan: ";
		for (int i = 0;i < 10;i++)
		{
			gotoxy(72+i, 10);cout << " ";
		}
		cmnd = block_number(8, 72, 10);
		if (cmnd[0] == '.')
		{
			cmnd = "00000000.";
			break;
		}
		if (cmnd.length() != 9)
		{
			gotoxy(94, 4);
			cout << "Khong hop le";
			gotoxy(94, 5);
			cout << "hoac da co,nhap lai!";
			_getch();
			for (int i = 0;i <= 20;i++)
			{
				gotoxy(94 + i, 4);cout << " ";
				gotoxy(94 + i, 5);cout << " ";
			}
		}
	} while (same_testcmnd(cm,cmnd)==1||cmnd.length()!=9||cmnd[0]=='\0');
	return cmnd;
}
int same_testcmnd(tree t, string key)
{
	tree p = t;
	do
	{
		if (p == NULL)
		{
			return 0;
		}
		else
		{
			if (p->cmnd == key)
			{
				return 1;
			}
			else if(p->cmnd < key)
			{
				p = p->pRight;
			}
			else if(p->cmnd > key)
			{
				p = p->pLeft;
			}
		}
	} while (1);
}
void rightRotate(tree &y)
{
	tree x = y->pLeft;
	tree T2 = x->pRight;
	x->pRight = y;
	y->pLeft = T2;
	y->hight = Max(height(y->pLeft), height(y->pRight)) + 1;
	x->hight = Max(height(x->pLeft), height(x->pRight)) + 1;
	y = x;
	//return y;
}
void leftRotate(tree &x)
{
	tree y = x->pRight;
	tree T2 = y->pLeft;
	y->pLeft = x;
	x->pRight = T2;
	x->hight = Max(height(x->pLeft), height(x->pRight)) + 1;
	y->hight = Max(height(y->pLeft), height(y->pRight)) + 1;
	x = y;
}
int getBalance(tree N)
{
	if (N == NULL)
	{
		return 0;
	}
	return height(N->pLeft) - height(N->pRight);
}
void insert_tree(tree& t, hanh_khach* p)
{
	int balance;
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->cmnd < t->cmnd)
		{
			insert_tree(t->pLeft, p);
		}
		else if (p->cmnd > t->cmnd)
		{
			insert_tree(t->pRight, p);
		}
		t->hight = 1 + max(height(t->pLeft), height(t->pRight));
		 balance = getBalance(t);
		 if (balance > 1 && p->cmnd < t->pLeft->cmnd)
		{
			 rightRotate(t);
		}
		else if (balance < -1 && p->cmnd > t->pRight->cmnd)
		{
			 leftRotate(t);
		}
		else if (balance > 1 && p->cmnd > t->pLeft->cmnd)
		{
			leftRotate(t->pLeft);
			rightRotate(t);
		}
		else if (balance < -1 && p->cmnd < t->pRight->cmnd)
		{
			rightRotate(t->pRight);
			leftRotate(t);
		}
	}
}
void preOrder(tree t,hanh_khach*ds[],int &nds)
{
	if ( t!= NULL)
	{
		int i = 0;
		ds[nds] = new hanh_khach;
		ds[nds]->cmnd = t->cmnd;
		while (t->ho[i] != '\0')
		{
			ds[nds]->ho[i] = t->ho[i];
			i++;
			ds[nds]->ho[i] = '\0';
		}
		i = 0;
		while (t->ten[i] != '\0')
		{
			ds[nds]->ten[i] = t->ten[i];
			i++;
			ds[nds]->ten[i] = '\0';
		}
		i = 0;
		while (t->sex[i] != '\0')
		{
			ds[nds]->sex[i] = t->sex[i];
			i++;
			ds[nds]->sex[i] = '\0';
		}
		nds++;
		preOrder(t->pLeft,ds,nds);
		preOrder(t->pRight,ds,nds);
	}
}
void result_dshanhkhach(hanh_khach* ds[], int& nds)
{
	int trang = 0;
	int tong = 0;
	if (nds == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (nds / 18 + 1);
	}
	Box_tong();
	box_key(4);
	box_key(6);
	box_kex(9, 4);
	box_noih(9, 4);
	box_noio(9, 6);
	box_kex(38, 4);
	box_noih(38, 4);
	box_noio(38, 6);
	box_kex(100, 4);
	box_noih(100, 4);
	box_noio(100, 6);
	gotoxy(5, 5);
	cout << "STT";
	gotoxy(18, 5);
	cout << "Chung minh nhan dan";
	gotoxy(60, 5);
	cout << "Ho va ten";
	gotoxy(106, 5);
	cout << "Phai";
	for (int i = trang * 18 + 0;i < nds && i <= 18 + trang * 18; i++)
	{
		gotoxy(5, 7 + i);cout << i;
		gotoxy(19, 7 + i);
		cout << ds[i]->cmnd;
		gotoxy(50, 7 + i);
		cout <<ds[i]->ho <<" "<< ds[i]->ten;
		gotoxy(106, 7 + i);
		cout <<ds[i]->sex;
	}
}
void Free(tree &root)
{
	if (root == NULL)return;
		Free(root->pLeft);
		Free(root->pRight);
		delete root;
}
void edit_hk(DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_CHUYEN_BAY& First)
{
backout:

	system("cls");
	Time();
	Free(ds_hk.TREE);
	ds_hk.sl = 0;
	ds_hk.TREE = NULL;
	read_hk(ds_hk.TREE);
	preOrder(ds_hk.TREE, ds, ds_hk.sl);
back:
	system("cls");
	int trang = 0;
	int tong = 0;
	if (ds_hk.sl == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (ds_hk.sl / 18 + 1);
	}
	result_dshanhkhach(ds, ds_hk.sl);
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	gotoxy(90, 3);cout << "TINH NANG EDIT";
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << trang+1 << "/" << tong;
	readfile_cb(First);;
	gotoxy(15, 3);cout << "Search cmnd:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 57)
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			b[i] = '\0';
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)break;
						gotoxy(5, 7 + l);cout << i;
						gotoxy(19, 7 + l);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + l);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + l);
						cout << ds[i]->sex;
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
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)break;
						gotoxy(5, 7 + k);cout << i;
						gotoxy(19, 7 + k);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + k);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + k);
						cout << ds[i]->sex;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				result_dshanhkhach(ds, ds_hk.sl);
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
		u = ds_hk.sl;
		for (int i = 0;i <= u;i++)
		{
			a[i] = i;
		}
	}
	//==========================================================================================================================//
	gotoxy(0, 7);cout << "==>";
	int f = 7;
	int p = 0;
	box_nho(100, 27, 15, 2);
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang+1 << "/" << tong;
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	//================================================================================================================//
	f = 7;
main:
	system("cls");
	Time();
	gotoxy(50, 0);cout << "TINH NANG EDIT";
	gotoxy(0, 1);cout << "Nhan <ESC> de thoat khong luu";
	gotoxy(50, 0);cout << "TINH NANG EDIT";
	gotoxy(0, 1);cout << "Nhan <ESC> de thoat khong luu";
	gotoxy(70, f);cout << " <==";
	for (int i = 0;i < 41;i++)
	{
		gotoxy(30 + i, 7);
		cout << " ";
	}
	gotoxy(30, 7);cout << "Chung Minh Nhan dan: " << ds[a[p]]->cmnd;
	for (int i = 0;i < 41;i++)
	{
		gotoxy(30 + i, 8);
		cout << " ";
	}
	gotoxy(30, 8);cout << "Ho: " << ds[a[p]]->ho;
	for (int i = 0;i < 41;i++)
	{
		gotoxy(30 + i, 9);
		cout << " ";
	}
	gotoxy(30, 9);cout << "Ten: " << ds[a[p]]->ten;
	for (int i = 0;i < 41;i++)
	{
		gotoxy(30 + i, 10);
		cout << " ";
	}
	gotoxy(30, 10);cout << "Gioi tinh: " << ds[a[p]]->sex;
	gotoxy(30, 11);cout << "Luu va Thoat";
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
			}
		}
		else if (c == 80)
		{
			if (f < 11)
			{
				f += 1;
			}

		}
		if (c == 27)
		{
			system("cls");
			goto back;
		}
		if (f > 7)
		{
			gotoxy(70, f - 1);
			printf("    ");
		}
		if (f < 11)
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
	case 7:
	{
		string cmp;
		cmp = ds[a[p]]->cmnd;
	xuat:
		gotoxy(0, 1);cout << "Nhan <ESC> de quay lai        ";
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0;j <= 50;j++)
		{
			gotoxy(50 + j, 7);cout << " ";
		}
		//gotoxy(53, 8);
		int n = 0;
		do {
			for (int i = 0;i < 15;i++)
			{
				gotoxy(50 + i, 7);cout << " ";
			}
			tmp = block_number(8, 50, 7);
			if (tmp[0] == '.')goto main;
		} while (tmp[0] != '\0' || strlen(tmp) < 9);
		while (tmp[n] != '\0')
		{
			ds[a[p]]->cmnd[n] = tmp[n];
			n++;
			ds[a[p]]->cmnd[n] = '\0';
		}
		//p = First;
		if (same_testcmnd(ds_hk.TREE, ds[a[p]]->cmnd) == 1)
		{
			gotoxy(50, 0);
			cout << "nhap trung xin nhap lai";
			_getch();
			for (int i = 0;i < 50;i++)
			{
				gotoxy(49 + i, 0);
				cout << " ";
			}
			goto xuat;
		}
		DS_CHUYEN_BAY v;
		v = First;
		while (v != NULL)
		{
			for (int i = 0;i <= v->cb.ds_ve.n;i++)
			{
				if (cmp == v->cb.ds_ve.cmnd[i])
				{
					v->cb.ds_ve.cmnd[i] = ds[a[p]]->cmnd;
				}
			}
			v = v->next;
		}
		break;
	}
	case 8:
	{
		gotoxy(0, 1);cout << "Nhan <ESC> de quay lai        ";
		int n = 0;
		char* tmp = new char[100];
		do {
			for (int j = 0;j <= 50;j++)
			{
				gotoxy(34 + j, 8);cout << " ";
			}
			tmp = block_char(21, 50, 8);
			if (tmp[0] == '.')goto main;
		} while (tmp[0] == '\0');
		while (tmp[n] != '\0')
		{
			ds[a[p]]->ho[n] = tmp[n];
			n++;
			ds[a[p]]->ho[n] = '\0';
		}
	}
	break;
	case 9:
	{
		gotoxy(0, 1);cout << "Nhan <ESC> de quay lai        ";
		int n = 0;
		char* tmp = new char[100];
		do {
			for (int j = 0;j <= 50;j++)
			{
				gotoxy(35 + j, 9);cout << " ";
			}
			tmp = block_char(21, 50, 9);
			if (tmp[0] == '.')goto main;
		} while (tmp[0] = '\0');
		while (tmp[n] != '\0')
		{
			ds[a[p]]->ten[n] = tmp[n];
			n++;
			ds[a[p]]->ten[n] = '\0';
		}
		break;
	}
	case 10:
	{
		gotoxy(0, 1);cout << "Nhan <ESC> de quay lai        ";
		//int n = 0;
		//char* tmp = new char[100];
		//do {
		//	for (int j = 0;j <= 50;j++)
		//	{
		//		gotoxy(41 + j, 10);cout << " ";
		//	}
		//	tmp = block_char(6, 50, 10);
		//	if (tmp[0] == '.')goto main;
		//} while (tmp[0] == '\0');
		//while (tmp[n] != '\0')
		//{
		//	ds[a[p]]->sex[n] = tmp[n];
		//	n++;
		//	ds[a[p]]->sex[n] = '\0';
		//}
		if (lua_chon_gt() == 1)
		{
			ds[a[p]]->sex[0] = 'N';
			ds[a[p]]->sex[1] = 'a';
			ds[a[p]]->sex[2] = 'm';
			ds[a[p]]->sex[3] = '\0';
		}
		else if (lua_chon_gt() == 0)
		{
			ds[a[p]]->sex[0] = 'N';
			ds[a[p]]->sex[1] = 'u';
			ds[a[p]]->sex[2] = '\0';
		}
		break;
	}
	case 11:
	{
		int t;
		t = ds_hk.sl;
		hanh_khach* v;
		Free(ds_hk.TREE);
		ds_hk.TREE = NULL;
		for (int i = 0;i < t;i++)
		{
			v = new_node(ds[i]->cmnd);
			strcpy_s(v->ho, ds[i]->ho);
			strcpy_s(v->ten, ds[i]->ten);
			strcpy_s(v->sex, ds[i]->sex);
			//insert_tree(ds_hk.TREE, v);
		}
		system("cls");
		yes_no_hk(ds_hk.TREE, First);
		system("cls");
		goto backout;
	}
	}
	goto main;
}
int yes_no_hk(tree &t,DS_CHUYEN_BAY &First)
{
	Time();
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
		write_hk(t);
		writefile_flight(First);
		system("cls");
		return 0;
	case 13:
		return 1;
	}
}
int do_cao(tree root)
{
	int h = 0;
	if (root != NULL) {
		int l_height = do_cao(root->pLeft);
		int r_height = do_cao(root->pRight);
		int max_height = Max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int cap_nhat_bf(tree root)
{
	int l_height = do_cao(root->pLeft);
	int r_height = do_cao(root->pRight);
	int b_factor = l_height - r_height;
	return b_factor;
}

tree quay_trai(tree root)
{
	tree p;
	p = root->pRight;
	root->pRight = p->pLeft;
	p->pLeft = root;
	return p;
}

tree quay_phai(tree root)
{
	tree p;
	p = root->pLeft;
	root->pLeft = p->pRight;
	p->pRight = root;
	return p;
}
tree quay_trai_phai(tree root)
{
	tree t;
	t = root->pLeft;
	root->pLeft = quay_trai(t);
	return quay_phai(root);
}

tree quay_phai_trai(tree root)
{
	tree t;
	t = root->pRight;
	root->pRight = quay_phai(t);
	return quay_trai(root);
}

void balance(tree& root)
{
	int bal_factor = cap_nhat_bf(root);
	if (bal_factor > 1)
	{
		if (cap_nhat_bf(root->pLeft) > 0)
			root = quay_phai(root);
		else
			root = quay_trai_phai(root);
	}
	else if (bal_factor < -1)
	{
		if (cap_nhat_bf(root->pRight) > 0)
			root = quay_phai_trai(root);
		else
			root = quay_trai(root);
	}
	return;
}
tree search(tree node) //tim node chua gia tri be nhat cua nut cha hien tai
{
	while (node->pLeft != NULL)
		node = node->pLeft;
	return node;
}

void chon_delete_hk(tree& root, string key)
{
	if (root == NULL) return;

	string a = root->cmnd;

	if (key < a)
	{
		chon_delete_hk(root->pLeft, key);
		balance(root);
	}
	else if (key > a)
	{
		chon_delete_hk(root->pRight, key);
		balance(root);
	}
	else
	{
		if (root->pRight == NULL)
		{
			tree p = root;
			root = p->pLeft;
			delete p;
			return;
		}
		else if (root->pLeft == NULL)
		{
			tree p = root;
			root = p->pRight;
			delete p;
			return;
		}
		else
		{
			tree p = search(root->pRight);
			root->cmnd = p->cmnd;
			chon_delete_hk(root->pRight, p->cmnd);
		}
	}
}
void Delete_hk(DS_HANH_KHACH& ds_hk, hanh_khach* ds[], DS_CHUYEN_BAY& First)
{
	//read_hk(t);
backout:
	system("cls");
	Time();
	Free(ds_hk.TREE);
	ds_hk.sl = 0;
	ds_hk.TREE = NULL;
	read_hk(ds_hk.TREE);
	preOrder(ds_hk.TREE, ds, ds_hk.sl);
back:
	int trang = 0;
	int tong = 0;
	if (ds_hk.sl == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (ds_hk.sl / 18 + 1);
	}
	readfile_cb(First);
	result_dshanhkhach(ds, ds_hk.sl);
	gotoxy(90, 3);cout << "TINH NANG XOA";
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << trang+1 << "/" << tong;
	gotoxy(15, 3);cout << "Search cmnd:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 57)
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			b[i] = '\0';
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)break;
						gotoxy(5, 7 + l);cout << i;
						gotoxy(19, 7 + l);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + l);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + l);
						cout << ds[i]->sex;
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
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)break;
						gotoxy(5, 7 + k);cout << i;
						gotoxy(19, 7 + k);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + k);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + k);
						cout << ds[i]->sex;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				result_dshanhkhach(ds, ds_hk.sl);
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
		u = ds_hk.sl;
		for (int i = 0;i <= u;i++)
		{
			a[i] = i;
		}
	}
	//==========================================================================================================================//
	gotoxy(0, 7);cout << "==>";
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 13);
	//========================================================================================================//
	DS_CHUYEN_BAY v;
	v = First;
	while (v != NULL)
	{
		for (int i = 0;i <= v->cb.ds_ve.n;i++)
		{
			if (ds[a[p]]->cmnd == v->cb.ds_ve.cmnd[i])
			{
				v->cb.ds_ve.cmnd[i] = "";
				v->cb.ds_ve.sl_da_ban = v->cb.ds_ve.sl_da_ban - 1;
				v->cb.ds_ve.sl_con = v->cb.ds_ve.sl_con + 1;
			}
		}
		v = v->next;
	}
	chon_delete_hk(ds_hk.TREE, ds[a[p]]->cmnd);
	system("cls");
	gotoxy(50, 11);cout << "Ban co chac la xoa khong!";
	yes_no_hk(ds_hk.TREE, First);
	goto backout;
}
void xem_hk(DS_HANH_KHACH& ds_hk, hanh_khach* ds[])
{
back:
	system("cls");
	int trang = 0;
	int tong = 0;
	if (ds_hk.sl == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (ds_hk.sl / 18 + 1);
	}
	box_nho(100, 27, 15, 2);
	gotoxy(101, 28);cout << "Trang: " << trang+1 << "/" << tong;
	result_dshanhkhach(ds, ds_hk.sl);
	box_nho(5, 27, 15, 2);
	gotoxy(6, 28);printf("<ESC> Quay lai");
	box_nho(22, 27, 16, 2);
	gotoxy(24, 28);cout << "<ENTER> de chon";
	gotoxy(90, 3);cout << "TINH NANG EDIT";
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	gotoxy(15, 3);cout << "Search cmnd:";
	connhay_on();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 57)
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			b[i] = '\0';
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int l = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)break;
						gotoxy(5, 7 + l);cout << i;
						gotoxy(19, 7 + l);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + l);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + l);
						cout << ds[i]->sex;
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
			string tim_cmnd;
			tim_cmnd = b;
			connhay_off();
			int k = 0;
			for (int i = 0; i < ds_hk.sl; i++)
			{
				for (int j = 0; j < tim_cmnd.length(); j++)
				{
					if (ds[i]->cmnd[j] != tim_cmnd[j])
						break;
					if (j == tim_cmnd.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)break;
						gotoxy(5, 7 + k);cout << i;
						gotoxy(19, 7 + k);
						cout << ds[i]->cmnd;
						gotoxy(50, 7 + k);
						cout << ds[i]->ho << " " << ds[i]->ten;
						gotoxy(106, 7 + k);
						cout << ds[i]->sex;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				result_dshanhkhach(ds, ds_hk.sl);
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
		u = ds_hk.sl;
		for (int i = 0;i <= u;i++)
		{
			a[i] = i;
		}
	}
	//==========================================================================================================================//
	gotoxy(0, 7);cout << "==>";
	int f = 7;
	int p = 0;
	box_nho(100, 27, 15, 2);
kay:
	f = 7;
	gotoxy(0, 7);cout << "==>";
	do
	{
		gotoxy(101, 28);cout << "Trang: " << trang+1 << "/" << tong;
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
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
		//if (c == 27)goto back;
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
				for (int i = 0;i < 28;i++)
				{
					gotoxy(10 + i, j + 7);
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
			for (int i = trang * 18 + 0;i < ds_hk.sl && i <= 18 + trang * 18; i++)
			{
				gotoxy(5, 7 + k);cout << i;
				gotoxy(19, 7 + k);
				cout << ds[i]->cmnd;
				gotoxy(50, 7 + k);
				cout << ds[i]->ho << " " << ds[i]->ten;
				gotoxy(106, 7 + k);
				cout << ds[i]->sex;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoxy(0, f);
		cout << "==>";
	} while (c != 27);
}

