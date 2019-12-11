#include "SDL.h" // thu vien do hoa
#include "SDL_image.h" //anh
#include "SDL_ttf.h"  // chu
#include <SDL_main.h>
#include "Draw.h"//ve
#include <iostream>
#include <fstream> //doc file
#include <ctime> //srand()
#include <cstdlib> //rand sinh so ngau nhien
#include <windows.h> //
#include <mmsystem.h> // cho nhac

using namespace std;

struct Info {
    unsigned int STT;
    string cauhoi;
    string a,b,c,d;
    char DapAn;
};
struct Node{
    Info BoCauHoi;//kieu du lieu
    Node *p; //con tro tro sang thang khac dung de lien ket
};
struct List{
    Node *head; // node dau
    Node *tail; // node cuoi
    int soluong;
};

int Stt=0;


Node *TaoNode(string cauhoi, string a, string b, string c, string d, char DapAn)
{
	Node *P = new Node; // khoi tao;
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

void addtail( Node *a,List &l)//them cuoi
{
	if(l.head==NULL) // neu rong
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

void file(List &l) // doc file
{
	string cauhoi, a ,b, c, d;
	char DapAn;
	int soluong;
	ifstream f("doc1.txt"); // mo file de doc
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

/*Node *laycauhoihientai( int stt ,List l)
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
}*/


char xuat_cau_hoi_ngau_nhien(List l, int sttCau)
{
    string text[5];
    string cauhoi;
	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == sttCau)
		{
		    cauhoi = p->BoCauHoi.cauhoi;
		    SDL_Rect  desRect;//cho tao do cau hoi
            desRect.x=310;
            desRect.y=170;
            renderText(cauhoi, desRect);//render cau hoi len
            text[0]= p->BoCauHoi.a;
            text[1]= p->BoCauHoi.b;
            text[2]= p->BoCauHoi.c;
            text[3]= p->BoCauHoi.d;
            desRect.x=320;
            desRect.y=390;
            for(int i=0; i<4; i++){
                if(i==0)
                    renderText(text[i], desRect);
                else if(i==1){
                    desRect.x = desRect.x+375;
                    renderText(text[i], desRect);
                }

                else if(i==2){
                    desRect.x=320;
                    desRect.y = desRect.y+150;
                    renderText(text[i], desRect);
                }

                else if(i==3){
                    desRect.x = desRect.x+375;
                    renderText(text[i], desRect);
                }

            }
            return p->BoCauHoi.DapAn;

		}
		i++;
	}

}

/*void _HoiYKienNguoiThan(Node *p)
{
    SDL_Rect desRect;
    desRect.x=650;
    desRect.y=500;
	char dapan[2];
	srand(time(NULL));
	int index = rand()% 2;
	dapan[0] = p->BoCauHoi.DapAn;
	string s[2];
	Draw("phone.jpg");
	if(index==0)
	{
	    s[0] = dapan[0];
		renderText(s[0], desRect);
		cout << s[0];
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
		s[1] = dapan[1];
		renderText(s[1], desRect);
		cout << s[1];
	}

}

void _HoiKhanGia(Node *p)
{
    SDL_Rect desRect;
	int a, b, c, d;
	srand(time(NULL));
	int random = 60 +rand() %21;
	char dapan = p->BoCauHoi.DapAn;
	switch(dapan)
	{
	case 'a':
		{
			a = random;
			b = (100 - a)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 'b':
		{
			b = random;
			a = (100 - b)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 'c':
		{
			c = random;
			a = (100 - c)/3; b = (100-a-c)/4; d = 100 - a - b - c;
			break;
		}
	case 'd':
		{
			d = random;
			a = (100 - d)/3; c = (100-a-d)/4; b = 100 -a -d -c;
			break;
		}
	}
    string s[5];
    s[0] = char(a+48);
    s[1] = char(b+48);
    s[2] = char(c+48);
    s[3] = char(d+48);
    Draw("khangia.jpg");
    desRect.x = 350;
    desRect.y = 265;
    renderText(s[0], desRect);
    desRect.x = 640;
    renderText(s[1], desRect);
    desRect.y = 450;
    desRect.x = 350;
    renderText(s[2], desRect);
    desRect.x = 640;
    renderText(s[3], desRect);
}*/


int cin_yourguess(char dapan, int *true_guess, int *bad_guess)
{
    SDL_Rect desRect;
    desRect.x=350;
    desRect.y=700;
    SDL_Event event; // nhap dap an
    char choose;
    bool kt = true;
    while(kt)
    {
        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                choose='a';
                break;
            case SDLK_b:
                choose='b';
                break;
            case SDLK_c:
                choose='c';
                break;
            case SDLK_d:
                choose='d';
                break;
            case SDLK_1:
                choose='1';
                break;
            }

            /*if(choose == '1'){
                Draw("phone.jpg");
                SDL_Delay(1000);
                return 2;
            }

            else*/ if (choose == dapan){
                renderText("TRUE", desRect);
                SDL_Delay(1000);
                cout<<"\ntrue";
                *true_guess+=1;
                cout<<"\nXin chuc mung! Ban da vuot qua cau: "<<*true_guess;
                return 1;
             }
             else{
                renderText("FALSE", desRect);
                SDL_Delay(1000);
                cout<<"\nfalse";
                *bad_guess+=1;
                kt = false;
                return 0;
            }
        }
    }
}

int play(){
    int choose;
    SDL_Event event;
    while(true)
    {
        while(SDL_WaitEvent(&event) != 0 && event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_c:
                choose=1;
                break;
            }
            if(choose==1)
                return 0;
            else
                return 1;

        }
    }
}

int check_finish(int true_guess, int bad_guess){
    if(true_guess==15){
        Draw("win.jpg");
        SDL_Delay(2000);
        cout<<"\nYou win!!!!";
        Draw("altp.jpg");
        return 1;
    }
    else if(true_guess>=10 && bad_guess==1){
        Draw("22.jpg");
        SDL_Delay(2000);
        cout<<"\nGame over!!!";
        Draw("altp.jpg");
        return 1;
    }
    else if(true_guess >=5 && true_guess <10 && bad_guess == 1){
        Draw("5.jpg");
        SDL_Delay(2000);
        cout<<"\nGame over!!!";
        Draw("altp.jpg");
        return 1;
    }
    else if( true_guess < 5 && bad_guess==1){
        Draw("thua.jpg");
        SDL_Delay(2000);
        cout<<"\nGame over!!!";
        Draw("altp.jpg");
        return 1;
    }
    return 0;
}


void choi()
{
    List l;
    l.head = l.tail = NULL;
    file(l);
    srand(time(0));
   /* SDL_Event event;
    SDL_Rect desRect;
    desRect.x = 350;
    desRect.y = 700;*/
    do{
        int bad_guess=0, true_guess=0;
        do{
            int random = 1+rand()% 48;
            Draw("bg.jpg");
            char dapan = xuat_cau_hoi_ngau_nhien(l, random);
            cin_yourguess(dapan, &true_guess, &bad_guess);

            if(check_finish(true_guess, bad_guess)==1) break;

        }while (bad_guess<1 && true_guess<=15);

    }while (play()!=1);

}

int main( int argc, char* argv[] )
{
    /*List l;
    l.head = l.tail = NULL;
    file(l);*/
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    init( "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false );
    SDL_Event event;

    Draw("altp.jpg");
    PlaySound(TEXT("altp.wav"), NULL, SND_ASYNC);//nhac
    while(true ){
        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_c:
                choi();
                break;
            default: break;
            }
        }

    }

    clean();
    return 0;
}
