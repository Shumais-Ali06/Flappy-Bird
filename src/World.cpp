#include "../include/World.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

World::World()
    : m_groundTex{ Constants::g_flrTexturePath, false, { {0, 80}, {64, 32} }}
    , m_bg{ Constants::g_bgTexturePath }
    // Place the bird midway above the ground initially
    , m_bird{ Constants::g_birdTexturePath, Constants::g_globalBounds.yMax / 2 }
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
    // NOTE: Sky consists of the region above y = 0 and floor lies below
    const float bgWidth      = window.getSize().x;
    const float skyHeight    = window.getSize().y * Constants::g_globalBounds.yMax / Constants::g_globalBounds.height();
    const float flrHeight    = window.getSize().y - skyHeight;

    // TODO: Give floor its own class
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
    m_bg.drawTo(window);
    m_bird.drawTo(window);
}
