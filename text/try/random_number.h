#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>
std::string chuyen(double num);
int play();
void random_number(int *num1, int *num2);
char rand_op();
void tinh_Dap_an(char op, double *answer, int num1, int num2);
void random_choose(char op, int r,double answer, SDL_Renderer* renderer);
int cin_yourguess(int r, int *true_guess, int *bad_guess, SDL_Renderer* renderer);
int check_finish(int true_guess, int bad_guess,SDL_Renderer* renderer);
