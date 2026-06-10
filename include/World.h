#pragma once

#include "Bird.h"

#include <SFML/Graphics.hpp>

class World {
private:
    const sf::Texture m_skyTex;
    const sf::Texture m_groundTex;

    const int m_gravity     = -50;
    const int m_scrollSpeed = 100;
    Bird m_bird;

    void drawBackground(sf::RenderWindow& window) const;

public:
    World();

    void update(const float dt);
    void drawTo(sf::RenderWindow& window);
    Bird& getBird() { return m_bird; }
};
