#include<iostream>
#include<SDL.h>

using namespace std;

int main()
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
                        if ( mouseX>=90&& mouseX<=210&& mouseY>=160 && mouseY<=220 ) {
                            return 1;
                        }
                    }
                }
            }
        }
	}

}
