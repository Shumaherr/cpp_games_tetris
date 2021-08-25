//
// Created by Aleksandr on 14.02.2021.
//

#include <SDL.h>
#include <memory>
#include <iostream>
#include <random>
#include "Game.h"
#include "Transform.h"
#include "Draw.h"
#include "Figure.h"

#define BLOCK_SIZE 20

void Game::Init() {
    blockSize = BLOCK_SIZE;
    gameState = STATE_INIT;
    window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            windowWidth,
            windowHeight,
            SDL_WINDOW_OPENGL
    );
    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    DropNewFigure();
    fieldRect = new SDL_Rect({50, 50, (int) (windowWidth * 0.6), (int) (windowHeight * 0.9)});
    mTicksCount = SDL_GetTicks();
}

Game::~Game() {
    delete (fieldRect);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete (fallingFigure);
    if (!gameObjects.empty()) {
        std::vector<Figure>().swap(gameObjects);
    }
}

bool Game::isRunning() {
    return gameState != STATE_EXIT ? true : false;
}

void Game::Update() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }
    mTicksCount = SDL_GetTicks();
    for (auto gameObject : gameObjects) {
        gameObject.Update(deltaTime);
    }
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    std::vector<SDL_Rect *> rects;
    rects.push_back(fieldRect);
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawRects(renderer, rects[0], rects.size());
    SDL_RenderFillRects(renderer, rects[0], rects.size());
    for (auto gameObject : gameObjects) {
        gameObject.Draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                gameState = STATE_EXIT;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        fallingFigure->MoveLeft();
                        break;
                    case SDLK_RIGHT:
                        fallingFigure->MoveRight();
                        break;
                    case SDLK_UP:
                        fallingFigure->Rotate();
                        break;
                    case SDLK_DOWN:
                        fallingFigure->DropDown();
                        break;
                    default:
                        break;
                }
                break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        gameState = STATE_EXIT;
    }
}

void Game::DropNewFigure() {
    auto it = gameObjects.emplace_back(Figure(Figure::randFigure(), *new Vector2(150, 50), this));
    fallingFigure = &it;
    //gameObjects.emplace_back(new Figure(Type::TYPE_Z, new Vector2(150, 50), this));
}

int Game::GetWindowHeight() {
    return windowHeight;
}

int Game::GetWindowWidth() {
    return windowWidth;
}

int Game::GetBlockSize() const {
    return blockSize;
}

SDL_Rect& Game::GetFieldRect() {
    return *fieldRect;
}

bool Game::CheckFiguresCollison(Figure& figure) const {
    if (blocks.empty())
        return false;
    for (const auto &figBlock:figure.GetBlocks()) {
        for (const auto &block:blocks) {
            if (block.x != figBlock.x)
                continue;
            if (figBlock.y + blockSize >= block.y)
                return true;
        }
    }
    return false;

}

void Game::PutFigure(Figure& figure) {
    figures.push_back(figure);
    for (auto &block: figure.GetBlocks()) {
        blocks.push_back(block);
    }
}



