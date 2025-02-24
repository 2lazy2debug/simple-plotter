#include "components/graph_components.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
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

    sp::draw_axes(window, 11, 11 * window.getSize().y / window.getSize().x);

    auto pt1 = sf::Vector2f{30.f, 40.f};
    sf::VertexArray va = sf::VertexArray(sf::PrimitiveType::LineStrip, 100);
    sf::VertexArray va2 = sf::VertexArray(sf::PrimitiveType::Points, 100);
    for (int i = 0; i < 20; ++i) {
      // sp::draw_point(pt1, window);
      pt1 *= 1.15f;
      va[i].position = pt1;
      va[i].color = sf::Color::Cyan;
      va2[i].position = pt1;
      va2[i].color = sf::Color::Red;
    }

    // sp::draw_points(va, window);
    sp::draw_points(va2, window);

    window.display();
  }
}