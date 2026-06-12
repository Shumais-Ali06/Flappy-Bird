#include "../include/World.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

World::World()
    : m_bg{ Constants::g_bgTexturePath }
    , m_flr{ Constants::g_flrTexturePath }
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

void World::drawTo(sf::RenderWindow& window)
{
    m_bg.drawTo(window);
    m_flr.drawTo(window);
    m_bird.drawTo(window);
}
