#pragma once

#include "World.h"

#include <SFML/Graphics.hpp>

class Game {
public:
    enum class State {
        Playing,
        GameOver,
        Paused,
        Menu,
    };

private:
    unsigned int        m_windowWidth  = 800;
    unsigned int        m_windowHeight = 600;
    unsigned int        m_targetFps    = 60;
    State               m_state;
    sf::RenderWindow    m_window;
    World               m_world;

public:
    Game(State initState);

    bool isRunning() const { return m_window.isOpen(); }

    void processEvents();
    void update(const float dt);
    void render();
};
