#pragma once

#include "WorldBounds.h"

#include <SFML/Graphics.hpp>

// Might split these further later on
namespace Constants {
    constexpr const char*   g_appTitle          = "Flappy Bird";
    constexpr unsigned int  g_windowWidth       = 800;
    constexpr unsigned int  g_windowHeight      = 600;
    constexpr unsigned int  g_targetFps         = 60;

    constexpr const char* g_birdTexturePath     = "assets/Player/StyleBird1/AllBird1.png";
    constexpr const char* g_bgTexturePath       = "assets/Background/Background3.png";
    constexpr const char* g_flrTexturePath      = "assets/Tiles/Style 1/SimpleStyle1.png";
    constexpr const char* g_pipeTexturePath     = "assets/Tiles/Style 1/PipeStyle1.png";

    constexpr WorldBounds g_globalBounds        = WorldBounds{ -20.0f, 100.0f, -20.0f, 80.0f };
    constexpr float       g_pipeWidth           = 10.0f;
    constexpr float       g_pipeGapLength       = 20.0f;

    /* Scale ratio between drawing (screen) and world coordinates.
     * Computed as (drawX/worldX) / (drawY/worldY).
     * =1.0: uniform scale in X and Y (no aspect distortion).
     * >1.0: X is scaled more than Y (horizontal stretch).
     * <1.0: Y is scaled more than X (vertical stretch). */
    constexpr float         g_scaleRatio        = 1.0f / 1.0f;

    // World aspect ratio: width divided by height
    constexpr float         g_worldRatio        = g_globalBounds.width() / g_globalBounds.height();

    /* Target aspect ratio used for rendering: combines world aspect with
     * the scale ratio that maps world units to screen units.
     * Computed as (worldWidth/worldHeight) * ((drawX/worldX) / (drawY/worldY)).
     * - =1.0: final rendering has a 1:1 aspect (no distortion).
     * - >1.0: final output is wider than tall.
     * - <1.0: final output is taller than wide.
     * Used to decide letterboxing, scaling strategy, etc */
    constexpr float         g_targetAspectRatio = g_worldRatio * g_scaleRatio;
}
