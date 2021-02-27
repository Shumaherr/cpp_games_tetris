//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <unordered_set>
#include "Component.h"
#include "Transform.h"
#include "Game.h"

class GameObject {

public:
    virtual void Update(float deltaTime) = 0;

    virtual void Draw(SDL_Renderer *renderer) = 0;

    virtual void ProcessInput(const Uint8 *state) = 0;

    class Game* GetGame();

    Transform transform;
protected:
    class Game* game;
};

