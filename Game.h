//
// Created by Aleksandr on 14.02.2021.
//
#pragma once

#include <SDL_render.h>
#include <string>
#include <vector>
#include <map>
#include "Transform.h"
#include "Figure.h"

enum GameState {
    STATE_INIT,
    STATE_PLAY,
    STATE_PAUSE,
    STATE_WIN,
    STATE_GAME_OVER,
    STATE_EXIT
};
class GameObject;
class Figure;
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
    SDL_Rect* GetFieldRect();
    int GetBlockSize();
    void DropNewFigure();
    void PutFigure(Figure* figure);
    bool CheckFiguresCollison(Figure* figure);
private:
    const char *title;
    int windowHeight, windowWidth;
    SDL_Rect *fieldRect;
    SDL_Renderer *renderer;
    SDL_Window *window;
    long score;
    GameState gameState;
    std::vector<Figure*> gameObjects;
    std::vector<Figure*> figures;
    std::vector<Vector2*> blocks;
    Uint32 mTicksCount;
    int blockSize;
    Figure* fallingFigure;

};
