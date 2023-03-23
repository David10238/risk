
#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include <memory>

#include "image.h"

class graphics {
private:
    SDL_Renderer *renderer;
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    image *boardImg;
public:
    graphics(SDL_Renderer *renderer, SDL_Window *window, int SCREEN_WIDTH, int SCREEN_HEIGHT);
    graphics() = delete;
    ~graphics();
    void drawBackground();
    void clear();
    void render();
};

#endif