
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include"menu.h"
#include"plane.h"
#include "AVLtree.h"
#include"flight.h"
#include"bookticket.h"
#include<time.h>
#include "Box.h"
#define boxx 4 //Vi tri x bat dau cua box
#define boxy 1 //Vi tri y bat dau cua box
#define boxs 110 //Box size
using namespace std;
int main()
{
	DS_MAYBAY mb;
	DS_CHUYEN_BAY First;
	chuyen_bay *ds_cb[MAX];
	DS_HANH_KHACH ds_hk;
	hanh_khach* ds[MAX];
	//Box_NhapMayBay();
	//read_hk(ds_hk.TREE);
	//Delete_hk(ds_hk, ds, First);
/*	hanh_khach* p;
	p=new_node("10");
	insert_tree(ds_hk.TREE, p);
	p = new_node("20");
	insert_tree(ds_hk.TREE, p);
	p = new_node("30");
	insert_tree(ds_hk.TREE, p);
	p = new_node("40");
	insert_tree(ds_hk.TREE, p);
	p = new_node("50");
	insert_tree(ds_hk.TREE, p);
	p = new_node("15");
	insert_tree(ds_hk.TREE, p);
	p = new_node("25");
	insert_tree(ds_hk.TREE, p);
	chon_delete_hk(ds_hk.TREE,"15");
	in_ds_tam(ds_hk.TREE)*/;
	//print_tree(ds_hk.TREE);
//	in(ds_hk.TREE, "225768455", 1);
	//in_cb(First,ds_hk, ds, mb,ds_cb);
	//readfile_cb(First);
	//in_date(First);
    //sap_xep(First, mb);
	//box_ke(50, 20);
	//in_ve(First, ds_hk, ds, mb, ds_cb);
	//_getch();
	Menu();
	//box_nho(20, 3,10,3);
	//_getch();
	return 0;
}
