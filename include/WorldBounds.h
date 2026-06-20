#pragma once

#include <SFML/System.hpp>
#include <cassert>

/* Represents an axis-aligned bounding box (AABB) in world space to describe
 * the extents of the game world and entities for bounds checking.
 *
 * NOTE:
 * - Do not use this type for screen-space coordinates or render-size calculations.
 * - SFML's sf::FloatRect is the appropriate type for screen/render rectangles,
 *   since SFML coordinates measure from the top-left corner in screen space. */

class WorldBounds {
private:
    sf::Vector2f            m_pos;          // Lower-left corner of the rectangle
    const sf::Vector2f      m_size;         // Size of the bounding box in world units

public:
    // Marked constexpr to generate constant for global bounds
    constexpr WorldBounds(const float xMin, const float xMax, const float yMin, const float yMax)
        : m_pos{ xMin, yMin }
        , m_size{ xMax - xMin, yMax - yMin }
    {
        assert(xMin < xMax && "xMin must be < xMax");
        assert(yMin < yMax && "yMin must be < yMax");
    }

    WorldBounds(const sf::Vector2f& pos, const sf::Vector2f& size)
        : m_pos{ pos }
        , m_size{ size }
    {
        assert(size.x > 0 && size.y > 0 && "size must be positive");
    }

    constexpr const sf::Vector2f& getPos() const { return m_pos; }
    constexpr const sf::Vector2f& getSize() const { return m_size; }

    float xMin() const { return m_pos.x; }
    float xMax() const { return m_pos.x + m_size.x; }
    float yMin() const { return m_pos.y; }
    float yMax() const { return m_pos.y + m_size.y; }

    // Returns true only if both rectangles have a positive overlapping area
    bool doesIntersect(const WorldBounds& o) const
    {
        if (m_size.x <= 0 || m_size.y <= 0 || o.getSize().x <= 0 || o.getSize().y <= 0) {
            return false;
        }

        return xMin() < o.xMax() && o.xMin() < xMax() && yMin() < o.yMax() && o.yMin() < yMax();
    }
};
