#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include <cstdlib>
#include <ctime>
#include "VeKhung.h"

using namespace std;


struct Info {
    unsigned int STT;
    string cauhoi;
    string a,b,c,d;
    char DapAn;
};
struct Node{
    Info BoCauHoi;
    Node *p;
};
struct List{
    Node *head;
    Node *tail;
    int soluong;
};


Node * TaoNode(string cauhoi, string a, string b, string c, string d, char DapAn);

void addtail( Node *a,List &l);

void file(List &l);

char xuat_cau_hoi_ngau_nhien(List l, int sttCau);

Node *laycauhoihientai( int stt ,List l);

void _HoiKhanGia(Node *p);

void _HoiYKienNguoiThan(Node *p);

void _50_50(Node *p);

void trogiup(int b[], int stt, List l);



