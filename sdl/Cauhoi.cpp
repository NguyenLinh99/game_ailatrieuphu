/*#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "CauHoi.h"
#include <SDL.h>
#include "draw.h"

//SDL_Renderer *renderer = NULL;
//SDL_Window *window = NULL;


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

int Stt=0;


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

void xuat_cau_hoi_ngau_nhien(List l, int sttCau)
{
    string text[5];
    string tch;
	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == sttCau)
		{
		    tch = p->BoCauHoi.cauhoi;
		    SDL_Rect  desRect;
            desRect.x=200;
            desRect.y=300;
            renderText(tch, desRect);
		   text[0]= p->BoCauHoi.a;
            text[1]= p->BoCauHoi.b;
            text[2]= p->BoCauHoi.c;
            text[3]= p->BoCauHoi.d;
            desRect.x=210;
            desRect.y=400;
            for(int i=0; i<4; i++){
                if(i==0)
                    renderText(text[i], desRect);
                else if(i==1){
                    desRect.x = desRect.x+200;
                    renderText(text[i], desRect);
                }

                else if(i==2){
                    desRect.x=210;
                    desRect.y = desRect.y+100;
                    renderText(text[i], desRect);
                }

                else if(i==3){
                    desRect.x = desRect.x+200;
                    renderText(text[i], desRect);
                }

            }

		}
		i++;
	}

}

void rungame()
{
    List l;
    l.head = l.tail = NULL;
    file(l);
    SDL_Event event;

    bool kt = true;

    while(kt){

        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_1:
                    xuat_cau_hoi_ngau_nhien(l, 1);
                    break;
                case SDLK_2:
                    kt = false;
                    break;


            }
        }

    }
}*/




