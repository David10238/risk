
#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL2/SDL.h>

class collider {
public:
    static bool check(SDL_Rect rect, int x, int y);
};

#endif