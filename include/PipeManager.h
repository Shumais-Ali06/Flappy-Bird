#pragma once

#include "PipePair.h"

#include "SFML/Graphics.hpp"

#include <deque>

class PipeManager {
private:
    sf::Texture             m_tex;
    std::deque<PipePair>    m_pipes;
    const float             m_interspacing;
    const int               m_scrollSpeed;

public:
    PipeManager(const char* pathToTexture, const float interspacing, const int scrollSpeed);

    const std::deque<PipePair>& getPipes() const { return m_pipes; }

    void drawPipes(sf::RenderWindow& window);
    void update(const float dt);
};
