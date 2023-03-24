#include <iostream>
#include <SDL2/SDL.h>
#include "src/graphics.h"
#include "src/board.h"

board game_board = board();

void handleClick(int x, int y){
    std::cout << "x: " << x << " y: " << y << std::endl;
    for(territory t : game_board.territories){
        int dx = x-t.x;
        int dy = y-t.y;
        if((0 < dx && dx < 20) && (0 < dy && dy < 20)){
            std::cout << "Clicked on: " << t.name << std::endl;
            for(int edge : t.edges){
                std::cout << game_board.territories[edge].name << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main(){ 
    std::cout << "Luanching" << std::endl;

    SDL_Event event;

    graphics ctx;

    int running = true;
    bool mouseDown = false;
    while(running) {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }

            // need to do a finicky toggle thing to register only one click
            if(event.type = SDL_MOUSEBUTTONDOWN && event.button.clicks == SDL_BUTTON_LEFT){
                if(!mouseDown){
                    int x = event.button.x;
                    int y = event.button.y;
                    handleClick(x, y);
                }
                mouseDown = !mouseDown;
            }
        }
    
        ctx.clear();
        
        ctx.drawBackground();
        for(territory t : game_board.territories){
            ctx.drawTerritory(t);
        }
        
        ctx.render();
        SDL_Delay(5);
    }

    return EXIT_SUCCESS;
}