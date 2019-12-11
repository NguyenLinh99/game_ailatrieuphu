#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"CauHoi.h"
#include <string>
#include"draw.h"

using namespace std;

void rungame(SDL_Renderer *renderer)
{
    double answer;
    List l;
    l.head = l.tail = NULL;
    file(l);
    srand(time(0));
    SDL_Rect    desRect;
    //desRect.x=230;
    //desRect.y=20;

    srand(time(0));
    do{
        int bad_guess=0, true_guess=0;
        do{
            int random = 1+rand()% 50;
            draw_line(renderer);

            char dapan = xuat_cau_hoi_ngau_nhien(l, random, renderer);
            cin_yourguess(dapan,&true_guess,&bad_guess, renderer);
            if(check_finish(true_guess, bad_guess,renderer)==1) break;
            //question= question+1;
        }while (bad_guess<1 && true_guess<=15);
        draw_play_again(renderer);
        cout<<"\nDo you play again? (Y/N) :\n";
   } while (play()!=1);
}
