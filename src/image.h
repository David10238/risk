
#ifndef IMAGE_H
#define GAME_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <memory>

class image {
private:
    int w, h;
    SDL_Renderer *renderer;
    SDL_Texture *img;
    SDL_Rect rect;
public:
    image(SDL_Renderer *renderer, const char *path);
    ~image();
    void draw();
};

#endif