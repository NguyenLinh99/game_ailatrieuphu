#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "CauHoi.h"
#include <SDL.h>
#include "draw.h"
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
char xuat_cau_hoi_ngau_nhien(List l, int sttCau, SDL_Renderer* renderer)
{
    string text[5];
    string tch;
	int i = 1;
	for(Node *p = l.head; p != NULL; p=p->p)
	{

	    draw_line(renderer);
		if(i == sttCau)
		{
		    tch = p->BoCauHoi.cauhoi;
		    SDL_Rect    desRect;
            draw_cau_hoi(renderer, tch);
		    text[0]= p->BoCauHoi.a;
            text[1]= p->BoCauHoi.b;
            text[2]= p->BoCauHoi.c;
            text[3]= p->BoCauHoi.d;
            desRect.x=160;
            desRect.y=300;
            for(int i=0; i<4; i++){
                if(i==0)
                    draw_dap_an(renderer, text[i], desRect);
                else if(i==1){
                    desRect.x = desRect.x+200;
                    draw_dap_an(renderer, text[i], desRect);
                }

                else if(i==2){
                    desRect.x=160;
                    desRect.y = desRect.y+100;
                    draw_dap_an(renderer, text[i], desRect);
                }

                else if(i==3){
                    desRect.x = desRect.x+200;
                    draw_dap_an(renderer, text[i], desRect);
                }

            }


            return p->BoCauHoi.DapAn;

		}
		i++;
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
            case SDLK_y:
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

int cin_yourguess(char dapan, int *true_guess, int *bad_guess, SDL_Renderer* renderer){
    char choose;
    SDL_Event event;
    SDL_Rect desRect;
    desRect.x=80;
    desRect.y=470;
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
            }
            if(choose==dapan) {
                draw_dap_an(renderer, "true", desRect);
                SDL_Delay(1000);
                cout<<"\ntrue";
                *true_guess+=1;
                cout<<"\nXin chuc mung! Ban da vuot qua cau: "<<*true_guess;
                return 1;
            }
            else {
                draw_dap_an(renderer, "false", desRect);
                SDL_Delay(1000);
                cout<<"\nfalse";
                *bad_guess+=1;
                kt = false;
                return 0;
            }
        }
    }

}

int check_finish(int true_guess, int bad_guess, SDL_Renderer* renderer){
    if(true_guess==15){
        drawwon(renderer, "YOU WON!!! BAN CO 150 trieu VND");
        SDL_Delay(1000);
        drawwon(renderer, "BAN DA TRO THANH TRIEU PHU! HAY BAO BAN BE DI AN NHA ^-^");
        cout<<"\nYou win!!!!";
        return 1;
    }
    else if(true_guess>=10 && bad_guess==1){
        drawwon(renderer, "GAME OVER! BAN CO 22 trieu VND");
        cout<<"\nGame over!!!";
        SDL_Delay(1000);
        return 1;
    }
    else if(true_guess>=5 && true_guess<10 && bad_guess==1){
        drawwon(renderer, "GAME OVER! BAN CO 5 trieu VND");
        SDL_Delay(1000);
        cout<<"\nGame over!!!";
        return 1;
    }

    else if(true_guess<5 && bad_guess==1){
        drawwon(renderer, "GAME OVER! BAN DA THANH AN MAY!!! ^-^");
        SDL_Delay(1000);
        cout<<"\nGame over!!!";
        return 1;
    }
    return 0;
}

/*void trogiup( int b[] , int stt, List l, SDL_Renderer *renderer)
{
    draw0(renderer);
    SDL_Rect desRect;
    SDL_Event event;
    desRect.x=300;
    desRect.y=260;
    string s1 = "1. GOI DIEN CHO NGUOI THAN ";
    string s2 = "2. LOAI BO 50/100";
    string s3 = "3. HOI Y KIEN KHAN GIA TRUONG QUAY";
    draw_tro_giup(renderer, s1, desRect);
    desRect.y=310;
    draw_tro_giup(renderer, s2, desRect);
    desRect.y=360;
    draw_tro_giup(renderer, s3, desRect);

    while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_1:
                choi(renderer);
                break;
            case SDLK_2:
                    //choose=2;
                break;
            case SDLK_3:
                    //choose=3;
                break;
}*/


void Chon_Menu(SDL_Renderer *renderer)
{
    draw0(renderer);
    SDL_Rect desRect;
    desRect.x=280;
    desRect.y=190;
    draw_menu(renderer, " BAT DAU", desRect);
    //desRect.y=300;
    //draw_menu(renderer, "HUONG DAN", desRect);
    desRect.y=410;
    draw_menu(renderer, "  THOAT", desRect);

}

void choi(SDL_Renderer *renderer)
{
    List l;
    l.head = l.tail = NULL;
    file(l);
    srand(time(0));
    SDL_Rect desRect;
    PlaySound(TEXT("bb.wav"), NULL, SND_ASYNC);
    do{
        int bad_guess=0, true_guess=0;
        do{
            int random = 1+rand()% 50;
            draw_line(renderer);

            char dapan = xuat_cau_hoi_ngau_nhien(l, random, renderer);
            cin_yourguess(dapan,&true_guess,&bad_guess, renderer);
            if(check_finish(true_guess, bad_guess,renderer)==1) break;

        }while (bad_guess<1 && true_guess<=15);
        draw_play_again(renderer);
        cout<<"\nDo you play again? (Y/N) :\n";
    }while (play()!=1);

}

void rungame(SDL_Renderer *renderer)
{
    SDL_Event event;

    Chon_Menu(renderer);

    bool kt = true;

    while(kt){

        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_1:

                    choi(renderer);
                    break;
                case SDLK_2:
                    kt = false;
                    break;


            }
        }

    }
}





