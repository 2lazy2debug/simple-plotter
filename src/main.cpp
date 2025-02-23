#include "components/graph_components.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

const bool is_debug = false;

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({640u, 480u}), "SimplePlotter");

  window.setFramerateLimit(60);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (event->is<sf::Event::Resized>()) {
        sf::View cur_view = window.getView();
        cur_view.setSize({static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)});
        cur_view.setCenter(cur_view.getSize() / 2.f);
        window.setView(cur_view);
      }
    }
    window.clear(sf::Color::Black);

    if (is_debug) {
      window.setFramerateLimit(10);
      sp::draw_debug(window);
    }

    sp::draw_axes(window, 10, 10 * window.getSize().y / window.getSize().x);

    window.display();
  }
}