//
// Created by Aleksandr on 14.02.2021.
//

#include <SDL2-2.0.12/include/SDL.h>
#include "Game.h"
#include "Transform.h"
#include "Draw.h"

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
    GameObject *field = new GameObject();
    field->AddComponent(new Transform(50,50, 300, 100, 1,1));
    SDL_Rect *background = new SDL_Rect({50, 50, 300, 100});
    std::vector<SDL_Rect*> rects;
    rects.push_back(background);
    field->AddComponent(new Draw(new SDL_Color({24,24,24,255}), rects ));
    gameObjects.push_back(*field);
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::isRunning() {
    return gameState != STATE_EXIT ? true : false;
}

void Game::Update() {

}

void Game::Render() {
    for(auto gameObject : gameObjects)
    {
        for(auto component : gameObject.GetComponents())
        {
            component->DrawObject(renderer);
        }
    }
    SDL_RenderPresent(renderer);
}

void Game::ProcessInput() {

}


