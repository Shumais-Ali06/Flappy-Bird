#pragma once

#include "Constants.h"
#include <SFML/Graphics.hpp>

class PipePair {
private:
    sf::Sprite          m_top;
    sf::Sprite          m_bottom;

    const float         m_gapLength;        // space between the two pipes (in game units)
    const float         m_gapHeight;        // distance between the ground and the centre of the gap
    const float         m_width;
    float               m_posX;

public:
    PipePair(const sf::Texture& tex,
             const float gapLength,
             const float gapHeight,
             const float width,
             const float posX);

    float getPosX() const { return m_posX; }
    void move(const float offsetX) { m_posX += offsetX; }
    void drawTo(sf::RenderWindow& window);
};
