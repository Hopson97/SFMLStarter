#include "ScreenMainMenu.h"

#include "GUI.h"
#include "ScreenGame.h"

ScreenMainMenu::ScreenMainMenu(ScreenManager* stack)
    : Screen(stack)

{
}

void ScreenMainMenu::onGUI(GUI* gui)
{
    if (gui->button({50, 50}, {50, 50})) {
        m_pScreens->pushScreen(std::make_unique<ScreenGame>(m_pScreens));
    }
}
void ScreenMainMenu::onRender(sf::RenderWindow* window) {}
