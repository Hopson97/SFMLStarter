#pragma once

#include "Screen.h"

class ScreenGame final : public Screen {
    enum class Menu {
        MainMenu,
        SettingsMenu,
    };

  public:
    ScreenGame(ScreenManager* screens);

    void onGUI(GUI* gui) override;
    void onUpdate(float dt) override;
    void onRender(sf::RenderWindow* window) override;

  private:
    Menu m_activeMenu = Menu::MainMenu;

    sf::RectangleShape m_sprite;
    sf::Clock m_clock;
};
