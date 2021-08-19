//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <SDL_render.h>

class Component {
public:
    virtual void Update(float deltaTime) = 0;
};
