
#include "image.h"

image::image(SDL_Renderer *renderer, const char *path) {
    this->renderer = renderer;
    SDL_Surface *surface = IMG_Load(path);
    img = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    
    this->rect.x = 0;
    this->rect.y = 0;
    this->rect.w = w;
    this->rect.h = h;
}

image::~image(){
    SDL_DestroyTexture(img);
}

void image::draw(){
    SDL_RenderCopy(renderer, img, NULL, &rect);
}