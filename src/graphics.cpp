
#include <iostream>
#include "graphics.h"

constexpr int SCREEN_WIDTH = 1000;
constexpr int BOARD_HEIGHT = 600;
constexpr int UI_HEIGHT = 200;

graphics::graphics() {
    SDL_Init(SDL_INIT_VIDEO);

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cout << "Unable to init SDL_image: " << IMG_GetError() << std::endl;
	}
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, BOARD_HEIGHT + UI_HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Risk");

    boardImg = new image(renderer, "/home/david10238/Desktop/riskImages/board.png");
    boardImg->setLocation(0, 0);
    boardImg->setSize(SCREEN_WIDTH, BOARD_HEIGHT);
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