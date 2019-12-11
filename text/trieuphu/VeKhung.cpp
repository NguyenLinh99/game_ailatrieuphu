#include "VeKhung.h"
#include "ChucNang.h"
#include <iostream>

using namespace std;

#define screenWidth   80
#define screenHeight  28


VeKhung::VeKhung()
{
}
VeKhung::VeKhung(int x,int y,int dai,int rong,string chuoi)
{
	this->x = x;
	this->y = y;
	this->ngang = dai;
	this->cao = rong;
	this->chuoi = chuoi;
}

void VeKhung::Ve()
{
	ChucNang cn = ChucNang();
	cn.GotoXY(this->x,this->y);

	cout << (char)218;
	for (int i = 1; i < this->ngang-1; i++) cout << (char)196;
	cout << (char)191;

	for (int i = 1; i < this->cao-1; i++)
	{
		cn.GotoXY(this->x, this->y+i);
		cout << (char)179;
		for (int j = 1; j < ngang - 1; j++)printf(" ");
		cout << (char)179;
	}

	cn.GotoXY(this->x, this->y + this->cao-1);

	cout << (char)192;
	for (int i = 1; i < this->ngang-1; i++) cout << (char)196;
	cout << (char)217;

	InChuoi();
}

void VeKhung::InChuoi()
{
	ChucNang cn = ChucNang();
	cn.GotoXY(this->x + 1, this->y + 1);

	int dem = 1;
	int viTri = 1;
	while ((viTri-1)<this->chuoi.length())
	{
		cout << chuoi[viTri-1];
		if (viTri % (this->ngang - 2) == 0)
		{
			dem++;
			cn.GotoXY(this->x + 1, this->y + dem);
		}
		viTri++;
	}

}

void VeKhung::DoiMauKhung(int mau)
{
	this->mau = mau;
	ChucNang cn = ChucNang();
	cn.TextColor(mau);
	this->Ve();
}

void VeKhung::XoaToanBo()
{
	ChucNang cn = ChucNang();
	cn.TextColor(this->mau);
	cn.GotoXY(this->x, this->y);
	for (int i = 0; i < this->cao; i++)
	{
		for (int j = 0; j < this->ngang; j++)
		{
			cn.GotoXY(this->x + i, this->y + j);
			printf(" ");
		}
	}

}

void VeKhung::Screen()
{
    ChucNang cn = ChucNang();
    cout<<"|==========================|\n";
    cout<<"| SO TIEN QUA MOI CAU HOI  |\n";
    cout<<"|==========================|\n";
    cn.TextColor(14);
    cout<<"|==========================|\n";
    cout<<"|  Cau 15: 150,000 VND     |\n";
    cout<<"|==========================|\n";
    cn.TextColor(7);
    cout<<"|  Cau 14: 85,000  VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 13: 60,000  VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 12: 40,000  VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 11: 30,000  VND     |\n";
    cn.TextColor(14);
    cout<<"|==========================|\n";
    cout<<"|  Cau 10: 22,000  VND     |\n";
    cout<<"|==========================|\n";
    cn.TextColor(7);
    cout<<"|  Cau 9:  14,000  VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 8:  10,000  VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 7:  6,000   VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 6:  3,000   VND     |\n";
    cn.TextColor(14);
    cout<<"|==========================|\n";
    cout<<"|  Cau 5:  2,000   VND     |\n";
    cout<<"|==========================|\n";
    cn.TextColor(7);
    cout<<"|  Cau 4:  1,000   VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 3:    600   VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 2:    400   VND     |\n";
    cout<<"|==========================|\n";
    cout<<"|  Cau 1:    200   VND     |\n";
    cout<<"|==========================|\n";

}

void VeKhung::SetChuoi(string chuoi)
{
	this->chuoi = chuoi;
	this->XoaToanBo();
	this->Ve();
}

void VeKhung::MauMacDinh()
{
	ChucNang cn = ChucNang();
	cn.TextColor(15);
	this->Ve();
}


