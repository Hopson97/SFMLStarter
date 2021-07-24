#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include <vector>

class GUI;

class Screen;

class ScreenManager final {
    struct Action {
        enum class Kind {
            Push,
            Pop,
            Change,
        };
        Kind kind;
        std::unique_ptr<Screen> screen;
    };

  public:
    void pushScreen(std::unique_ptr<Screen> screen);
    void popScreen();
    void changeScreen(std::unique_ptr<Screen> screen);

    void update();

    Screen& peekScreen();

    bool hasScreen() const;

  private:
    std::stack<std::unique_ptr<Screen>> m_screens;
    std::vector<Action> m_actions;
};

class Screen {
  public:
    Screen(ScreenManager* screens);
    virtual ~Screen() = default;

    virtual void onGUI([[maybe_unused]] GUI* gui) {}
    virtual void onInput() {}
    virtual void onUpdate([[maybe_unused]] float dt) {}
    virtual void onRender(sf::RenderWindow* window) = 0;

  protected:
    ScreenManager* m_pScreens;
};
