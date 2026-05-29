#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <optional>

constexpr int WINDOW_WIDTH  = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr int TARGET_FPS    = 60;

int main(int argc, char* argv[])
{
    sf::RenderWindow window{sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), 
                            "Flappy Bird", sf::Style::Titlebar | sf::Style::Close};
    window.setFramerateLimit(TARGET_FPS);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            window.clear(sf::Color::Cyan);
            window.display();
        }
    }

    return 0;
}
