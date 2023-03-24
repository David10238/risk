#include <iostream>
#include <SDL2/SDL.h>
#include "src/graphics.h"
#include "src/board.h"
#include "src/collider.h"

board game_board = board();
graphics ctx;
bool gameStarted = false;

std::array<SDL_Rect, 6> createPlayerBoxes(){
    constexpr int BUTTON_WIDTH = 600;
    constexpr int BUFFER = 20;
    
    const int SCREEN_HEIGHT = ctx.getHeight();
    const int SCREEN_WIDTH = ctx.getWidth();

    const int BUTTON_HEIGHT = (SCREEN_HEIGHT - BUFFER * 7) / 6;;

    std::array<SDL_Rect, 6> arr;
    for(int i = 0; i < arr.size(); i++){
        arr[i].h = BUTTON_HEIGHT;
        arr[i].w = BUTTON_WIDTH;
        arr[i].x = (SCREEN_WIDTH / 2) - (BUTTON_WIDTH / 2);
        arr[i].y = (BUFFER) + (BUFFER + BUTTON_HEIGHT)*i;
    }
    return arr;
}
const std::array<SDL_Rect, 6> playercounts_boxes = createPlayerBoxes();

void handleClick(int x, int y){
    std::cout << "x: " << x << " y: " << y << std::endl;
    if(!gameStarted){
        for(int i = 0; i < playercounts_boxes.size(); i++){
            if(collider::check(playercounts_boxes[i], x, y)){
                gameStarted = true;
                std::cout << "Selected " << i+1 << " players" << std::endl;
            }
        }
        return;
    }

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

void renderGame(){
    ctx.drawBackground();
    for(territory t : game_board.territories){
        ctx.drawTerritory(t);
    }
}

void renderMenu(){
    for(SDL_Rect box : playercounts_boxes){
        ctx.fillRect(&box, 255, 255, 255, 255);
    }
}


int main(){ 
    std::cout << "Luanching" << std::endl;

    SDL_Event event;

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
        
        if(gameStarted){
            renderGame();
        }
        else{
            renderMenu();
        }
        
        ctx.render();
        SDL_Delay(5);
    }

    return EXIT_SUCCESS;
}