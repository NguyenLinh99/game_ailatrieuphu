#include<windows.h>
#include "Menu.h"
#include "VeKhung.h"


Menu::Menu()
{
	this->batDau = VeKhung(46, 8, 27, 5, "         BAT DAU");
	this->troGiup=VeKhung(46, 15, 27, 5, "        HUONG DAN");
	this->thoat = VeKhung(46, 22, 27, 5, "          THOAT");
}


Menu::~Menu()
{
}

void Menu::ShowMenu()
{
	system("cls");
	this->batDau.Ve();
	this->troGiup.Ve();
	this->thoat.Ve();
	this->ChonBatDau();
	this->InHuongDan();
}

void Menu::ChonBatDau()
{
	this->batDau.DoiMauKhung(3);
	this->troGiup.MauMacDinh();
	this->thoat.MauMacDinh();
}

void Menu::ChonThongTin()
{
	this->batDau.MauMacDinh();
	this->troGiup.DoiMauKhung(3);
	this->thoat.MauMacDinh();
}

void Menu::ChonThoat()
{
	this->batDau.MauMacDinh();
	this->troGiup.MauMacDinh();
	this->thoat.DoiMauKhung(3);
}

void Menu::InHuongDan()
{
    system("cls");
	ChucNang cn = ChucNang();
	cn.GotoXY(1, 1);
	cn.TextColor(13);
	printf("                     1:Chon Bat Dau, 2: Chon Tro Giup, 3: Chon Thoat, Enter: Chon, Esc: Thoat");
}

void Menu::InThongTin()
{
	system("cls");
	ChucNang cn = ChucNang();
	cn.TextColor(14);
    cout<<"\t\t\|============================================|\n";
    cout<<"\t\t\|                HUONG DAN                   |\n";
    cout<<"\t\t\|============================================|\n\n";
    cn.TextColor(7);
    char chuoi1[]="      - Vuot qua 15 cau hoi cua chuong trinh ban se danh duoc 150 trieu dong";
    char chuoi2[]="      - Ban co cac quyen tro giup:";
    int g=strlen(chuoi1);
    int h=strlen(chuoi2);
    for(int i=0; i<g; i++){
        cout<<chuoi1[i];
        Sleep(50);
    }
    cout << "\n\n";
    for(int i=0; i<h; i++){
        cout<<chuoi2[i];
        Sleep(50);
    }
    cout << "\n\n";

    cn.TextColor(9);
    cout<<"      |=====================================================|\n";
    cout<<"      |1. GOI DIEN CHO NGUOI THAN                           |\n";
    cout<<"      | Ban co quyen goi dien cho 1 nguoi than de tro giup  |\n";
    cout<<"      | ve cau hoi trong khoang thoi gian 30 giay           |\n";
    cout<<"      |=====================================================|\n\n";
    Sleep(100);
    cn.TextColor(10);
    cout<<"      |==============================================================|\n";
    cout<<"      |2.TRO GIUP 50/50: may tinh se lay 2 dap an gan chinh xac nhat |\n";
    cout<<"      |==============================================================|\n\n";
    Sleep(100);
    cn.TextColor(11);
    cout<<"      |=====================================================|\n";
    cout<<"      |3. HOI Y KIEN KHAN GIA: Khan gia trong truong quay   |\n";
    cout<<"      |  se dua ra dap an ma cho ho la chinh xac.           |\n";
    cout<<"      |=====================================================|\n\n\n";
    Sleep(2000);
    cn.TextColor(14);
    cout<<"      |===============================|\n";
    cout<<"      |  Nhap 1 Quay lai Chuong Trinh |\n";
    cout<<"      |===============================|\n";
    cout<<"      |===============================|\n";
    cout<<"      |  Nhap bat ky de thoat         |\n";
    cout<<"      |===============================|\n";
    cn.TextColor(7);
	_getch();
}

