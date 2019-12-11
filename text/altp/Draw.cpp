#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <SDL_image.h>
#include "Draw.h"
#include <fstream>

using namespace std;
bool isRunning = true;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
void init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen )
{
    int flags = 0;
    if( fullscreen )
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
    {
        window = SDL_CreateWindow( title, xpos, ypos, 1024, 768, flags );
        TTF_Init();

        renderer = SDL_CreateRenderer( window, -1, 0 );
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 ); //mau

        isRunning = true;
    } else { isRunning = false; };
}

void clean()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
}

void Draw(char* path)
{
    SDL_Surface* tmpSurface = IMG_Load( path );
    SDL_Texture* tex = SDL_CreateTextureFromSurface( renderer, tmpSurface );
    SDL_FreeSurface( tmpSurface );

    SDL_Rect src, dest;
    src.x = src.y = 0;
    dest.x = dest.y = 0;
    src.w = dest.w = 1024;
    src.h = dest.h = 768;

    SDL_RenderCopy( renderer, tex, &src, &dest );
    SDL_RenderPresent( renderer );
}

void renderText(std::string text, SDL_Rect desRect)
{
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 20);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect srcRest;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
    SDL_Delay(1000);

}
int chuot(int x1, int x2, int y1, int y2)
{
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
                        if ( mouseX>=x1&& mouseX<=x2&& mouseY>=y1 && mouseY<=y2 ) {
                            return 1;
                        }
                    }
                }
            }
        }
	}
}
