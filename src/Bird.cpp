#include "../include/Bird.h"
#include "../include/Constants.h"
#include "../include/Utils.h"

#include <SFML/Graphics.hpp>

#include <algorithm>

Bird::Bird(const char* pathToTexture, const float initY)
    : m_tex{ pathToTexture }
    , m_spr{ m_tex,  {{0,0}, {16,16} }, 4, 24.0f }
    , m_posY{ initY }
{
    const sf::Vector2u originalSize{ m_spr.getTextureRect().size };
    const sf::Vector2u windowSize{ Constants::g_windowWidth, Constants::g_windowHeight };
    const sf::Vector2f globalBoundsSize{ Constants::g_globalBounds.getSize() };

    const sf::Vector2f drawSize{
        worldToScnSize({ m_size, m_size }, globalBoundsSize, windowSize)
    } ;

    m_spr.setScale(computeSpriteScale(originalSize, drawSize));
    m_spr.setOrigin(m_spr.getLocalBounds().size / 2.0f);
}

void Bird::update(const float gravity, const float dt)
{
    m_velY += gravity * dt;
    m_posY = std::clamp(m_posY + m_velY * dt, 0.0f, Constants::g_globalBounds.yMax);
    if (m_posY <= 0.0f) {
        m_alive = false;
    }

    m_spr.playAnimation(dt);
}

void Bird::drawTo(sf::RenderWindow& window)
{
    m_spr.setPosition(worldToScnCoords({0.0f, m_posY}, Constants::g_globalBounds, window.getSize()));

    window.draw(m_spr);
}

void Bird::jump()
{
    m_velY = std::min(m_maxSpeed, std::max(0.0f, m_velY) + m_jumpImpulse);
}
