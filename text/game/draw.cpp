#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>
#include<string>
#include<SDL_image.h>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Ai la trieu phu";


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

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

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
    filled_rect.x = SCREEN_WIDTH-800 ;
    filled_rect.y = SCREEN_HEIGHT-600 ;
    filled_rect.w = 800;
    filled_rect.h = 600;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect);
    SDL_RenderPresent( renderer);

}

void Draw1(SDL_Renderer* renderer)
{
    SDL_Surface* tmpSurface = IMG_Load( "bg.bmp" );
    SDL_Texture* tex = SDL_CreateTextureFromSurface( renderer, tmpSurface );
    SDL_FreeSurface( tmpSurface );

    SDL_Rect src, dest;
    src.x = src.y = 0;
    dest.x = dest.y = 0;
    src.w = dest.w = 1024;
    src.h = dest.h = 768;

    SDL_RenderCopy( renderer, tex, &src, &dest );
//SDL_RenderPresent( renderer );
}

void draw_name1 (SDL_Renderer* renderer){
    draw0(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 50, 150, 750, 150);
    SDL_RenderDrawLine(renderer, 50, 160, 750, 160);
    SDL_RenderDrawLine(renderer, 50, 350, 750, 350);
    SDL_RenderDrawLine(renderer, 50, 360, 750, 360);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 50);
    SDL_Color  fg = {120, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "AI LA TRIEU PHU", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "AI LA TRIEU PHU\n", &srcRest.w, &srcRest.h );
    srcRest.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRest.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRect.x = 200;// cách mép trái cửa sổ
    desRect.y = 200;// cách mép trên cửa sổ
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
    Surface = TTF_RenderText_Blended( fonts, "c - PLAY", fgs );
    Texture = SDL_CreateTextureFromSurface( renderer, Surface );
    SDL_Rect    srcRests;
    SDL_Rect    desRects;
    TTF_SizeText(fonts, "c - PLAY", &srcRests.w, &srcRests.h );
    srcRests.x = 0;//hiên thị từ pixel đầu tiên bên trái
    srcRests.y = 0;//hiển thị từ pixel đầu tiên bên trên
    desRects.x = 320;// cách mép trái cửa sổ
    desRects.y = 300;// cách mép trên cửa sổ
    desRects.w = srcRests.w;
    desRects.h = srcRests.h;
    SDL_RenderCopy( renderer, Texture, &srcRests, &desRects );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
void draw_line(SDL_Renderer* renderer){

    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH-800 ;
    filled_rect.y = SCREEN_HEIGHT-600 ;
    filled_rect.w = 800;
    filled_rect.h = 600;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color  fg = {120, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "Question  :", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "Question  :", &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.x = 20;
    desRect.y = 20;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderDrawLine(renderer, 100, 70, 750, 70);
    SDL_RenderDrawLine(renderer, 100, 200, 750, 200);
    SDL_RenderDrawLine(renderer, 100, 70, 100, 200);
    SDL_RenderDrawLine(renderer, 750, 70, 750, 200);

    SDL_RenderDrawLine(renderer, 150, 270, 300, 270);
    SDL_RenderDrawLine(renderer, 150, 340, 300, 340);
    SDL_RenderDrawLine(renderer, 150, 270, 150, 340);
    SDL_RenderDrawLine(renderer, 300, 270, 300, 340);

    SDL_RenderDrawLine(renderer, 350, 270, 500, 270);
    SDL_RenderDrawLine(renderer, 350, 340, 500, 340);
    SDL_RenderDrawLine(renderer, 350, 270, 350, 340);
    SDL_RenderDrawLine(renderer, 500, 270, 500, 340);


    SDL_RenderDrawLine(renderer, 150, 360, 300, 360);
    SDL_RenderDrawLine(renderer, 150, 430, 300, 430);
    SDL_RenderDrawLine(renderer, 150, 360, 150, 430);
    SDL_RenderDrawLine(renderer, 300, 360, 300, 430);

    SDL_RenderDrawLine(renderer, 350, 360, 500, 360);
    SDL_RenderDrawLine(renderer, 350, 430, 500, 430);
    SDL_RenderDrawLine(renderer, 350, 360, 350, 430);
    SDL_RenderDrawLine(renderer, 500, 360, 500, 430);


    SDL_RenderPresent(renderer);
}
void draw_dap_an(SDL_Renderer* renderer,std:: string text,SDL_Rect    desRect ){
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 20);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}
void draw_cau_hoi(SDL_Renderer* renderer,std:: string text){
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 20);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.x=120;
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
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 30);
    SDL_Color  fg = {130, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, text.c_str(), fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect srcRest;
    SDL_Rect desRect;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.x =160;
    desRect.y =300;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
    SDL_Delay(1000);
}

void draw_menu(SDL_Renderer* renderer, std::string text,SDL_Rect desRect)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 250, 150, 520, 150);
    SDL_RenderDrawLine(renderer, 250, 300, 520, 300);
    SDL_RenderDrawLine(renderer, 250, 150, 250, 300);
    SDL_RenderDrawLine(renderer, 520, 150, 520, 300);

   // SDL_RenderDrawLine(renderer, 250, 270, 520, 270);
   // SDL_RenderDrawLine(renderer, 250, 370, 520, 370);
   // SDL_RenderDrawLine(renderer, 250, 270, 250, 370);
   // SDL_RenderDrawLine(renderer, 520, 270, 520, 370);

    SDL_RenderDrawLine(renderer, 250, 350, 520, 350);
    SDL_RenderDrawLine(renderer, 250, 500, 520, 500);
    SDL_RenderDrawLine(renderer, 250, 350, 250, 500);
    SDL_RenderDrawLine(renderer, 520, 350, 520, 500);

    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 35);
    SDL_Color  fg = {120, 0, 0};

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


void draw_play_again(SDL_Renderer* renderer)
{
    draw0( renderer);
    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 50);
    SDL_Color  fg = {255, 0, 0};
    m_pSurface = TTF_RenderText_Blended( font, "PLAY AGAIN ? (y/n)", fg );
    m_pTexture = SDL_CreateTextureFromSurface( renderer, m_pSurface );
    SDL_Rect    srcRest;
    SDL_Rect    desRect;
    TTF_SizeText(font, "PLAY AGAIN ? (y/n):", &srcRest.w, &srcRest.h );
    srcRest.x = 0;
    srcRest.y = 0;
    desRect.x = 80;
    desRect.y = 150;
    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    SDL_RenderCopy( renderer, m_pTexture, &srcRest, &desRect );
    SDL_RenderPresent( renderer);
    TTF_Quit();
}

/*void draw_tro_giup(SDL_Renderer* renderer, std::string text,SDL_Rect desRect)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 200, 250, 600, 250);
    SDL_RenderDrawLine(renderer, 200, 400, 600, 400);
    SDL_RenderDrawLine(renderer, 200, 250, 200, 400);
    SDL_RenderDrawLine(renderer, 600, 250, 600, 400);

    SDL_RenderDrawLine(renderer, 200, 300, 600, 300);
    SDL_RenderDrawLine(renderer, 200, 350, 600, 350);
    SDL_RenderDrawLine(renderer, 200, 400, 600, 400);
    SDL_RenderDrawLine(renderer, 600, 200, 600, 400);

    SDL_Texture *m_pTexture;
    SDL_Surface *m_pSurface;
    TTF_Init() ;
    TTF_Font*  font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color  fg = {120, 0, 0};

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
}*/

