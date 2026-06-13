#pragma once

#include "Background.h"
#include "Bird.h"
#include "Floor.h"

#include <SFML/Graphics.hpp>

class World {
private:
    const int           m_gravity     = -50;
    const int           m_scrollSpeed = 100;

    Background          m_bg;
    Floor               m_flr;
    Bird                m_bird;

public:
    World();

    void update(const float dt);
    void drawTo(sf::RenderWindow& window);
    Bird& getBird() { return m_bird; }
};
