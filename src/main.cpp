#include "../include/Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    Game game{ Game::State::Playing };

    sf::Clock clk;
    while (game.isRunning()) {
        game.processEvents();
        game.update(clk.restart().asSeconds());
        game.render();
    }

    return 0;
}
