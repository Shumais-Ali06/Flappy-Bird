#pragma once

#include "Constants.h"
#include "Pipe.h"
#include <SFML/Graphics.hpp>

/* Class to manage a top-bottom pipe pair with a configurable vertical gap,
 * handles positioning, movement, and rendering */
// NOTE: Both pipes always have the same x position
class PipePair {
private:
    const float         m_gapLength;        // space between the two pipes (in game units)
    const float         m_gapHeight;        // distance between the ground and the centre of the gap
    const float         m_width;
    Pipe                m_top;
    Pipe                m_bottom;

public:
    PipePair(const sf::Texture& tex,
             const float gapLength,
             const float gapHeight,
             const float width,
             const float posX);

    float getPosX() const { return m_top.getPosX(); }

    void move(const float offsetX);
    void drawTo(sf::RenderWindow& window);

    const Pipe& getTop() const { return m_top; }
    const Pipe& getBottom() const { return m_bottom; }
};
