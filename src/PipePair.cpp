#include "../include/PipePair.h"
#include "../include/Constants.h"
#include "../include/Utils.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

PipePair::PipePair(const sf::Texture& tex,
                   const float gapLength,
                   const float gapHeight,
                   const float width,
                   const float posX)
    : m_top{ tex }
    , m_bottom{ tex }
    , m_gapLength{ gapLength }
    , m_gapHeight{ gapHeight }
    , m_width{ width }
    , m_posX{ posX }
{
    // NOTE: The origin of each bottom pipe is at the centre bottom and for top pipe at the centre top

    const sf::Vector2u originalSize = m_bottom.getTexture().getSize();

    // TODO: Replace the hardcoded window size values
    const sf::Vector2u windowSize   = { 800, 600 };

    // Bottom pipe
    const sf::Vector2f bottomWorldSize{
        m_width,
        m_gapHeight - m_gapLength / 2.0f
    };

    const sf::Vector2f bottomDrawSize{
        worldToScnSize(bottomWorldSize, Constants::g_globalBounds.getSize(), windowSize)
    };

    m_bottom.setOrigin({ originalSize.x / 2.0f, static_cast<float>(originalSize.y) });
    m_bottom.setScale(computeSpriteScale(originalSize, bottomDrawSize));

    // Top pipe
    const sf::Vector2f topWorldSize{
        m_width,
        Constants::g_globalBounds.yMax - (m_gapHeight + m_gapLength / 2.0f)
    };

    const sf::Vector2f topDrawSize{
        worldToScnSize(topWorldSize, Constants::g_globalBounds.getSize(), windowSize)
    };

    m_top.setOrigin({ originalSize.x / 2.0f, static_cast<float>(originalSize.y) });
    m_top.setRotation(sf::degrees(180.0f));
    m_top.setScale(computeSpriteScale(originalSize, topDrawSize));
}

void PipePair::drawTo(sf::RenderWindow& window)
{
    m_top.setPosition(worldToScnCoords({ m_posX, Constants::g_globalBounds.yMax }, Constants::g_globalBounds, window.getSize()));
    window.draw(m_top);

    m_bottom.setPosition(worldToScnCoords({ m_posX, 0.0f }, Constants::g_globalBounds, window.getSize()));
    window.draw(m_bottom);
}
