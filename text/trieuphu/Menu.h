#pragma once
#include "ChucNang.h"
#include "VeKhung.h"
class Menu
{
private:
	VeKhung batDau;
	VeKhung troGiup;
	VeKhung thoat;
public:
	Menu();
	~Menu();
public:
	void ShowMenu();
	void ChonBatDau();
	void ChonThongTin();
	void ChonThoat();
	void InHuongDan();
	void InThongTin();
};

