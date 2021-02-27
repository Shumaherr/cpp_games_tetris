//
// Created by Aleksandr on 22.02.2021.
//

#include "Figure.h"
#include "Draw.h"

void Figure::Draw(SDL_Renderer *renderer) {
    switch (type) {
        case Type::TYPE_I:
            SDL_SetRenderDrawColor(renderer, 0, 240, 240, 255);
            for (int i = 0; i < 4; i++) {
                SDL_RenderDrawRectF(renderer, new SDL_FRect(
                        {transform.getPosition()->x, transform.getPosition()->y + i * 10, 10, 10}));
            }
            break;
        case Type::TYPE_J:
            SDL_SetRenderDrawColor(renderer, 0, 0, 240, 255);
            for (int i = 0; i < 3; i++) {
                SDL_RenderDrawRectF(renderer, new SDL_FRect(
                        {transform.getPosition()->x, transform.getPosition()->y + i * 10, 10, 10}));
            }
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x - 10, transform.getPosition()->y + 2 * 10, 10, 10}));
            break;
        case Type::TYPE_L:
            SDL_SetRenderDrawColor(renderer, 240, 160, 0, 255);
            for (int i = 0; i < 3; i++) {
                SDL_RenderDrawRectF(renderer, new SDL_FRect(
                        {transform.getPosition()->x, transform.getPosition()->y + i * 10, 10, 10}));
            }
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y + 2 * 10, 10, 10}));
            break;
        case Type::TYPE_O:
            SDL_SetRenderDrawColor(renderer, 235, 235, 0, 255);
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x, transform.getPosition()->y, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y + 10, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x, transform.getPosition()->y + 10, 10, 10}));
            break;
        case Type::TYPE_T:
            SDL_SetRenderDrawColor(renderer, 160, 0, 240, 255);
            for (int i = 0; i < 3; i++) {
                SDL_RenderDrawRectF(renderer, new SDL_FRect(
                        {transform.getPosition()->x + i * 10, transform.getPosition()->y, 10, 10}));
            }
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y + 10, 10, 10}));
            break;
        case Type::TYPE_Z:
            SDL_SetRenderDrawColor(renderer, 216, 0, 0, 255);
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x, transform.getPosition()->y, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y + 10, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 20, transform.getPosition()->y + 10, 10, 10}));
            break;
        case Type::TYPE_S:
            SDL_SetRenderDrawColor(renderer, 0, 235, 0, 255);
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x, transform.getPosition()->y + 10, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y + 10, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 10, transform.getPosition()->y, 10, 10}));
            SDL_RenderDrawRectF(renderer, new SDL_FRect(
                    {transform.getPosition()->x + 20, transform.getPosition()->y, 10, 10}));
            break;

    }
}

Figure::Figure(Type type, Vector2 *pos, Game* game) {
    this->type = type;
    this->transform.setPosition(pos);
    this->game = game;
    speed = 100.0;
}

void Figure::Update(float deltaTime) {
    Vector2 *newPos = this->transform.getPosition();
    //Check is figure fallen down
    newPos->y += speed * deltaTime;
    if (dx != 0)
        newPos->x += dx;
    if(newPos->x < 50)
        newPos->x = 50;
    if(newPos->x > game->GetWindowWidth() + 50)
        newPos->x = game->GetWindowWidth() + 50;
    transform.setPosition(newPos);
    dx = 0;
    delete newPos;
}

void Figure::ProcessInput(const Uint8 *state) {
    if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
        dx = 1;
    }
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
        dx = -1;
    }

}
