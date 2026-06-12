#pragma once

#include "WorldBounds.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

/* Convert world coordinates to screen pixels for the given window size
 * globalBounds specifies how to map each window corner to a worldPos
 * Maps x linearly from [xMin,xMax] to [0,width] and y from [yMax,yMin] to [0,height]
 * Derived using the two-point form of a straight line */
inline sf::Vector2f worldToScnCoords(const sf::Vector2f& worldPos,
                                     const WorldBounds& globalBounds,
                                     const sf::Vector2u& windowSize)
{
    return sf::Vector2f{
        windowSize.x * (worldPos.x - globalBounds.xMin) / (globalBounds.xMax - globalBounds.xMin),
        windowSize.y * (worldPos.y - globalBounds.yMax) / (globalBounds.yMin - globalBounds.yMax)
    };
}

/* Converts an entity size from world coordinates to screen coordinates by
 * scaling each axis by the ratio of window size to the global bounds size. */
inline sf::Vector2f worldToScnSize(const sf::Vector2f& entityWorldSize,
                                   const sf::Vector2f& globalBoundsSize,
                                   const sf::Vector2u& windowSize)
{
    return sf::Vector2f{
        windowSize.x * entityWorldSize.x / globalBoundsSize.x,
        windowSize.y * entityWorldSize.y / globalBoundsSize.y
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
