
#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include <memory>

#include "image.h"
#include "board.h"

class graphics {
private:
    SDL_Renderer *renderer;
    SDL_Window *window;
    image *boardImg;
public:
    graphics();
    ~graphics();
    void drawBackground();
    void drawTerritory(territory t);
    void clear();
    void render();
};

#endif