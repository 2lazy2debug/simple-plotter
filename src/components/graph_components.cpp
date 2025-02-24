#include "graph_components.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace sp {

  void draw_axes(sf::RenderWindow &window, short x_steps, short y_steps) {

    sf::Vector2f w_coords = window.getView().getSize();
    sf::Vector2f center_coords({(w_coords.x / 2), (w_coords.y / 2)});

    auto x_axis = sf::RectangleShape({w_coords.x, 1});
    x_axis.setFillColor(sf::Color::White);
    x_axis.setPosition({0, w_coords.y / 2});
    window.draw(x_axis);

    auto y_axis = sf::RectangleShape({1, w_coords.y});
    y_axis.setFillColor(sf::Color::White);
    y_axis.setPosition({(w_coords.x / 2.f), 0});
    window.draw(y_axis);

    for (short i = 0; i < x_steps; ++i) {
      auto step = sf::RectangleShape({1, 20});
      auto step_width = w_coords.x / x_steps;
      step.setFillColor(sf::Color::White);
      step.setPosition({(i * step_width) + (step_width / 2), w_coords.y / 2 - 10});
      window.draw(step);
    }

    for (short i = 0; i < y_steps; ++i) {
      auto step = sf::RectangleShape({20, 1});
      auto step_width = w_coords.y / y_steps;
      step.setFillColor(sf::Color::White);
      step.setPosition({w_coords.x / 2 - 10, (i * step_width) + (step_width / 2)});
      window.draw(step);
    }
  }

  void draw_point(sf::Vector2f &point_v, sf::RenderWindow &window) {
    sf::Vertex point(point_v, sf::Color::White);
    window.draw(&point, 1, sf::PrimitiveType::Points);
  }
  void draw_points(sf::VertexArray &point_collection, sf::RenderWindow &window) { window.draw(point_collection); }

  void draw_function(sf::Vector2f &bounds, sf::RenderWindow &window, std::string function) {}

  void draw_debug(sf::RenderWindow &window) {
    sf::RectangleShape window_rect({static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)});
    window_rect.setFillColor(sf::Color(0, 0, 255, 127));
    window_rect.setPosition({0.f, 0.f});
    window.draw(window_rect);

    sf::RectangleShape view_rect({window.getView().getSize().x, window.getView().getSize().y});
    view_rect.setFillColor(sf::Color(255, 0, 0, 127));
    view_rect.setPosition({0.f, 0.f});
    window.draw(view_rect);

    std::cout << "window size : " << window.getSize().x << "x" << window.getSize().y
              << " - view size : " << window.getView().getSize().x << "x" << window.getView().getSize().y << std::endl;
  }

} // namespace sp