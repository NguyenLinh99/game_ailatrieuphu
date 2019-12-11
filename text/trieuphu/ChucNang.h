#pragma once
#include <conio.h>
#include <iostream>
using namespace std;
class ChucNang
{
public:
	ChucNang();
public:
    void resizeConsole(int width, int height);
	void GotoXY(int x, int y);
	void TextColor(int x);
	void Xoa(int x, int y);
	void Deletec();
};
