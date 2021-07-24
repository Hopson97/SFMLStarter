#include "GUI.h"

#include <iostream>

namespace {
    template <typename Vector>
    bool doesContain(const sf::RectangleShape& rect, Vector vector)
    {
        float x = static_cast<float>(vector.x);
        float y = static_cast<float>(vector.y);

        return rect.getGlobalBounds().contains({x, y});
    }
} // namespace

GUI::GUI(sf::RenderWindow* window)
    : m_pWindow(window)
{
}

void GUI::beginFrame() { m_events.clear(); }

void GUI::onEvent(sf::Event& event) { m_events.push_back(event); }

bool GUI::button(const sf::Vector2f& size, const sf::Vector2f& position)
{
    m_rect.setSize(size);
    m_rect.setPosition(position);
    m_rect.setFillColor(sf::Color::Blue);

    auto mousePosition = sf::Mouse::getPosition(*m_pWindow);

    bool clicked = false;

    for (auto& e : m_events) {
        if (e.type == sf::Event::MouseButtonReleased) {

            clicked = doesContain(m_rect, e.mouseButton);
        }
    }

    if (doesContain(m_rect, mousePosition)) {
        m_rect.setFillColor(sf::Color::Green);
    }

    m_pWindow->draw(m_rect);

    return clicked;
}