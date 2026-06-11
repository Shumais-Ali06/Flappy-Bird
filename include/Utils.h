#pragma once

#include "WorldBounds.h"
#include <SFML/System.hpp>

inline sf::Vector2f worldToScnCoords(const sf::Vector2f& pos,
                                     const sf::Vector2u& windowSize,
                                     const WorldBounds& bounds)
{
    const float w = static_cast<float>(windowSize.x);
    const float h = static_cast<float>(windowSize.y);

    // Derived using the two-point form of a straight line
    const float xScn = w / (bounds.xMax - bounds.xMin) * (pos.x - bounds.xMin);
    const float yScn = h / (bounds.yMin - bounds.yMax) * (pos.y - bounds.yMax);

    return sf::Vector2f{ xScn, yScn };
}
