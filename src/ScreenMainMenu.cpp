#include "ScreenMainMenu.h"
#include "ScreenGame.h"
#include <imgui_sfml/imgui.h>

ScreenMainMenu::ScreenMainMenu(ScreenManager* stack)
    : Screen(stack)

{
}

void ScreenMainMenu::onGUI()
{
    ImGui::Begin("Main Menu");
    if (ImGui::Button("Play Game")) {
        m_pScreens->pushScreen(std::make_unique<ScreenGame>(m_pScreens));
    }
    ImGui::End();
}
void ScreenMainMenu::onRender(sf::RenderWindow* window) {}
