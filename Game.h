//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <SDL_render.h>
#include <string>
#include <vector>
#include "GameObject.h"

enum GameState {
    STATE_INIT,
    STATE_PLAY,
    STATE_PAUSE,
    STATE_WIN,
    STATE_GAME_OVER,
    STATE_EXIT
};

class Game {
public:
    Game() : windowHeight(800), windowWidth(600), title("Tetris") {};

    Game(int windowHeight, int windowWidth, const char *title) : windowHeight(windowHeight), windowWidth(windowWidth),
                                                                title(title) {};
    ~Game();
    void Init();

    void Update();

    void Render();
    void ProcessInput();
    bool isRunning();

private:
    const char *title;
    int windowHeight, windowWidth;
    SDL_Renderer *renderer;
    SDL_Window *window;
    long score;
    GameState gameState;
    std::vector<GameObject*> gameObjects;
    Uint32 mTicksCount;
};
