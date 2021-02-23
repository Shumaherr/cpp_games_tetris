//
// Created by Aleksandr on 19.02.2021.
//

#include "Draw.h"

void Draw::DrawObject(SDL_Renderer* render, std::vector<SDL_Rect *> rects, SDL_Color* color ) {
    SDL_SetRenderDrawColor(render, color->r, color->g, color->b, color->a);
    SDL_RenderDrawRects(render, rects[0], rects.size());
    SDL_RenderFillRects(render, rects[0], rects.size());
}
