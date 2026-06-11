#pragma once

#include <cassert>

struct WorldBounds {
    float xMin, xMax, yMin, yMax;

    constexpr WorldBounds(const float xMin, const float xMax, const float yMin, const float yMax)
        : xMin{ xMin }, xMax{ xMax }, yMin{ yMin }, yMax{ yMax }
    {
        assert(xMin < xMax && "xMin must be < xMax");
        assert(yMin < yMax && "yMin must be < yMax");
    }

    float width() const { return xMax - xMin; }
    float height() const { return yMax - yMin; }
};
