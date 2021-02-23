//
// Created by Aleksandr on 22.02.2021.
//

#include "Figure.h"
#include "Draw.h"

void Figure::Draw(SDL_Renderer *renderer) {


}

Figure::Figure(Type type) {
    this->type = type;
    switch (type) {
        case Type::TYPE_I:
            AddComponent(new Draw())

    }
    AddComponent(new Draw())
}
