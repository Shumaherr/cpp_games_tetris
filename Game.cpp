//
// Created by Aleksandr on 14.02.2021.
//

#include <SDL2-2.0.12/include/SDL.h>
#include <memory>
#include "Game.h"
#include "Transform.h"
#include "Draw.h"
#include "Figure.h"

void Game::Init() {
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
    SDL_Rect *background = new SDL_Rect({50, 50, (int) (windowWidth * 0.6), (int) (windowHeight * 0.9)});
    std::vector<SDL_Rect *> rects;
    rects.push_back(background);
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawRects(renderer, rects[0], rects.size());
    SDL_RenderFillRects(renderer, rects[0], rects.size());
    gameObjects.emplace_back(new Figure(Type::TYPE_S, new Vector2(50, 150), this));
    mTicksCount = SDL_GetTicks();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    if (!gameObjects.empty()) {
        std::vector<GameObject *>().swap(gameObjects);
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
        gameObject->Update(deltaTime);
    }
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (auto gameObject : gameObjects) {
        gameObject->Draw(renderer);
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
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        gameState = STATE_EXIT;
    }
    for (auto gameObject : gameObjects) {
        gameObject->ProcessInput(state);
    }
}

int Game::GetWindowHeight() {
    return windowHeight;
}

int Game::GetWindowWidth() {
    return windowWidth;
}


