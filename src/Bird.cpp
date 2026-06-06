#include "../include/Bird.h"

#include <SFML/Graphics.hpp>

Bird::Bird(const char* pathToTexture, const float initY)
    : m_tex{ pathToTexture }
    , m_spr{ m_tex,  {{0,0}, {16,16} }, 4, 24.0f }
    , m_posY{ initY }
{
    /* NOTE: These values are hardcoded for the time being and the window aspect
     * ratio should be taken into consideration as such */
    const float scaleX = 2.5f;
    const float scaleY = 2.5f;
    m_spr.sprite().setScale({scaleX, scaleY});
}

void Bird::update(const float dt)
{
    m_spr.playAnimation(dt);
}

void Bird::drawTo(sf::RenderWindow& window)
{
    window.draw(m_spr.sprite());
}
