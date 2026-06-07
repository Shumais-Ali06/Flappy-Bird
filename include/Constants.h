#pragma once

// Might split these further later on
namespace Constants {
    constexpr const char* g_appTitle        = "Flappy Bird";
    constexpr const char* g_birdTexturePath = "assets/Player/StyleBird1/AllBird1.png";
    constexpr float g_pi                    = 3.14159f;

    // NOTE: x = 0 at the bird's position (increases to the right) 
    //       y = 0 at the ground level    (increases upwards)
    constexpr float yMax =  80.0f;
    constexpr float yMin = -20.0f;
    constexpr float xMax =  80.0f;
    constexpr float xMin = -20.0f;
}
