#include "../include/World.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

World::World()
    : m_skyTex{ Constants::g_skyTexturePath }
    , m_groundTex{ Constants::g_flrTexturePath, false, { {0, 80}, {64, 32} }}
    // Place the bird midway above the ground initially
    , m_bird{ Constants::g_birdTexturePath, Constants::yMax / 2 }
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
    const float flrHeight    = window.getSize().y - skyHeight;

    sf::RectangleShape sky{ { bgWidth, skyHeight } };
    sky.setTexture(&m_skyTex);
    window.draw(sky);

    // BUG: Texture appears stretched and distorted instead of being scaled to fit and repeated
    // Might require switching from sf::Shape to sf::Texture later on
    sf::RectangleShape flr{ { bgWidth, flrHeight } };
    flr.setPosition({0.0f, skyHeight});
    flr.setTexture(&m_groundTex);
    window.draw(flr);
}

void World::drawTo(sf::RenderWindow& window)
{
    drawBackground(window);
    m_bird.drawTo(window);
}
