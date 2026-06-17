#pragma once

#include <SFML/Graphics.hpp>

// Class to manage a single Pipe entity
// NOTE: The origin of each Pipe is at the centre-bottom of its base
class Pipe {
public:
    enum Location {
        TOP,
        BOTTOM
    };

private:
    sf::Sprite          m_spr;
    const Location      m_loc;
    const float         m_length;
    const float         m_width;
    float               m_posX;

public:
    Pipe(const sf::Texture& tex,
         const Location loc,
         const float length,
         const float width,
         const float posX);

    float getPosX() const { return m_posX; }
    void move(const float offsetX) { m_posX += offsetX; }

    void drawTo(sf::RenderWindow& window);
};
