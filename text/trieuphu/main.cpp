#include <iostream>
#include <vector>
#include<windows.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include "ChucNang.h"
#include "VeKhung.h"
#include "Menu.h"
#include "Cauhoi.h"

using namespace std;


int cau = 1;
int Max = 15;

int main()
{
    ChucNang cn = ChucNang();
    VeKhung vk = VeKhung();

    cn.resizeConsole(1100, 600);
	cn.Deletec();
	srand(time(0));
    int flag=1;

	int luaChon = 1;
	bool kt = true;

	while(kt){

	quaylai:

        Menu menu = Menu();
        menu.ShowMenu();
        menu.ChonBatDau();

		char chon = _getch();
		switch (chon){
            case 49:
            {
                menu.ChonBatDau();
                luaChon = 1;
                break;
            }
            case 50:
                menu.ChonThongTin();
                luaChon = 2;
                break;
            case 51:
                menu.ChonThoat();
                luaChon = 3;
                break;
            default:
                break;
            }

            if (chon == 13)
            {
                switch (luaChon){
                case 1:
                {
                    int b[5]= {0,1,2,3,4};
                    int tien = 0;
                    int i=0;
                    List l;
                    l.head = l.tail = NULL;
                    file(l);
            tieptuc: do{
                        int random = 1+rand()% 50;
                        system("cls");
                        cn.Deletec();
                    tieptuc1:
                        vk.Screen();
                        srand(time(0));

                        char DapAn, nhap;
                        int phuongan;
                        DapAn = xuat_cau_hoi_ngau_nhien(l,random);
                        cn.GotoXY(35, 25);
                        cout << "1. Tro Giup - 2.Tra Loi - 3.Dung Cuoc Choi :";
                        cn.GotoXY(35, 26);
                        cout << "Ban muon: ";
                        cn.GotoXY(45, 26);
                        do{
                            cin >> phuongan;
                        }while(phuongan != 1 && phuongan != 2 && phuongan != 3 );

                        switch(phuongan)
                        {
                        case 1 :{
                            system("cls");
                            trogiup(b,random,l);
                            char u = _getch();
                            if(u==13){
                                system("cls");
                                goto tieptuc1;
                            }
                        };

                        case 2 :{

                            char s[] = "Hay nhap cau tra loi cua ban: ";
                            cn.GotoXY(35, 28);
                            for(int j=0; j<strlen(s); j++){
                                cout << s[j];
                                Sleep(50);
                            }
                            cn.GotoXY(65, 28);
                            cin>>nhap;
                            if(DapAn == nhap){
                                if(i==1)
                                    tien = tien+200;
                                if(i==2)
                                    tien = tien+200;
                                if(i==3)
                                    tien = tien+200;
                                if(i==4)
                                    tien = tien+400;
                                if(i==5)
                                    tien = tien+1000;
                                if(i==6)
                                    tien = tien+1000;
                                if(i==7)
                                    tien = tien+3000;
                                if(i==8)
                                    tien = tien+4000;
                                if(i==9)
                                    tien = tien+4000;
                                if(i==10)
                                    tien = tien+8000;
                                if(i==11)
                                    tien = tien+8000;
                                if(i==12)
                                    tien = tien+10000;
                                if(i==13)
                                    tien = tien+20000;
                                if(i==14)
                                    tien = tien+25000;
                                if(i==15)
                                    tien = tien+65000;
                                cn.GotoXY(110, 10);
                                cout << "Xin Chuc Mung!";
                                cn.GotoXY(110, 11);
                                cout << "Ban da tra loi dung.";
                                /*cn.GotoXY(110, 12);
                                cout << "So tien hien tai cua ";
                                cn.GotoXY(110, 13);
                                cout << "ban khi da qua cau " <<i-1<<" la: " <<tien<<" VND \n";*/

                                if(i==15){
                                    system("cls");
                                    system("color 47");
                                    cout<<"\n\n\t\t RAT TUYET VOI \n";
                                    cout<<"\t CHUC MUNG ";
                                    cout<<" BAN LA NGUOI CHIEN THANG \n\n";
                                    cout<<"\tSO PHAN THUONG BAN NHAN DUOC LA: ";
                                    cout<<tien<<" VND \n";
                                    cout<<"\t|===============================|\n";
                                    cout<<"\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                                    cout<<"\t|===============================|\n";
                                    cout<<"\t|===============================|\n";
                                    cout<<"\t|  Nhap Bat ky De Thoat         |\n";
                                    cout<<"\t|===============================|\n";
                                    int u;
                                    cin>>u;
                                    if(u==1){
                                        system("cls");
                                        goto quaylai;
                                    }
                                }
                                i++;
                                char u = _getch();
                                if(u==13){
                                    system("cls");
                                    goto tieptuc;
                                }
                            }
                            else flag = 0;

                            if(flag == 0){
                                system("cls");
                                system("color 2e");

                                cout<<"Dap an dung la : "<<DapAn<<endl;
                                cout<<"\n\n";
                                char s1[50]="                             GAME OVER ";
                                for(int i=0; i<strlen(s1); i++)
                                {
                                    cout << s1[i];
                                    Sleep(50);
                                }

                                cout<<"\n\n\t\tSO TIEN THUONG BAN NHAN DUOC LA: ";
                                cout<<tien<<" VND \n\n";
                                Sleep(100);
                                cout<<"\t\t|===============================|\n";
                                cout<<"\t\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                                cout<<"\t\t|===============================|\n";
                                cout<<"\t\t|===============================|\n";
                                cout<<"\t\t|  Nhap Bat ky De thoat         |\n";
                                cout<<"\t\t|===============================|\n";
                                int u;
                                cin>>u;
                                if(u==1){
                                    system("cls");
                                    goto quaylai;
                                }
                                else break;
                            }

                    }break;
				case 3 :{
				    system("cls");
					system("color 2e");
                    cout<<"\n\t\t \n\n";
					cout<<"Dap An dung la :"<<DapAn<<endl;
                    char s1[50]="                            END GAME ";
                    for(int i=0; i<strlen(s1); i++)
                    {
                        cout<<s1[i];
                        Sleep(50);
                    }
                    cout<<"\n\n\t\tSO TIEN THUONG BAN NHAN DUOC LA: ";
                    cout<<tien<<" VND \n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap Bat ky De thoat         |\n";
                    cout<<"\t\t|===============================|\n";
                    int u;
                    cin>>u;
                    if(u==1){
						system("cls");
						goto quaylai;
					}
					else break;

                }break;
                        }
                        }while(flag == 1);
            }break;


			case 2:
				menu.InThongTin();
				menu.ShowMenu();
				luaChon = 1;
				break;
			case 3:
				kt = false;
                }
            }
	}

}


