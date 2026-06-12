#pragma once

#include "Constants.h"
#include "Utils.h"
#include "WorldBounds.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Background {
private:
    const sf::Texture       m_tex;
    sf::Sprite              m_spr;
    const WorldBounds       m_bounds;

public:
    Background(const char* pathToTexture)
    : m_tex{ pathToTexture }
    , m_spr{ m_tex }
    , m_bounds{ Constants::g_globalBounds.xMin, Constants::g_globalBounds.xMax,
                0.0f                          , Constants::g_globalBounds.yMax }
    {
        // TODO: Replace hardcoded window size values
        const sf::Vector2f drawSize{ worldToScnSize(m_bounds.getSize(), Constants::g_globalBounds.getSize(), { 800, 600 }) };

        m_spr.setScale(computeSpriteScale(m_tex.getSize(), drawSize));
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(m_spr);
    }
};
