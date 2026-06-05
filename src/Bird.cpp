#include "../include/Bird.h"

#include <SFML/Graphics.hpp>

Bird::Bird(const char* pathToTexture, const float initY)
    : m_tex{ pathToTexture }
    , m_posY{ initY }
{
}

void Bird::update(const float dt)
{
}

void Bird::drawTo(sf::RenderWindow& window) const
{
    static sf::Sprite spr{ m_tex, {{0, 0}, {16, 16}} };

    /* NOTE: These values are hardcoded for the time being and the window aspect
     * ratio should be taken into consideration as such */
    const float scaleX = 2.5f;
    const float scaleY = 2.5f;
    spr.setScale({scaleX, scaleY});

    window.draw(spr);
}
