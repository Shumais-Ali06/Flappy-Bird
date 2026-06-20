#include "../include/World.h"
#include "../include/Constants.h"
#include "../include/WorldBounds.h"

#include <SFML/Graphics.hpp>

World::World()
    : m_bg{ Constants::g_bgTexturePath }
    , m_flr{ Constants::g_flrTexturePath }
    // Place the bird midway above the ground initially
    , m_bird{ Constants::g_birdTexturePath, Constants::g_globalBounds.yMax() * 0.5f }
    , m_pipeMgr{ Constants::g_pipeTexturePath, 30, m_scrollSpeed }
{
}

bool World::checkBirdPipeCollision() const
{
    // Fraction of the bird's size to inset the hitbox to reduce false collisions
    constexpr float hitboxInsetFactor = 0.23f;
    const float hitboxInset = m_bird.getSize() * hitboxInsetFactor;

    const WorldBounds birdBox{
        { 0.0f - m_bird.getSize() * 0.5f, m_bird.getPosY() - m_bird.getSize() * 0.5f },
        { m_bird.getSize() - hitboxInset, m_bird.getSize() - hitboxInset }
    };

    for (const auto& pair : m_pipeMgr.getPipes()) {
        const float pipeXMin = pair.getBottom().getPosX() - pair.getBottom().getWidth() * 0.5f;
        const float pipeXMax = pair.getBottom().getPosX() + pair.getBottom().getWidth() * 0.5f;

        const WorldBounds bottomPipeBox{
            pipeXMin,
            pipeXMax,
            0.0f,
            pair.getBottom().getLength()
        };

        if (birdBox.doesIntersect(bottomPipeBox)) {
            return true;
        }

        const WorldBounds topPipeBox{
            pipeXMin,
            pipeXMax,
            Constants::g_globalBounds.yMax() - pair.getTop().getLength(),
            Constants::g_globalBounds.yMax()
        };

        if (birdBox.doesIntersect(topPipeBox)) {
            return true;
        }
    }

    return false;
}

void World::update(const float dt)
{
    if (m_bird.isAlive()) {
        if (checkBirdPipeCollision()) {
            m_bird.kill();
            return;
        }

        m_pipeMgr.update(dt);
        m_bird.update(m_gravity, dt);
    }
}

void World::drawTo(sf::RenderWindow& window)
{
    m_bg.drawTo(window);
    m_flr.drawTo(window);
    m_pipeMgr.drawPipes(window);
    m_bird.drawTo(window);
}
