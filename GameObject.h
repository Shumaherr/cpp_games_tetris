//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include "Component.h"
#include "Transform.h"

class Game;
class GameObject {

public:

    virtual void Update(float deltaTime) = 0;

    virtual void Draw(SDL_Renderer *renderer) = 0;

    Transform transform;

protected:
    Game& game;
};

