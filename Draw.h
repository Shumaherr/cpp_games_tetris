//
// Created by Aleksandr on 19.02.2021.
//

#ifndef TETRIS_DRAW_H
#define TETRIS_DRAW_H


#include "Component.h"
#include <SDL.h>
#include <vector>

class Draw: public Component {
public:
    Draw();
    void DrawObject(SDL_Renderer* render) override ;

private:
    SDL_Color *color;
    std::vector<SDL_Rect *> rects;
};


#endif //TETRIS_DRAW_H
