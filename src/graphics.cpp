
#include "graphics.h"

graphics::graphics(SDL_Renderer *renderer, SDL_Window *window, int SCREEN_WIDTH, int SCREEN_HEIGHT) : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Risk");

    this->boardImg = new image(renderer, "/home/david10238/Desktop/riskImages/board.png");
}

graphics::~graphics(){
    delete boardImg;
}

void graphics::clear(){
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void graphics::drawBackground(){
    this->boardImg->draw();
}

void graphics::render(){
    SDL_RenderPresent(this->renderer);
}