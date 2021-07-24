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

void GUI::onEvent(sf::Event& event) { m_events.push_back(event); }

void GUI::render()
{
    for (auto& command : m_commands) {
        m_rect.setSize(command.size);
        m_rect.setPosition(command.position);
        m_rect.setFillColor(command.fillColour);
        m_rect.setOutlineColor(command.outlineColour);
        m_rect.setOutlineThickness(command.outlineThickness);

        m_pWindow->draw(m_rect);
    }
    m_events.clear();
}

bool GUI::button(const sf::Vector2f& size, const sf::Vector2f& position)
{
    DrawCommand command;
    command.size = size;
    command.position = position;
    command.outlineThickness = 1.0f;

    auto mousePosition = sf::Mouse::getPosition(*m_pWindow);
    bool clicked = false;
    for (auto& e : m_events) {
        if (e.type == sf::Event::MouseButtonReleased) {
            clicked = doesContain(m_rect, e.mouseButton);
        }
    }
    if (doesContain(m_rect, mousePosition)) {
        command.fillColour = sf::Color::Green;
    }

    m_commands.push_back(command);

    return clicked;
}