#include "../include/Bird.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

#include <algorithm>

// TODO: Remove the need to pass window size
sf::Vector2f worldToScnCoords(unsigned w, unsigned h, sf::Vector2f pos)
{
    // Derived using the two-point form of a straight line
    const float xScn = float(w) / (Constants::xMax - Constants::xMin) * (pos.x - Constants::xMin);
    const float yScn = float(h) / (Constants::yMin - Constants::xMax) * (pos.y - Constants::yMax);
    return sf::Vector2f{ xScn, yScn };
}

Bird::Bird(const char* pathToTexture, const float initY)
    : m_tex{ pathToTexture }
    , m_spr{ m_tex,  {{0,0}, {16,16} }, 4, 24.0f }
    , m_posY{ initY }
{
    /* NOTE: These values are hardcoded for the time being and the window aspect
     * ratio should be taken into consideration as such */
    const float scaleX = 2.5f;
    const float scaleY = 2.5f;

    // TODO: Make the sprite modification calls more readable
    m_spr.sprite().setScale({scaleX, scaleY});
    m_spr.sprite().setOrigin(m_spr.sprite().getLocalBounds().size / 2.0f);
}

void Bird::update(const float gravity, const float dt)
{
    m_velY += gravity * dt;
    m_posY = std::clamp(m_posY + m_velY * dt, 0.0f, Constants::yMax);
    if (m_posY <= 0.0f) {
        m_alive = false;
    }

    m_spr.playAnimation(dt);
}

void Bird::drawTo(sf::RenderWindow& window)
{
    // TODO: Remove the hardcoded values for the window size
    m_spr.sprite().setPosition(worldToScnCoords(800, 600, { 0.0f, m_posY }));

    window.draw(m_spr.sprite());
}

void Bird::jump()
{
    m_velY = std::min(m_maxSpeed, std::max(0.0f, m_velY) + m_jumpImpulse);
}
