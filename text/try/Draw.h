#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>


void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void draw0(SDL_Renderer* renderer);
void draw_name1 (SDL_Renderer* renderer);
void draw_line(SDL_Renderer* renderer);
void draw_dap_an(SDL_Renderer* renderer,std:: string text,SDL_Rect    desRect );
void draw_phep_tinh(SDL_Renderer* renderer,std:: string text);
void drawwon(SDL_Renderer* renderer,std:: string text);
void draw_play_again(SDL_Renderer* renderer);
