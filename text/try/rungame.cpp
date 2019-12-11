#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"random_number.h"
#include <string>
#include"draw.h"
using namespace std;
void rungame(SDL_Renderer *renderer){
    int num1, num2;
   double answer;
   SDL_Rect    desRect;
   desRect.x=230;
   desRect.y=20;

   string text;
   srand(time(0));
   do{
       int bad_guess=0, true_guess=0;
       char question=49;
        do{
            string num;
            num=question;
            draw_line(renderer);
            draw_dap_an(renderer,num,desRect);
            char op;
            op=rand_op();
            random_number(&num1,&num2);
            text= chuyen(num1) +" "+ op +" "+chuyen(num2)+" = ?";
            draw_phep_tinh(renderer, text);
            cout<<"\n"<<num1<<" "<<op<<" "<<num2<<" =";
            tinh_Dap_an(op,&answer,num1,num2);
            int r=rand()%3;
            random_choose(op, r,answer,renderer);
            cin_yourguess(r,&true_guess,&bad_guess, renderer);
            if(check_finish(true_guess, bad_guess,renderer)==1) break;
            question= question+1;
        }while (bad_guess<5);
        draw_play_again(renderer);
        cout<<"\nDo you play again? (Y/N) :\n";
   } while (play()!=1);
}
