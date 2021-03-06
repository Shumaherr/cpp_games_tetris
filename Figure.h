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
    Figure(Type type, Vector2 );
    void Draw(SDL_Renderer* renderer);
private:
    Type type;
};


#endif //TETRIS_FIGURE_H
