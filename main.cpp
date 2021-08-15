#include <iostream>
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
    return 0;
}
