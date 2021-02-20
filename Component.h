//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <SDL2-2.0.12/include/SDL_render.h>

class Component {
public:
    virtual void Update(float deltaTime);
    virtual void DrawObject(SDL_Renderer* render);
};
