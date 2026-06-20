#include "../include/PipePair.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

PipePair::PipePair(const sf::Texture& tex,
                   const float gapLength,
                   const float gapHeight,
                   const float width,
                   const float posX)
    : m_gapLength{ gapLength }
    , m_gapHeight{ gapHeight }
    , m_width{ width }
    , m_top{ tex, Pipe::TOP, Constants::g_globalBounds.yMax() - (gapHeight + gapLength / 2.0f), m_width, posX }
    , m_bottom{ tex, Pipe::BOTTOM, gapHeight - gapLength / 2.0f, m_width, posX }
{
}

void PipePair::move(const float offsetX)
{
    m_top.move(offsetX);
    m_bottom.move(offsetX);
}

void PipePair::drawTo(sf::RenderWindow& window)
{
    m_top.drawTo(window);
    m_bottom.drawTo(window);
}
