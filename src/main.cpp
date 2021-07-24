#include "GUI.h"
#include "Keyboard.h"
#include "Screen.h"
#include "ScreenMainMenu.h"
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    sf::RenderWindow window({1280, 720}, "SFML");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    GUI gui(&window);
    Keyboard keyboard;
    ScreenManager screens;
    screens.pushScreen(std::make_unique<ScreenMainMenu>(&screens));
    screens.update();

    sf::Clock updateClock;
    while (window.isOpen() || !screens.hasScreen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            keyboard.update(e);
            gui.onEvent(e);
            switch (e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyReleased:
                    if (e.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }

                default:
                    break;
            }
        }
        screens.peekScreen().onInput();
        screens.peekScreen().onUpdate(updateClock.restart().asSeconds());

        window.clear();
        screens.peekScreen().onGUI(&gui);
        screens.peekScreen().onRender(&window);

        gui.render();

        window.display();
        screens.update();
    }
}