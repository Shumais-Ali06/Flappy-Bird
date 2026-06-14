#include "../include/PipeManager.h"
#include "../include/PipePair.h"
#include "../include/Constants.h"

#include <SFML/Graphics.hpp>

PipeManager::PipeManager(const char* pathToTexture, const float interspacing, const int scrollSpeed)
    : m_tex{ pathToTexture, false, { {0,0}, {32,64} } }
    , m_interspacing{ interspacing }
    , m_scrollSpeed{ scrollSpeed }
{
}

void PipeManager::update(const float dt)
{
    /* Add pipes until the distance between the rightmost pipe and the right
     * side of the screen is less than the distance between two pipes */
    while (m_pipes.empty() || Constants::g_globalBounds.xMax - m_pipes.back().getPosX() > m_interspacing) {
        auto getRandInt = [](const int min, const int max) {
            return min + rand() % (max - min + 1);
        };
        const float gapHeight = getRandInt(Constants::g_pipeGapLength, Constants::g_globalBounds.yMax - Constants::g_pipeGapLength);
        const float initPosX  = Constants::g_globalBounds.xMax + Constants::g_pipeWidth / 2.0f;
        m_pipes.push_back(PipePair{ m_tex, Constants::g_pipeGapLength, gapHeight, Constants::g_pipeWidth, initPosX });
    }

    // Move each pipe to the left
    const float distMoved = m_scrollSpeed * dt;
    for (auto& pipe : m_pipes) {
        pipe.move(-distMoved);
    }

    // Despawn pipes that go out of bounds
    while (m_pipes.front().getPosX() + Constants::g_pipeWidth / 2.0f < Constants::g_globalBounds.xMin) {
        m_pipes.pop_front();
    }
}

void PipeManager::drawPipes(sf::RenderWindow& window)
{
    for (auto& pipe : m_pipes) {
        pipe.drawTo(window);
    }
}
