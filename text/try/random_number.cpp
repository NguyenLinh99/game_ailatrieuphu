#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"Draw.h"
#include<string>
using namespace std;
std::string chuyen(double num){
    string text;
    double old;
	int i=0,m;

	if(num<0) {
            old=num;
            num=0-num;
	}
	else {
         old =num;
	}
	m=num*100;
	do{
		if(i==2) text='.'+text;
		char b;
		b=m%10+48;
		m=m/10;
		text = b+text;
		i++;
	}while (m!=0);
	if(old<0) text ='-' +text;
	else if(old>0&&old<1) text ="0."+text;
	return text;
}
int play(){
    int choose;
    SDL_Event event;
    while(true)
    {
        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
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
void random_number(int *num1, int *num2){

    *num1=1+rand()%10;
    *num2=1+rand()%10;
}
char rand_op(){
    int o=rand()%4;
    if(o==1) return '+';
    else if(o==2) return '-';
    else if(o==3) return '*';
    else return '/';
}
void tinh_Dap_an(char op, double *answer, int num1, int num2){
    switch(op){
        case '-': *answer=num1-num2;break;
        case '+': *answer=num1+num2;break;
        case '*': *answer=num1*num2; break;
        default: *answer=(double) num1/num2;
    }
}
void random_choose(char op, int r,double answer, SDL_Renderer* renderer){
    std :: string text[5];
    double a[5];
    for(int i=0; i<=3; i++){
        int num3, num4;
        double answer1;
        random_number(&num3,&num4);
        if(r==i) a[i]=answer;
        else {
            switch(op){
                case '-': answer1=num3-num4;break;
                case '+': answer1=num3+num4;break;
                case '*': answer1=num3*num4; break;
                default:{
                     answer1=(double) num3/num4;
                }
            }
            a[i]=answer1;
        }
    }
    text[0]= "A: "+ chuyen(a[0]);
    text[1]="B: " +chuyen(a[1]);
    text[2]= "C: "+ chuyen(a[2]);
    text[3]="D: " +chuyen(a[3]);
    SDL_Rect    desRect;
    desRect.x=30;
    desRect.y=190;
     for(int i=0; i<4; i++){
       draw_dap_an(renderer, text[i], desRect);
        desRect.x= desRect.x+120;
    }
    cout<<fixed<<setprecision(2)<<"\nA: "<<a[0]<<"\tB: "<<a[1]<<"\tC: "<<a[2]<<"\tD: "<<a[3]<<"\n";
}
int cin_yourguess(int r, int *true_guess, int *bad_guess, SDL_Renderer* renderer){
    int choose;
    SDL_Event event;
    SDL_Rect    desRect;
    desRect.x=30;
    desRect.y=270;
    while(true)
    {
        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                choose=0;
                break;
            case SDLK_b:
                choose=1;
                break;
            case SDLK_c:
                choose=2;
                break;
            case SDLK_d:
                choose=3;
                break;
            }
            if(choose==r) {
                    draw_dap_an(renderer, "true", desRect);
                    SDL_Delay(1000);
                cout<<"true";
                *true_guess+=1;
                cout<<"\nNumber of guesses wrong: "<<*bad_guess;
                return 1;
            }
            else {
                    draw_dap_an(renderer, "false", desRect);
                    SDL_Delay(1000);
                cout<<"false";
                *bad_guess+=1;
                cout<<"\nNumber of guesses wrong: "<<*bad_guess;
                return 0;
            }
        }
    }

}
int check_finish(int true_guess, int bad_guess,SDL_Renderer* renderer){
    if(true_guess==5){
            drawwon(renderer, "YOU WON!!!");
        cout<<"\nYou win!!!!";
        return 1;
    }
    else if(bad_guess==5) {
        drawwon(renderer, "GAME OVER!!");
        cout<<"\nGame over!!!";
        return 0;
    }
    return 0;
}

