#include "ScreenGame.h"
#include "ScreenMainMenu.h"
#include <cmath>
#include <imgui_sfml/imgui.h>

ScreenGame::ScreenGame(ScreenManager* stack)
    : Screen(stack)

{
    m_sprite.setSize({64, 64});
}

void ScreenGame::onGUI()
{
    ImGui::Begin("Menu");
    if (ImGui::Button("Exit Game")) {
        m_pScreens->popScreen();
    }
    ImGui::End();
}

void ScreenGame::onUpdate(float dt)
{
    static float y = 500;
    y += std::sin(m_clock.getElapsedTime().asSeconds() * dt * 100);
    m_sprite.setPosition({300, y});
}
void ScreenGame::onRender(sf::RenderWindow* window) { window->draw(m_sprite); }
