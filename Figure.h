//
// Created by Aleksandr on 22.02.2021.
//
#pragma once

#include "GameObject.h"
#include "Transform.h"
#include "Game.h"

enum Type {
    TYPE_I,
    TYPE_J,
    TYPE_L,
    TYPE_O,
    TYPE_S,
    TYPE_T,
    TYPE_Z,
    last
};

class Figure : public GameObject {
public:
    Figure();

    Figure(Type type, Vector2 *pos, Game* game);

    void Draw(SDL_Renderer *renderer) override;

    void Update(float deltaTime) override;

    void ProcessInput(const Uint8 *state) override;

    bool IsActive() {return isActive;};
    std::vector<Vector2> GetBlocks() {return blocks;};
    float GetLeftX();
    float GetRightX();
    float GetBottomY();

private:
    Type type;
    float speed;
    int dx;
    bool isRotating;
    std::vector<Vector2> blocks;
    bool isActive;

    bool CheckConstraints();

    void Rotate();

    bool CheckIsDown();

    void CheckFallen();
};
