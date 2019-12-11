#include<SDL.h>
#include<SDL_main.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>

void logSDLError(std::ostream& os,const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void draw0(SDL_Renderer* renderer);
void draw_name1(SDL_Renderer* renderer);
void draw_line(SDL_Renderer* renderer);
void draw_dap_an(SDL_Renderer* renderer,std:: string text,SDL_Rect desRect );
void draw_cau_hoi(SDL_Renderer* renderer,std:: string text);
void draw_play_again(SDL_Renderer* renderer);
void drawwon(SDL_Renderer* renderer,std::string text);
void draw_menu(SDL_Renderer* renderer, std::string text,SDL_Rect desRect);
void Draw1(SDL_Renderer* renderer);
