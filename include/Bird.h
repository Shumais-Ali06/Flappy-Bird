#pragma once

#include "Sprite.h"
#include <SFML/Graphics.hpp>

// Modelled as a square shaped entity for simplicity
class Bird {
private:
    sf::Texture m_tex;
    Sprite      m_spr;
    float       m_posY;
    float       m_velY  = 0.0f;
    bool        m_alive = true;
    const float m_size          = 7.0f;
    const float m_jumpImpulse   = 30.0f;
    const float m_maxSpeed      = 30.0f;

public:
    Bird(const char* pathToTexture, const float initY);

    bool isAlive() const { return m_alive; }
    const sf::Texture& getTexture() const { return m_tex; }

    void jump();
    void update(const float gravity, const float dt);
    void drawTo(sf::RenderWindow& window);
};
