#include <iostream>
#include <SDL2-2.0.12/include/SDL_video.h>
#include <SDL2-2.0.12/include/SDL_render.h>
#include "Game.h"

Game *game;

int main() {
    game = new Game();
    game->Init();
    while (game->isRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }
    if (game)
        delete game;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
