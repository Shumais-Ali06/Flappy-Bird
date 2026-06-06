#pragma once

#include "Animation.h"

#include <SFML/Graphics.hpp>

/* Utility class to encapsulate sprites with animated frames from an existing texture */
class Sprite {
private:
    sf::Sprite  m_sprite;
    Animation   m_anim;
    float       m_acc = 0.0f;       // time accumluator

public:
    Sprite(const sf::Texture& tex, const sf::IntRect& texRect, const int numFrames, const float framesPerSec)
        : m_sprite{ tex, texRect }
        , m_anim{ texRect, numFrames, framesPerSec }
    {
    }

    void playAnimation(const float dt)
    {
        const float spf = 1.0f / m_anim.getFramesPerSec();
        m_acc += dt;

        // advance one or more frames if enough time has accumulated
        while (m_acc >= spf) {
            m_acc -= spf;
            m_anim.next();
            m_sprite.setTextureRect(m_anim.getFrame());
        }
    }

    sf::Sprite& sprite() { return m_sprite; }
};
