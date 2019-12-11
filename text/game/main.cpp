#include "CauHoi.h"
#include<SDL.h>
#include<SDL_main.h>
#include"draw.h"
#include"rungame.h"
#include<string>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include <SDL_image.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char*argv[])
{

    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_RenderClear(renderer);
    SDL_Event event;
    SDL_Rect desRect;

    //draw_name1(renderer);
    //Draw1(renderer);
    while(true)
    {
        while(SDL_WaitEvent(&event) != 0&&event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_c:
                Draw1(renderer);
                rungame(renderer);
                break;
            default: return 1;
            }
        }
    }


}




