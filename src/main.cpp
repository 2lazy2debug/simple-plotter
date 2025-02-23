#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

void draw_axes(sf::RenderWindow &window) {

  auto w_coords = window.getSize();

  // std::cout << "x coords : " << w_coords.x << " - y coords : " << w_coords.y
  // << std::endl;

  auto x_axis = sf::RectangleShape({static_cast<float>(w_coords.x), 1.f});
  x_axis.setFillColor(sf::Color::White);
  x_axis.setPosition({0.f, static_cast<float>(w_coords.y / 2)});
  window.draw(x_axis);

  auto y_axis = sf::RectangleShape({1.f, static_cast<float>(w_coords.y)});
  y_axis.setFillColor(sf::Color::White);
  y_axis.setPosition({static_cast<float>((w_coords.x / 2)), 0});
  window.draw(y_axis);
}

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({640u, 480u}), "SimplePlotter");

  window.setFramerateLimit(60);
  auto view = window.getDefaultView();
  // view.setCenter({0, 0});
  // window.setView(view);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (event->is<sf::Event::Resized>()) {
        view.setSize({0, 0}); // todo, get size from event
        view.setCenter({0, 0});
        window.setView(view);
      }
    }
    window.clear(sf::Color::Black);

    draw_axes(window);

    window.display();
  }
}