
#include <iostream>
#include "Game.h"

int main()
{
    Game* game = new Game();

    while (true) {
        game->handleInput();
        game->update();
        game->render();
    }
    
    return 0;
}