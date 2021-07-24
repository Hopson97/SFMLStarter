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

bool imguiBeginMenu(const char* name)
{
    ImVec2 windowSize(1280 / 4, 720 / 2);
    ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
    ImGui::SetNextWindowPos({windowSize.x + windowSize.x * 4 / 8.0f, windowSize.y / 2},
                            ImGuiCond_Always);
    return ImGui::Begin(name, nullptr,
                        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                            ImGuiWindowFlags_NoCollapse |
                            ImGuiWindowFlags_AlwaysAutoResize);
}

bool imguiButtonCustom(const char* text)
{
    ImGui::SetCursorPos({ImGui::GetCursorPosX() + 100, ImGui::GetCursorPosY() + 20});
    return ImGui::Button(text, {100, 50});
}
