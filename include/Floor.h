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
        // TODO: Replace hardcoded window size values
        const sf::Vector2f drawSize{ worldToScnSize(m_bounds.getSize(), Constants::g_globalBounds.getSize(), { 800.0f, 600.0f }) };

        m_spr.setScale(computeSpriteScale(m_tex.getSize(), drawSize));
        m_spr.setPosition(worldToScnCoords({ m_bounds.xMin, m_bounds.yMax}, { 800, 600 }, Constants::g_globalBounds));
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(m_spr);
    }
};

