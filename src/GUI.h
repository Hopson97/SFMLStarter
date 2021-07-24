#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

class GUI {
  public:
    GUI(sf::RenderWindow* window);

    void beginFrame();
    void onEvent(sf::Event& event);

    bool button(const sf::Vector2f& size, const sf::Vector2f& position);

  private:
    sf::RenderWindow* m_pWindow;
    sf::RectangleShape m_rect;

    std::vector<sf::Event> m_events;
};