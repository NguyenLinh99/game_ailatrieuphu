#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <SDL_main.h>
#include "Draw.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>

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
    string text[5];
    string cauhoi;
	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == sttCau)
		{
		    cauhoi = p->BoCauHoi.cauhoi;
		    SDL_Rect  desRect;
            desRect.x=315;
            desRect.y=250;
            renderText(cauhoi, desRect);
            text[0]= p->BoCauHoi.a;
            text[1]= p->BoCauHoi.b;
            text[2]= p->BoCauHoi.c;
            text[3]= p->BoCauHoi.d;
            desRect.x=320;
            desRect.y=470;
            renderText(text[0], desRect);
            desRect.x=695;
            renderText(text[1], desRect);
            desRect.x=320;
            desRect.y=620;
            renderText(text[2], desRect);
            desRect.x=695;
            renderText(text[3], desRect);

            return p->BoCauHoi.DapAn;

		}
		i++;
	}

}

void _HoiYKienNguoiThan(Node *p)
{
    SDL_Rect desRect;
    desRect.x=700;
    desRect.y=530;
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
		if(dapan[0] + 1 >4)
		{
			dapan[1] = 'a';
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

string chuyen(int n)
{
    string text;
    while(n != 0){
        char b;
        b = n%10+48;
		n = n/10;
		text = b+text;
    }
    return text;
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
    s[0] = chuyen(a);
    s[1] = chuyen(b);
    s[2] = chuyen(c);
    s[3] = chuyen(d);
    Draw("khangia.jpg");
    desRect.x = 480;
    desRect.y = 270;
    renderText(s[0], desRect);
    desRect.x = 880;
    renderText(s[1], desRect);
    desRect.y = 460;
    desRect.x = 480;
    renderText(s[2], desRect);
    desRect.x = 880;
    renderText(s[3], desRect);
}

char mouse()
{
    char choose;
    SDL_Event event;
    while (true){

		while (SDL_PollEvent(&event)){

			switch (event.type){

                case SDL_QUIT: return 0;

                case SDL_MOUSEBUTTONDOWN:{

                    int mouseX, mouseY;
                    Uint32 buttons;
                    buttons = SDL_GetMouseState(&mouseX, &mouseY);

                    if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT) ){
                        if ( mouseX>=320&& mouseX<=600&& mouseY>=460 && mouseY<=530 ) {
                            choose = 'a';
                            return choose;
                        }
                        else if ( mouseX>=670&& mouseX<=970&& mouseY>=460 && mouseY<=530 ) {
                            choose = 'b';
                            return choose;
                        }
                        else if ( mouseX>=320&& mouseX<=600&& mouseY>=600 && mouseY<=670 ) {
                            choose = 'c';
                            return choose;
                        }
                        else if ( mouseX>=670&& mouseX<=970&& mouseY>=600 && mouseY<=670 ) {
                            choose = 'd';
                            return choose;
                        }
                        else if ( mouseX>=260&& mouseX<=380&& mouseY>=30 && mouseY<=140 ) {
                            choose = '1';
                            return choose;
                        }
                        else if ( mouseX>=430&& mouseX<=600&& mouseY>=30 && mouseY<=140 ) {
                            choose = '2';
                            return choose;
                        }

                    }
                }
            }
        }
	}
	return choose;


}

int play()
{
    int choose;
    SDL_Event event;
    while(true)
    {
        if(chuot(340, 675, 450, 590)==1){
            choose=1;
        }
        if(choose==1)
            return 0;
        else
            return 1;
    }
}

int check_finish(int true_guess, int bad_guess)
{
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
    char choose;
    SDL_Event event;
    SDL_Rect desRect;

    do{
        int bad_guess=0, true_guess=0;
        int check1 = 0;
        int check2 = 0;
        do{

            int random = 1+rand()% 48;
      tieptuc:
            Draw("bg.bmp");

            if(check1==1){
                desRect.x = 320;
                desRect.y = 100;
                renderText("x", desRect);
            }
            if(check2==1){
                desRect.x = 550;
                desRect.y = 100;
                renderText("x", desRect);
            }
            char dapan = xuat_cau_hoi_ngau_nhien(l, random);

            char traloi=mouse();

            if(traloi== '1'){
                _HoiYKienNguoiThan(laycauhoihientai(random, l));
                check1 = 1;
                SDL_Delay(2000);
                goto tieptuc;
             }

            else if(traloi == '2'){
                _HoiKhanGia(laycauhoihientai(random, l));
                check2 = 1;
                SDL_Delay(2000);
                goto tieptuc;
            }

            else if (traloi== dapan){
                desRect.x = 350;
                desRect.y = 700;
                renderText("TRUE", desRect);
                SDL_Delay(1000);
                cout<<"\ntrue";
                true_guess+=1;
                cout<<"\nXin chuc mung! Ban da vuot qua cau: "<<true_guess;

             }

             else if(traloi!=dapan && traloi!='1'){
                desRect.x = 350;
                desRect.y = 700;
                renderText("FALSE", desRect);
                SDL_Delay(1000);
                cout<<"\nfalse";
                bad_guess+=1;

             }

            if(check_finish(true_guess, bad_guess)==1) break;

        }while (bad_guess<1 && true_guess<=15);

    }while (play()!=1);

}

int main( int argc, char* argv[] )
{

    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    init( "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false );
    SDL_Event event;

    Draw("altp.jpg");
    PlaySound(TEXT("altp.wav"), NULL, SND_ASYNC);
    while(true ){

        chuot(340, 675, 450, 590);
        choi();

    }

    clean();
    return 0;
}
