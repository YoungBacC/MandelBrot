#pragma once
#include <SFML/Graphics.hpp>

class Point {
private:
  sf::Vector2f pos;
  sf::CircleShape sprite;

public:
  Point(const sf::Vector2f &, const sf::Vector2f &, double, const sf::Color &);

  sf::Vector2f getPos();
  void setPos(const sf::Vector2f &);
  void setRenderPos(const sf::Vector2f);
  sf::CircleShape getPoint();
};
