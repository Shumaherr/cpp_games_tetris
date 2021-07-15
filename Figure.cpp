//
// Created by Aleksandr on 22.02.2021.
//

#include "Figure.h"
#include "Draw.h"

void Figure::Draw(SDL_Renderer *renderer) {
    switch (type) {
        case Type::TYPE_I:
            SDL_SetRenderDrawColor(renderer, 0, 240, 240, 255);
            break;
        case Type::TYPE_J:
            SDL_SetRenderDrawColor(renderer, 0, 0, 240, 255);
            break;
        case Type::TYPE_L:
            SDL_SetRenderDrawColor(renderer, 240, 160, 0, 255);
            break;
        case Type::TYPE_O:
            SDL_SetRenderDrawColor(renderer, 235, 235, 0, 255);
            break;
        case Type::TYPE_T:
            SDL_SetRenderDrawColor(renderer, 160, 0, 240, 255);
            break;
        case Type::TYPE_Z:
            SDL_SetRenderDrawColor(renderer, 216, 0, 0, 255);
            break;
        case Type::TYPE_S:
            SDL_SetRenderDrawColor(renderer, 0, 235, 0, 255);
            break;

    }
    for(auto block : blocks)
    {
        SDL_RenderDrawRectF(renderer, new SDL_FRect(
                {block.x, block.y , (float) game->GetBlockSize(), (float) game->GetBlockSize()}));
    }
}

Figure::Figure(Type type, Vector2 *pos, Game* game) {
    this->type = type;
    this->transform.setPosition(pos);
    this->game = game;
    switch (type) {

        case Type::TYPE_I:
            for (int i = 0; i < 4; i++) {
                blocks.push_back(Vector2(transform.getPosition()->x, transform.getPosition()->y + i * game->GetBlockSize()));
            }
            break;
        case Type::TYPE_J:
            for (int i = 0; i < 3; i++) {
                blocks.push_back(Vector2(transform.getPosition()->x, transform.getPosition()->y + i * game->GetBlockSize()));
            }
            blocks.push_back(Vector2(transform.getPosition()->x - game->GetBlockSize(), transform.getPosition()->y + 2 * game->GetBlockSize()));
            break;
        case Type::TYPE_L:
            for (int i = 0; i < 3; i++) {
                blocks.push_back(Vector2(transform.getPosition()->x, transform.getPosition()->y + i * game->GetBlockSize()));
            }
            blocks.push_back(Vector2(transform.getPosition()->x + game->GetBlockSize(), transform.getPosition()->y + 2 * game->GetBlockSize()));
            break;
        case Type::TYPE_O:
            break;
        case Type::TYPE_S:
            break;
        case Type::TYPE_T:
            break;
        case Type::TYPE_Z:
            break;
    }
    speed = 100.0;
}

void Figure::Update(float deltaTime) {
    Vector2 *newPos = this->transform.getPosition();

    //Check is figure fallen down
    float oldX[4];
    for (int i = 0; i < 4; i++)
    {
        blocks[i].y += speed * deltaTime;
        oldX[i] = blocks[i].x;
        if(dx != 0)
            blocks[i].x += 2 * dx;
    }
    for(auto &block : blocks)
    {

    }
    if(!CheckConstraints())
        for (int i = 0; i < 4; i++)
        {
            blocks[i].x = oldX[i];
        }
    transform.setPosition(newPos);
    dx = 0;
    delete newPos;
}

bool Figure::CheckConstraints()
{
    for(auto &block:blocks)
    {
        if(block.x < game->GetField()->x || block.x >= game->GetField()->x + game->GetField()->w - game->GetBlockSize() + 2)
            return false;
    }
    return true;
}

void Figure::Rotate()
{
    Vector2 p = blocks[1];
    for(int i = 0; i < 4; i++)
    {
        int x = blocks[i].y - p.y;
        int y = blocks[i].x - p.x;
        blocks[i].x = p.x - x;
        blocks[i].y = p.y + y;
    }
}

void Figure::ProcessInput(const Uint8 *state) {
    if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
        dx = 1;
    }
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
        dx = -1;
    }
    if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
        Rotate(); //TODO Optimise. Stop rendering before figure is rotated
    }

}

float Figure::GetLeftX() {
    float min = game->GetWindowWidth();
    for(auto &block : blocks)
    {
        if(block.x < min)
            min = block.x;
    }
    return min;
}

float Figure::GetRightX() {
    float max = 0;
    for(auto &block : blocks)
    {
        if(block.x > max)
            max = block.x;
    }
    return max;
}

float Figure::GetBottomY() {
    float max = 0;
    for(auto &block : blocks)
    {
        if(block.y > max)
            max = block.y;
    }
    return max;
}