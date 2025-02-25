#ifndef GRAPH_COMPONENTS
#define GRAPH_COMPONENTS

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace sp {

  void draw_axes(sf::RenderWindow &window, short x_steps, short y_steps);
  void draw_points(sf::VertexArray &point_collection, sf::RenderWindow &window);

  void draw_function(sf::Vector2f &bounds, sf::RenderWindow &window, std::string function);
  void draw_debug(sf::RenderWindow &window);

} // namespace sp

#endif