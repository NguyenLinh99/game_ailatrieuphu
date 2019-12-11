#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<SDL.h>

using namespace std;


/*struct Info {
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
};*/

struct Info;
struct Node;
struct List;


Node * TaoNode(string cauhoi, string a, string b, string c, string d, char DapAn);

void addtail( Node *a,List &l);

void file(List &l);

char xuat_cau_hoi_ngau_nhien(List l, int sttCau, SDL_Renderer* renderer);

Node *laycauhoihientai( int stt ,List l);

void rungame(SDL_Renderer *renderer);

int cin_yourguess(char dapan, int *true_guess, int *bad_guess, SDL_Renderer* renderer);

int check_finish(int true_guess, int bad_guess, SDL_Renderer* renderer);

int play();

void Chon_Menu(SDL_Renderer *renderer);

void choi(SDL_Renderer *renderer);

void rungame(SDL_Renderer *renderer);




