//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include "Component.h"

struct Vector2
{
    int x, y;
public:
    Vector2() :x(0), y(0) {};
    Vector2(int x, int y) :x(x), y(y) {};
};
class Transform: Component {
public:
    Transform();
    Transform(int x, int y, float rotation, float scale);
    void setPosition(Vector2* newPos);
    Vector2* getPosition();
    void setRotation(float newRotation);
    float getRotation();
    void setScale(float newScale);
    float getScale();
private:
    Vector2 position;
    float rotation; //rotation in radians
    float scale; //Scale of the object, 1.0 is 100%
};

