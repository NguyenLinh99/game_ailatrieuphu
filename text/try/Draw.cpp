#include<iostream>
#include<SDL.h>
#include<SDL_main.h>
#include<SDL_ttf.h>
#include<string>
using namespace std;
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 350;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";


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
        SDL_Delay(100);
    }
}
void draw0(SDL_Renderer* renderer){

    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH-500 ;
    filled_rect.y = SCREEN_HEIGHT-350 ;
    filled_rect.w = 500;
    filled_rect.h = 350;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &filled_rect);
    SDL_RenderPresent( renderer);

}
void draw_name1 (SDL_Renderer* renderer){
    draw0(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    SDL_RenderDrawLine(renderer, 50, 50, 450, 50);
    SDL_RenderDrawLine(renderer, 50, 60, 450, 60);
    SDL_RenderDrawLine(renderer, 50, 250, 450, 250);
    SDL_RenderDrawLine(renderer, 50, 260, 450, 260);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 35);
    SDL_Color  fg = {120, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "GAMES For 1st GRADERS", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "GAMES For 1st GRADERS\n", &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x = 30;// cách mép trái cửa sổ
    desRect.y = 100;// cách mép trên cửa sổ
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();

    SDL_Texture *Texture;
    SDL_Surface *Surface;
    TTF_Init() ;
    TTF_Font*  fonts = TTF_OpenFont("arial.ttf", 30);
    SDL_Color  fgs = {120, 0, 0};
    Surface = TTF_RenderText_Blended( fonts, "c - play", fgs );
    Texture = SDL_CreateTextureFromSurface( renderer, Surface );
    SDL_Rect    srcRests;
    SDL_Rect    desRects;
    TTF_SizeText(fonts, "c - play", &srcRests.w, &srcRests.h );
    srcRests.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRests.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRects.x =200;// cách mép trái cửa sổ
    desRects.y = 150;// cách mép trên cửa sổ
    desRects.w = srcRests.w;
    desRects.h = srcRests.h;
    SDL_RenderCopy( renderer, Texture, &srcRests, &desRects );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
void draw_line(SDL_Renderer* renderer){

    draw0(renderer);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color  fg = {120, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "Question number     :", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "Question number     :", &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x = 20;// cách mép trái cửa sổ
    desRect.y = 20;// cách mép trên cửa sổ
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
    //ke khung 3x3

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    SDL_RenderDrawLine(renderer, 10, 70, 490, 70);
    SDL_RenderDrawLine(renderer, 10, 140, 490, 140);
    SDL_RenderDrawLine(renderer, 10, 70, 10, 140);
    SDL_RenderDrawLine(renderer, 490, 70, 490, 140);

    SDL_RenderDrawLine(renderer, 10, 170, 490, 170);
    SDL_RenderDrawLine(renderer, 10, 240, 490, 240);
    SDL_RenderDrawLine(renderer, 10, 170, 10, 240);
    SDL_RenderDrawLine(renderer, 130, 170, 130, 240);
    SDL_RenderDrawLine(renderer, 250, 170, 250, 240);
    SDL_RenderDrawLine(renderer, 370, 170, 370, 240);
    SDL_RenderDrawLine(renderer, 490, 170, 490, 240);

    SDL_RenderPresent(renderer);
}
void draw_dap_an(SDL_Renderer* renderer,std:: string text,SDL_Rect    desRect ){
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
void draw_phep_tinh(SDL_Renderer* renderer,std:: string text){
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 30);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x=100;
    desRect.y= 90;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
void drawwon(SDL_Renderer* renderer,std:: string text){
    draw0(renderer);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 50);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x =60;
    desRect.y =140;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
    SDL_Delay(1000);
}


void draw_play_again(SDL_Renderer* renderer){
    draw0( renderer);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 32);
    SDL_Color  fg = {255, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "PLAY AGAIN ? (y/n)", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "PLAY AGAIN ? (y/n):", &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x = 80;// cách mép trái cửa sổ
    desRect.y = 150;// cách mép trên cửa sổ
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
