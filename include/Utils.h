#pragma once

#include "WorldBounds.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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

/* Converts an entity size from world coordinates to screen coordinates by
 * scaling each axis by the ratio of window size to the global bounds size. */
inline sf::Vector2f worldToScnSize(const sf::Vector2f& entityWorldSize,
                                   const sf::Vector2f& globalBoundsSize,
                                   const sf::Vector2f& windowSize)
{
    return sf::Vector2f{
        entityWorldSize.x * (windowSize.x / globalBoundsSize.x),
        entityWorldSize.y * (windowSize.y / globalBoundsSize.y),
    };
}

// Returns the X/Y scale factors needed to resize a sprite from originalSize to finalSize
inline sf::Vector2f computeSpriteScale(const sf::Vector2u& originalSize,
                                       const sf::Vector2f& finalSize)
{
    return sf::Vector2f{
        finalSize.x / originalSize.x,
        finalSize.y / originalSize.y
    };
}
