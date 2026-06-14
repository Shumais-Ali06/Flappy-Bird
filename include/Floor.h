#pragma once

#include "Constants.h"
#include "Utils.h"
#include "WorldBounds.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Floor {
private:
    const sf::Texture       m_tex;
    sf::Sprite              m_spr;
    const WorldBounds       m_bounds;

public:
    Floor(const char* pathToTexture)
    : m_tex{  pathToTexture, false, { {0, 80}, {64, 32} } }
    , m_spr{ m_tex }
    , m_bounds{ Constants::g_globalBounds.xMin, Constants::g_globalBounds.xMax,
                Constants::g_globalBounds.yMin, 0.0f }
    {
        const sf::Vector2u windowSize{ Constants::g_windowWidth, Constants::g_windowHeight };

        const sf::Vector2f drawSize{ worldToScnSize(m_bounds.getSize(), Constants::g_globalBounds.getSize(), windowSize) };

        m_spr.setScale(computeSpriteScale(m_tex.getSize(), drawSize));
        m_spr.setPosition(worldToScnCoords({ m_bounds.xMin, m_bounds.yMax }, Constants::g_globalBounds, windowSize));
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(m_spr);
    }
};

