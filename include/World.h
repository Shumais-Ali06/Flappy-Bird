#pragma once

#include "Bird.h"
#include "Config.h"

#include <SFML/Graphics.hpp>

class World {
public:
    /* Anything within this given range will be rendered.
     * Note that the bird may exceed yMax. */
    static constexpr float yMax =  800.0f;
    static constexpr float yMin = -200.0f;
    static constexpr float xMax = -200.0f;
    static constexpr float xMin =  800.0f;

    static constexpr const char* pathToBirdTexture = "assets/bird.png";

private:
    int  m_scrollSpeed;
    Bird m_bird;

    void drawBackground(sf::RenderWindow& window) const;

public:
    World(const int scrollSpeed);

    void update(const float dt);
    void drawTo(sf::RenderWindow& window) const;
};
