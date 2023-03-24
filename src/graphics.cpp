
#include <iostream>
#include <array>
#include "graphics.h"

constexpr int SCREEN_WIDTH = 1200;
constexpr int BOARD_HEIGHT = 650;
constexpr int UI_HEIGHT = 250;
constexpr int SCREEN_HEIGHT = BOARD_HEIGHT + UI_HEIGHT;

graphics::graphics() {
    SDL_Init(SDL_INIT_VIDEO);

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cout << "Unable to init SDL_image: " << IMG_GetError() << std::endl;
	}
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
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

void graphics::drawTerritory(territory t){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect;
    rect.x = t.x,
    rect.y = t.y;
    rect.h = 20;
    rect.w = 20;
    SDL_RenderFillRect(renderer, &rect);
}

void graphics::fillRect(SDL_Rect *rect, int r, int g, int b, int a){
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, rect);
}

void graphics::render(){
    SDL_RenderPresent(this->renderer);
}

const int graphics::getHeight() const{
    return SCREEN_HEIGHT;
}

const int graphics::getWidth() const{
    return SCREEN_WIDTH;
}