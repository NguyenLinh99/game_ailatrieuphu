#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 330;
const int SCREEN_HEIGHT = 330;
const string WINDOW_TITLE = "Game";

//window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//gScreenSurface = SDL_GetWindowSurface( window );




void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
     // SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thu?ng ch?y v?i môi tru?ng bình thu?ng ? nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi ch?y ? máy th?c hành WinXP ? tru?ng (máy ?o)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
    }
}

void draw_name (SDL_Renderer* renderer){

    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 30);
    SDL_Color  fg = {120, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "NUMBERED", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "NUMBERED", &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x = 20;// cách mép trái cửa sổ
    desRect.y = 10;// cách mép trên cửa sổ
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

int mouse(int x1, int x2, int y1, int y2)
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

int main(int argc, char*argv[]){

    SDL_Window* window=NULL;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_RenderClear(renderer);

    SDL_Surface* gScreenSurface=NULL;
    SDL_Surface* BG=NULL;

    window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    gScreenSurface = SDL_GetWindowSurface( window );
    BG = SDL_LoadBMP("bg.bmp");

    bool quit = false;

    while( !quit ){
        SDL_BlitSurface( BG, NULL, gScreenSurface, NULL );
        draw_name(renderer);
        SDL_UpdateWindowSurface( window );
        if(mouse(60, 210, 50, 150)==1) cout << "hello";
        //waitUntilKeyPressed();
        quitSDL(window, renderer);
    }
	return 1;

}
