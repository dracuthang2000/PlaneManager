#pragma once
#include<iostream>
//#define NULL 0
#define MAX 300
#define MAXV 1000
using namespace std;
struct may_bay
{
	char sohieu[16];
	char loaimaybay[41];
	int socho;
};
typedef struct may_bay MAY_BAY;
struct ds_maybay
{
	MAY_BAY* dsmaybay[MAX];
	int sl = 0;
};
typedef struct ds_maybay DS_MAYBAY;
struct ve
{
	int n;
	string *cmnd;
	int sl_con = 0;
	int sl_da_ban = 0;
};
typedef struct ve VE;

struct chuyenbay
{
	char sohieu[16];
	char sanbay[100];
	int cb;
	char machuyenbay[15];
	int ngay;
	int gio;
	int phut;
	int thang;
	int nam;
	int trangthai;
	VE ds_ve;
};

typedef struct chuyenbay chuyen_bay;
struct ds_chuyen_bay
{
	chuyen_bay cb;
	struct ds_chuyen_bay* next;
	int sl = 0;
};
typedef struct ds_chuyen_bay *DS_CHUYEN_BAY;
//DS_CHUYEN_BAY pFirst,pLast,p;

struct hanh_khach
{
	string cmnd;
	char ho[21];
	char ten[21];
	char sex[7];
	//DS_CHUYEN_BAY ds_mb;
	hanh_khach *pLeft;
	hanh_khach *pRight;
	int hight;
};
typedef struct hanh_khach* tree;
struct ds_hanhkhach
{
	tree TREE = 0;
	int sl = 0;
};
typedef ds_hanhkhach DS_HANH_KHACH;
