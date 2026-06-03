#pragma once

#include "Config.h"
#include "Constants.h"
#include "World.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    enum class State {
        Playing,
        GameOver,
        Paused,
        Menu,
    };

private:
    Config&             m_cfg;
    State               m_state;
    sf::RenderWindow    m_window;
    World               m_world;

public:
    Game(Config& cfg, State initState);

    bool isRunning() const { return m_window.isOpen(); }

    void processEvents();
    void update(const float dt);
    void render();
};
