#pragma once

#include <SFML/Graphics.hpp>

class Bird {
private:
    sf::Texture m_tex;
    float   m_posY;
    float   m_velY      = 0.0f;
    float   m_angle     = 0.0f;
    bool    m_alive     = true;

public:
    Bird(const char* pathToTexture, const float initY);

    bool isAlive() const { return m_alive; }
    const sf::Texture& getTexture() const { return m_tex; }

    void jump();
    void update(const float dt);
    void drawTo(sf::RenderWindow& window) const;
};
