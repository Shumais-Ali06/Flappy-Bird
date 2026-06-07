#include "../include/Game.h"
#include "../include/Constants.h"

Game::Game(State initState)
    : m_state{ initState }
    , m_window{ sf::VideoMode{{m_windowWidth, m_windowHeight}},
                              Constants::g_appTitle,
                              sf::Style::Titlebar | sf::Style::Close }
    , m_world{}
    {
        m_window.setFramerateLimit(m_targetFps);
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

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::Space) {
                m_world.getBird().jump();
            }
        }
    }
}
