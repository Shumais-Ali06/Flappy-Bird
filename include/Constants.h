#pragma once

#include "WorldBounds.h"

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

    constexpr WorldBounds g_globalBounds        = WorldBounds{ -20.0f, 80.0f, -20.0f, 80.0f };
    constexpr float       g_pipeWidth           = 10.0f;
    constexpr float       g_pipeGapLength       = 20.0f;
}
