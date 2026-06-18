#include "../include/World.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

// NOTE: This a temporary struct to check collision
struct Rect {
    float x, y;     // Coords of bottom left corner
    float w, h;     // Size of the rectangle
};

World::World()
    : m_bg{ Constants::g_bgTexturePath }
    , m_flr{ Constants::g_flrTexturePath }
    // Place the bird midway above the ground initially
    , m_bird{ Constants::g_birdTexturePath, Constants::g_globalBounds.yMax / 2 }
    , m_pipeMgr{ Constants::g_pipeTexturePath, 30, m_scrollSpeed }
{
}

bool World::checkBirdPipeCollision() const
{
    // Fraction of the bird's size to inset the hitbox to reduce false collisions
    constexpr float hitboxInsetFactor = 0.225f;
    const float hitboxInset = m_bird.getSize() * hitboxInsetFactor;

    const auto doesIntersect = [](const Rect& a, const Rect& b) -> bool
    {
        if (a.w <= 0 || a.h <= 0 || b.w <= 0 || b.h <= 0) {
            return false;
        }
        return (a.x < b.x + b.w) && (a.x + a.w > b.x) && (a.y < b.y + b.h) && (a.y + a.h > b.y);
    };

    const Rect birdBox{
        0.0f - m_bird.getSize() * 0.5f,
        m_bird.getPosY() - m_bird.getSize() * 0.5f,
        m_bird.getSize() - hitboxInset,
        m_bird.getSize() - hitboxInset
    };

    for (const auto& pair : m_pipeMgr.getPipes()) {
        const Rect bottomPipeBox{
            pair.getBottom().getPosX() - pair.getBottom().getWidth() * 0.5f,
            0.0f,
            pair.getBottom().getWidth(),
            pair.getBottom().getLength()
        };

        if (doesIntersect(birdBox, bottomPipeBox)) {
            return true;
        }

        const Rect topPipeBox{
            pair.getTop().getPosX() - pair.getTop().getWidth() * 0.5f,
            Constants::g_globalBounds.yMax - pair.getTop().getLength(),
            pair.getTop().getWidth(),
            pair.getTop().getLength()
        };

        if (doesIntersect(birdBox, topPipeBox)) {
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
