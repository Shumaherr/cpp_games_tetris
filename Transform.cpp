//
// Created by Aleksandr on 14.02.2021.
//

#include "Transform.h"

Transform::Transform() {
    position.x = 0;
    position.y = 0;
    rotation = 0.0;
    scale = 1.0;
}

Transform::Transform(int x, int y, int height, int width, float rotation, float scale) {
    position.x = x;
    position.y = y;
    this->height = height;
    this->width = width;
    rotation = rotation;
    scale = scale;
}

void Transform::setPosition(Vector2 *newPos) {
    position = *newPos;
}

Vector2* Transform::getPosition() {
    return &position;
}

void Transform::setRotation(float newRotation) {
    rotation = newRotation;
}

float Transform::getRotation() {
    return rotation;
}

void Transform::setScale(float newScale) {
    scale = newScale;
}

float Transform::getScale() {
    return scale;
}

void Transform::Update(float deltaTime) {

}
