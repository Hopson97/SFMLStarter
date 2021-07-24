#include "ScreenGame.h"
#include <cmath>

#include "GUI.h"
#include "ScreenMainMenu.h"

ScreenGame::ScreenGame(ScreenManager* stack)
    : Screen(stack)

{
    m_sprite.setSize({64, 64});
}

void ScreenGame::onGUI(GUI* gui)
{
    if (gui->button({50, 50}, {50, 50})) {
        m_pScreens->popScreen();
    }
}

void ScreenGame::onUpdate(float dt)
{
    static float y = 500;
    y += std::sin(m_clock.getElapsedTime().asSeconds() * dt * 100);
    m_sprite.setPosition({300, y});
}
void ScreenGame::onRender(sf::RenderWindow* window) { window->draw(m_sprite); }
