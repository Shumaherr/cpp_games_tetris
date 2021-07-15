//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <SDL_render.h>
#include <string>
#include <vector>

enum GameState {
    STATE_INIT,
    STATE_PLAY,
    STATE_PAUSE,
    STATE_WIN,
    STATE_GAME_OVER,
    STATE_EXIT
};
class GameObject;
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

    int GetWindowHeight();
    int GetWindowWidth();
    SDL_Rect* GetField();
    int GetBlockSize();
private:
    const char *title;
    int windowHeight, windowWidth;
    SDL_Rect *fieldRect;
    SDL_Renderer *renderer;
    SDL_Window *window;
    long score;
    GameState gameState;
    std::vector<GameObject*> gameObjects;
    Uint32 mTicksCount;
    int blockSize;
};
