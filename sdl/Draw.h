#include<SDL.h>
#include<SDL_main.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>

void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
void clean();
void Draw(char* path);
void renderText(std:: string text, SDL_Rect desRect);
int mouse(int x1, int x2, int y1, int y2);


