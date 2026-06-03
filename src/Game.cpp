#include "../include/Game.h"

Game::Game(Config& cfg, State initState)
    : m_cfg{ cfg }
    , m_state{ initState }
    , m_window{ sf::VideoMode{{cfg.windowWidth, cfg.windowHeight}},
                              Constants::g_appTitle,
                              sf::Style::Titlebar | sf::Style::Close }
    , m_world{ cfg.scrollSpeed }
    {
        m_window.setFramerateLimit(cfg.targetFps);
    }

void Game::update(float dt)
{
    if (m_state == State::Playing) {
        m_world.update(dt);
    }
}

void Game::render()
{
    m_window.clear();

    switch (m_state) {
    case State::Playing:
        m_world.drawTo(m_window);
        break;
    case State::GameOver:
        break;
    case State::Paused:
        break;
    case State::Menu:
        break;
    }

    m_window.display();
}

void Game::processEvents()
{
    while (const std::optional event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            m_window.close();
        }
    }
}
