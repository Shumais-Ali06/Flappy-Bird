#pragma once

#include "Constants.h"
#include "WorldBounds.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

// Computes a centered viewport rectangle inside a window that maintains a given target aspect ratio
inline sf::FloatRect computeViewport(const sf::Vector2u& windowSize, const float targetAspectRatio)
{
    const float winW = static_cast<float>(windowSize.x);
    const float winH = static_cast<float>(windowSize.y);

    if (winW <= 0.0f || winH <= 0.0f || targetAspectRatio <= 0.0f) {
        return sf::FloatRect{};
    }

    const float winAspect = winW / winH;
    float vpW, vpH;

    if (winAspect > targetAspectRatio) {
        // Window is wider -> pillarbox
        vpH = winH;
        vpW = vpH * targetAspectRatio;
    } else {
        // Window is taller or equal -> letterbox
        vpW = winW;
        vpH = vpW / targetAspectRatio;
    }

    // Center the viewport in the window
    const float left = (winW - vpW) * 0.5f;
    const float top  = (winH - vpH) * 0.5f;

    return sf::FloatRect{
        {left, top},
        {vpW, vpH}
    };
}

/* Map a point from world-space coordinates to screen (pixel) coordinates for a
 * given window size within a computed viewport.
 * Derived using the two-point form of a straight line */
inline sf::Vector2f worldToScnCoords(const sf::Vector2f& worldPos,
                                     const WorldBounds& globalBounds,
                                     const sf::Vector2u& windowSize)
{
    const sf::FloatRect viewRect{ computeViewport(windowSize, Constants::g_targetAspectRatio) };
    return sf::Vector2f{
        viewRect.position.x + viewRect.size.x * (worldPos.x - globalBounds.xMin()) / globalBounds.getSize().x,
        viewRect.position.y - viewRect.size.y * (worldPos.y - globalBounds.yMax()) / globalBounds.getSize().y
    };
}

/* Convert a size expressed in world-space units to size in screen pixels,
 * matching the same viewport used by worldToScnCoords. */
inline sf::Vector2f worldToScnSize(const sf::Vector2f& entityWorldSize,
                                   const sf::Vector2f& globalBoundsSize,
                                   const sf::Vector2u& windowSize)
{
    const sf::FloatRect viewRect{ computeViewport(windowSize, Constants::g_targetAspectRatio) };
    return sf::Vector2f{
        viewRect.size.x * entityWorldSize.x / globalBoundsSize.x,
        viewRect.size.y * entityWorldSize.y / globalBoundsSize.y
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
