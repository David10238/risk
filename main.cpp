#include <iostream>
#include <SDL2/SDL.h>
#include "src/graphics.h"


int main(){ 
    std::cout << "Luanching" << std::endl;

    SDL_Event event;

    graphics ctx;

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

    return EXIT_SUCCESS;
}