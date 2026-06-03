#include "../include/Bird.h"

#include <SFML/Graphics.hpp>

Bird::Bird(const char* pathToTexture, const float initY)
    : m_tex{ pathToTexture }
    , m_posY{ initY }
{
}

void Bird::update(float dt)
{
}

void Bird::drawTo(sf::RenderWindow& window) const
{
    static sf::Sprite spr{ m_tex };

    /* NOTE: These values are hardcoded for the time being and the window aspect
     * should be taken into consideration as such */
    const float scaleX = 0.1f;
    const float scaleY = 0.1f;
    spr.setScale({scaleX, scaleY});

    window.draw(spr);
}
