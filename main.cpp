#include <iostream>
#include <SDL2/SDL.h>
#include "src/graphics.h"


int main(){ 
    std::cout << "Luanching" << std::endl;

    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    graphics ctx(renderer, window, 1000, 500);

    int running = true;
    while(running) {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
    
        ctx.clear();
        ctx.drawBackground();
        ctx.render();
        SDL_Delay(5);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}