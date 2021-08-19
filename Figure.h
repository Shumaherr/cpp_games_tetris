//
// Created by Aleksandr on 22.02.2021.
//
#pragma once

#include <vector>
#include "GameObject.h"
#include "Transform.h"

enum Type {
    TYPE_I = 0,
    TYPE_J,
    TYPE_L,
    TYPE_O,
    TYPE_S,
    TYPE_T,
    TYPE_Z,
    last
};
class GameObject;
class Game;
class Figure : public GameObject {
public:
    Figure();

    Figure(Type type, Vector2& pos, const Game& game);

    void Draw(SDL_Renderer *renderer) override;

    void Update(float deltaTime) override;

    bool IsActive() { return isActive; };

    void MoveLeft();

    void MoveRight();

    void DropDown();

    void Rotate();
    void StopMoving();
    std::vector<Vector2> &GetBlocks() { return blocks; };

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


    bool CheckIsDown();

    bool CheckFallen();


};
