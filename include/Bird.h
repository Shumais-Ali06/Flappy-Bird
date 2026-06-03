#pragma once

#include "Config.h"
#include <SFML/Graphics.hpp>

class Bird {
private:
    sf::Texture m_tex;
    float   m_posY;
    float   m_velY;
    float   m_angle;
    bool    m_alive;

public:
    Bird(const char* pathToTexture, const float initY);

    bool isAlive() const { return m_alive; }
    const sf::Texture& getTexture() const { return m_tex; }

    void jump();
    void update(const float dt);
    void drawTo(sf::RenderWindow& window) const;
};
