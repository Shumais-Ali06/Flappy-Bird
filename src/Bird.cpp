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
    /* NOTE: These values are hardcoded for the time being and the window aspect
     * ratio should be taken into consideration as such */
    const float scaleX = 2.5f;
    const float scaleY = 2.5f;

    m_spr.setScale({scaleX, scaleY});
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
    m_spr.setPosition(worldToScnCoords({0.0f, m_posY}, window.getSize(), Constants::g_globalBounds));

    window.draw(m_spr);
}

void Bird::jump()
{
    m_velY = std::min(m_maxSpeed, std::max(0.0f, m_velY) + m_jumpImpulse);
}
