#include "../include/Game.hpp"
#define FPS 60

int main(int argc, char **argv) {
// Program entry point.
    Game game; // Creating our game object.
    while (!game.GetWindow()->IsDone()) {
// Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
        sf::sleep(sf::seconds(1.0/FPS));
    }

    return 0;
}