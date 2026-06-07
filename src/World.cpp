#include "../include/World.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

World::World()
    // Place the bird midway above the ground initially
    : m_bird{ Constants::g_birdTexturePath, Constants::yMax / 2 }
{
}

void World::update(const float dt)
{
    if (m_bird.isAlive()) {
        m_bird.update(m_gravity, dt);
    }
}

void World::drawBackground(sf::RenderWindow& window) const
{
    const float bgWidth      = window.getSize().x;
    const float skyHeight    = window.getSize().y * float(Constants::yMax) / (Constants::yMax - Constants::yMin);
    const float groundHeight = window.getSize().y - skyHeight;

    sf::RectangleShape sky{{ bgWidth, skyHeight }};
    sky.setFillColor(sf::Color::Blue);
    window.draw(sky);

    sf::RectangleShape ground{{bgWidth, groundHeight}};
    ground.setPosition({0.0f, skyHeight});
    ground.setFillColor(sf::Color::Green);
    window.draw(ground);
}

void World::drawTo(sf::RenderWindow& window)
{
    drawBackground(window);
    m_bird.drawTo(window);
}
