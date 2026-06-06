#pragma once

#include <SFML/Graphics.hpp>

/* NOTE: All frames within the same animation must have the same y-coordinate,
 * width, size and proceed from left-to-right. */

class Animation {
private:
    const sf::IntRect   m_startFrame;           // Leftmost frame in the spritesheet
    const int           m_numFrames;
    const float         m_framesPerSec;         // Assumed constant (at least for now)
    int                 m_currIndex = 0;        // Tracks current frame in the animation (0-indexed)
    sf::IntRect         m_currFrame;            // Cache the frame for faster retrieval

public:
    Animation(const sf::IntRect& startFrame, const int numFrames, const float framesPerSec)
        : m_startFrame{ startFrame }
        , m_numFrames{ numFrames }
        , m_framesPerSec{ framesPerSec }
        , m_currFrame{ startFrame }
    {
        assert(m_numFrames > 0);
        assert(m_framesPerSec > 0.0f);
    }

    void next()
    {
        m_currIndex = (m_currIndex + 1) % m_numFrames;
        m_currFrame.position.x = m_startFrame.position.x + m_currIndex * m_startFrame.size.x;
    }

    void prev()
    {
        m_currIndex = (m_currIndex + m_numFrames - 1) % m_numFrames;
        m_currFrame.position.x = m_startFrame.position.x + m_currIndex * m_startFrame.size.x;
    }

    float getFramesPerSec() const { return m_framesPerSec; }
    const sf::IntRect& getFrame() const { return m_currFrame; }
};
