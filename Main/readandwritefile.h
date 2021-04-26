#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include "ctdl.h"
#include <conio.h>
#include "flight.h"
using namespace std;

void writefile_plane(DS_MAYBAY& mb)
{
	ofstream fi;
	fi.open("ds_maybay.txt", ios_base::out);
	for (int i = 0;i < mb.sl;i++)
	{
		fi << mb.dsmaybay[i]->loaimaybay << endl;
		fi << mb.dsmaybay[i]->sohieu << endl;
		fi << mb.dsmaybay[i]->socho << endl;
	}
	fi.close();
}
void readfile_plane(DS_MAYBAY& mb)
{
	ifstream fi;
	fi.open("ds_maybay.txt");
	mb.sl = 0;

	while (fi.eof() != true)
	{
		mb.dsmaybay[mb.sl] = new MAY_BAY;
		fi.getline(mb.dsmaybay[mb.sl]->loaimaybay, 40);
		fi.getline(mb.dsmaybay[mb.sl]->sohieu, 15);
		fi >> mb.dsmaybay[mb.sl]->socho;
		fi.ignore();
		mb.sl++;
	}
	fi.close();
}
void writefile_flight(DS_CHUYEN_BAY &first)
{
	
	chuyenbay cb;
	ofstream fi;
	//p = first;
	if (first == NULL)return;
	fi.open("ds_chuyenbay.txt", ios_base::out);
	for (DS_CHUYEN_BAY p = first; p != NULL; p = p->next)
	{
		fi << p->cb.machuyenbay << endl;
		fi << p->cb.sohieu << endl;
		fi << p->cb.sanbay << endl;
		fi << p->cb.ngay << endl;
		fi << p->cb.thang << endl;
		fi << p->cb.nam << endl;
		fi << p->cb.gio << endl;
		fi << p->cb.phut << endl;
		fi << p->cb.ds_ve.n<<endl;
		fi << p->cb.trangthai<<endl;
		fi << p->cb.ds_ve.sl_con << endl;
		if (p->next == NULL && p->cb.ds_ve.sl_da_ban == 0)
		{
			fi << p->cb.ds_ve.sl_da_ban<<endl;
		}
		else
		{
			fi << p->cb.ds_ve.sl_da_ban << endl;
		}
		for (int i = 0; i < p->cb.ds_ve.n+1; i++)
		{
			if (p->next == NULL && i != p->cb.ds_ve.n+1 && p->cb.ds_ve.cmnd[i].length() == 9)
			{
				fi << i << endl;
				fi << p->cb.ds_ve.cmnd[i]<<endl;
			}
			else if (p->cb.ds_ve.cmnd[i].length() == 9 && p->next != NULL && i != p->cb.ds_ve.n+1)
			{
				fi << i << endl;
				fi << p->cb.ds_ve.cmnd[i] << endl;
			}
		}
	}
	fi.close();
}
void insert_last(DS_CHUYEN_BAY& first, chuyenbay x)
{
	DS_CHUYEN_BAY p = new_nodecb();
	p->cb = x;
	p->next = NULL;
	if (first == NULL) first = p;
	else {
		DS_CHUYEN_BAY last = first;
		for (; last->next != NULL; last = last->next);
		last->next = p;
	}
}
void readfile_cb(DS_CHUYEN_BAY& First)
{
	DS_CHUYEN_BAY p;
	chuyenbay cb;
	ifstream fi;
	char a[11];
	fi.open("ds_chuyenbay.txt");
	First=NULL;
	clearlist(First);
	int i = 0;
	while (!fi.eof())
	{
		fi.getline(cb.machuyenbay, 15);
		if (_strcmpi(cb.machuyenbay, "")==0)break;
		fi.getline(cb.sohieu,16);
		fi.getline(cb.sanbay, 100);
		fi.getline(a, 4);
		cb.ngay = atoi(a);
		fi.getline(a, 4);
		cb.thang = atoi(a);
		fi.getline(a, 5);
		cb.nam = atoi(a);
		fi.getline(a, 5);
		cb.gio = atoi(a);
		fi.getline(a, 4);
		cb.phut = atoi(a);
		fi.getline(a, 4);
		cb.ds_ve.n = atoi(a);
		fi.getline(a, 5);
		cb.trangthai=atoi(a);
		int x = cb.ds_ve.n;
		cb.ds_ve.cmnd = new string[x+1];
		fi >> cb.ds_ve.sl_con;
		fi >> cb.ds_ve.sl_da_ban;

		int temp;
		for (int i = 0; i < cb.ds_ve.sl_da_ban; i++)
		{
			fi >> temp;
			fi >> cb.ds_ve.cmnd[temp];
		}
		insert_last(First, cb);
		fi.ignore();
	
	}
	fi.close();
}
void read_hk(tree &t)
{
	hanh_khach *p;
	DS_HANH_KHACH hk;
	ifstream fi;
	char a[11];
	fi.open("ds_hanhkhach.txt");
	string cmnd;
	//Free(t);
	t = NULL;
	while (fi.eof() != true)
	{
		getline(fi,cmnd);
		if (cmnd == "")break;
		p = new_node(cmnd);
		fi.getline(p->ho, 21);
		fi.getline(p->ten, 21);
		fi >> p->sex;
		insert_tree(t, p);
		hk.sl++;
		fi.ignore();
	}
	fi.close();
}
void insert_fi(tree& t, ofstream& fi)
{
	if (t != NULL)
	{
		fi << t->cmnd<<endl;
		fi << t->ho << endl;
		fi << t->ten << endl;
		fi << t->sex << endl;
		insert_fi(t->pLeft, fi);
		insert_fi(t->pRight, fi);
	}
}
void write_hk(tree& t)
{
	ofstream fi;
	fi.open("ds_hanhkhach.txt", ios_base::out);
	insert_fi(t, fi);
	fi.close();
}
