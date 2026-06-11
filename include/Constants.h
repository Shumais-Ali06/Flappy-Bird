#pragma once

#include "WorldBounds.h"

// Might split these further later on
namespace Constants {
    constexpr const char* g_appTitle        = "Flappy Bird";
    constexpr const char* g_birdTexturePath = "assets/Player/StyleBird1/AllBird1.png";
    constexpr const char* g_skyTexturePath  = "assets/Background/Background3.png";
    constexpr const char* g_flrTexturePath  = "assets/Tiles/Style 1/SimpleStyle1.png";
    constexpr WorldBounds g_worldBounds     = WorldBounds{ -20.0f, 80.0f, -20.0f, 80.0f };
}
