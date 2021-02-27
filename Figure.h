//
// Created by Aleksandr on 22.02.2021.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include "GameObject.h"
#include "Transform.h"

enum class Type {
    TYPE_I,
    TYPE_J,
    TYPE_L,
    TYPE_O,
    TYPE_S,
    TYPE_T,
    TYPE_Z
};

class Figure : public GameObject {
public:
    Figure();

    Figure(Type type, Vector2 *pos, Game* game);

    void Draw(SDL_Renderer *renderer) override;

    void Update(float deltaTime) override;

    void ProcessInput(const Uint8 *state) override;

private:
    Type type;
    float speed;
    int dx;
    bool isRotating;
};


#endif //TETRIS_FIGURE_H
