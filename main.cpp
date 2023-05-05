
#include "Game.h"

int main()
{
    Game* game = new Game();

    while (true) {
        game->handleInput();
        game->update();
        game->render();
    }

    delete game;
    return 0;
}