#include "../include/Pipe.h"
#include "../include/Constants.h"
#include "../include/Utils.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Pipe::Pipe(const sf::Texture& tex,
           const Location loc,
           const float length,
           const float width,
           const float posX)
    : m_spr{ tex }
    , m_loc{ loc }
    , m_length{ length }
    , m_width{ width }
    , m_posX{ posX }
{
    const sf::Vector2u windowSize{ Constants::g_windowWidth, Constants::g_windowHeight };
    const sf::Vector2f globalBoundsSize{ Constants::g_globalBounds.getSize() };
    const sf::Vector2u originalSize{ m_spr.getTextureRect().size };

    const sf::Vector2f worldSize{ m_width, m_length };

    const sf::Vector2f drawSize{
        worldToScnSize(worldSize, globalBoundsSize, windowSize)
    };

    m_spr.setOrigin({ originalSize.x / 2.0f, static_cast<float>(originalSize.y) });
    m_spr.setScale(computeSpriteScale(originalSize, drawSize));

    const sf::Angle rotation = sf::degrees(m_loc == BOTTOM ? 0.0f : 180.0f);
    m_spr.setRotation(rotation);
}

void Pipe::drawTo(sf::RenderWindow& window)
{
    const float posY = m_loc == BOTTOM ? 0.0f : Constants::g_globalBounds.yMax();
    m_spr.setPosition(worldToScnCoords({ m_posX, posY }, Constants::g_globalBounds, window.getSize()));
    window.draw(m_spr);
}
