
#include <iostream>
#include "graphics.h"

graphics::graphics(int SCREEN_WIDTH, int SCREEN_HEIGHT): SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT) {
    SDL_Init(SDL_INIT_VIDEO);

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cout << "Unable to init SDL_image: " << IMG_GetError() << std::endl;
	}
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Risk");

    this->boardImg = new image(renderer, "/home/david10238/Desktop/riskImages/board.png");
}

graphics::~graphics(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
    
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