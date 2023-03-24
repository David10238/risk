
#include "collider.h"

bool collider::check(SDL_Rect rect, int x, int y){
    int x_low = rect.x;
    int x_high = x_low + rect.w;
    int y_low = rect.y;
    int y_high = y_low + rect.h;

    return (x_low <= x) && (x <= x_high) && (y_low <= y) && (y <= y_high);
}