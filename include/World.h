#pragma once

#include "Bird.h"

#include <SFML/Graphics.hpp>

class World {
public:
    const int gravity     = -10;
    const int scrollSpeed =  100;

private:
    Bird m_bird;

    void drawBackground(sf::RenderWindow& window) const;

public:
    World();

    void update(const float dt);
    void drawTo(sf::RenderWindow& window) const;
};
