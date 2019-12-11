#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Cauhoi.h"
#include "ChucNang.h"
#include "VeKhung.h"

using namespace std;

int Stt=0;
ChucNang cn = ChucNang();


Node *TaoNode(string cauhoi, string a, string b, string c, string d, char DapAn)
{
	Node *P = new Node;
	P->BoCauHoi.cauhoi = cauhoi;
	P->BoCauHoi.a = a;
	P->BoCauHoi.b = b;
	P->BoCauHoi.c = c;
	P->BoCauHoi.d = d;
	P->BoCauHoi.STT = Stt;
	P->BoCauHoi.DapAn = DapAn;
	P->p = NULL;
	return P;
}

void addtail( Node *a,List &l)
{
	if(l.head==NULL)
	{
		l.head=a;
		l.tail=l.head;
	}
	else
	{
		l.tail-> p=a;
		l.tail =a;
	}
}

void file(List &l)
{
	string cauhoi, a ,b, c, d;
	char DapAn;
	int soluong;
	ifstream f("doc1.txt");
	f>>soluong;
	string temp;
	getline(f, temp);
	for(int i = 0; i<soluong; i++)
	{
		Stt ++;
		getline(f, cauhoi);
		getline(f, a);
		getline(f, b);
		getline(f, c);
		getline(f, d);
		f>>DapAn;
		getline(f, temp);
		Node *p = TaoNode(cauhoi, a, b, c, d, DapAn);
		addtail(p, l);
	}
}

Node *laycauhoihientai( int stt ,List l)
{

	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == stt)
		{
			return p;
		}
		i++;
	}
}

char xuat_cau_hoi_ngau_nhien(List l, int sttCau)
{
	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == sttCau)
		{
            VeKhung vk = VeKhung(35, 7, 70, 7, "");
            vk.SetChuoi("Cau hoi:  " + p->BoCauHoi.cauhoi);

			VeKhung vk1 = VeKhung(40, 15, 20, 4, "");
            vk1.SetChuoi(p->BoCauHoi.a);

			VeKhung vk2 = VeKhung(75, 15, 20, 4, "");
            vk2.SetChuoi(p->BoCauHoi.b);

			VeKhung vk3 = VeKhung(40, 20, 20, 4, "");
            vk3.SetChuoi(p->BoCauHoi.c);

			VeKhung vk4 = VeKhung(75, 20, 20, 4, "");
            vk4.SetChuoi(p->BoCauHoi.d);

            return p->BoCauHoi.DapAn;
		}
		i++;
	}
}

void _HoiKhanGia(Node *p)
{
	int a, b, c, d;
	srand(time(NULL));
	int random = 60 +rand() %21;
	char dapan = p->BoCauHoi.DapAn;
	switch(dapan)
	{
	case 'A':
		{
			a = random;
			b = (100 - a)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 'B':
		{
			b = random;
			a = (100 - b)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 'C':
		{
			c = random;
			a = (100 - c)/3; b = (100-a-c)/4; d = 100 - a - b - c;
			break;
		}
	case 'D':
		{
			d = random;
			a = (100 - d)/3; c = (100-a-d)/4; b = 100 -a -d -c;
			break;
		}
	}

	cout << "Y kien cua khan gia:\n";
	cout << "A: " << a << "%" <<endl;
	cout << "B: " << b << "%" <<endl;
	cout << "C: " << c << "%" <<endl;
	cout << "D: " << d << "%" <<endl;
}

void _HoiYKienNguoiThan(Node *p)
{
	char dapan[2];
	srand(time(NULL));
	int index = rand()% 2;
	dapan[0] = p->BoCauHoi.DapAn;
	if(index==0)
	{
		cout <<"Nguoi than ban chon cau: " <<dapan[0]<<endl;
	}
	else
	{
		if(dapan[index] + 1 >4)
		{
			dapan[1] = 'A';
		}
		else
		{
			dapan[1] = dapan[0] + 1;
		}
		cout<<"Nguoi than ban chon cau: "<<dapan[1]<<endl;
	}

}

void _50_50(Node *p)
{
	int dapan[2];
	dapan[0] = p->BoCauHoi.DapAn;

	if(dapan[0] + 1 >4)
	{
		dapan[1] = rand()%2+2;
	}
	else
	{
		dapan[1] = dapan[0] + 1;
	}

	cout<<"May tinh da chon ra 2 phuong an co the dung la: "<<dapan[0]<<" va "<<dapan[1]<<endl;
}

void trogiup( int b[] , int stt, List l)
{

    cout<<"BAN CO 3 SU TRO GIUP SAU:\n";
    cout<<"\n\n";
    Sleep(500);
    cout<<"|======================================|\n";
    cout<<"| 1.  GOI DIEN CHO NGUOI THAN          |\n";
    cout<<"|======================================|\n";
    cout<<"|======================================|\n";
    cout<<"| 2.  LOAI BO 50/100                   |\n";
    cout<<"|======================================|\n";
    cout<<"|======================================|\n";
    cout<<"| 3.  HOI Y KIEN KHAN GIA TRUONG QUAY  |\n";
    cout<<"|======================================|\n\n\n";

    Sleep(200);
    cout << "Ban chon su tro giup so: ";

	int a;
	do{
        cin>>a;
	}while(a!=1 && a!=2 && a!=3 );

    if(b[1]==0&&a==1||b[2]==0&&a==2||b[3]==0&&a==3){
        cout<<"\n\n Quyen tro giup nay da duoc su dung roi :\n";
        cout<<"\n\n Ban tiep tuc su dung quyen tro giup so: ";
        int a;
        do{
            cin>>a;
        }while(a!=1 && a!=2 && a!=3 );
            _getch();
    }

    if(a==b[1]){
        _HoiYKienNguoiThan(laycauhoihientai(stt,l));
        b[1]=0;
        _getch();
    }
    if(a==b[2]){
        _50_50(laycauhoihientai(stt,l));
        b[2]=0;
        _getch();
    }
    if(a==b[3]){
        _HoiKhanGia(laycauhoihientai(stt,l));
        b[3]=0;
        _getch();
    }
}




