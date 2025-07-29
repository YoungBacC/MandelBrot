// #pragma once
#include "point.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
private:
  sf::Vector2f origin;
  double scale;
  sf::RectangleShape complexAxis;
  sf::RectangleShape realAxis;
  std::vector<Point *> points;

public:
  // constructors:
  // 1: will create a graph for a real axis and imaginary axis at the origin
  // 2. will create a graph for a real axis and imaginary axis with specified
  //	 scale and origin relative to the window's middle.
  Graph(const sf::RenderWindow &);
  Graph(const sf::RenderWindow &, const double);
  Graph(const sf::RenderWindow &, const sf::Vector2f &, double);

  // setter
  void setOrigin(const sf::RenderWindow &, const sf::Vector2f &);
  void setScale(const double);

  // getter
  sf::Vector2f getOrigin();
  double getScale();
  std::vector<Point *> getPoints();

  // public methods

  // draws the complex and real axes.
  void drawAxes(sf::RenderWindow &);

  sf::Vector2f positionPoint(const sf::Vector2f &, const sf::RenderWindow &);

  // creates and adds a point to the points Vector with specified coords
  void addPoint(const sf::Vector2f &, const sf::RenderWindow &);

  // draws all points to the window in the points vector
  void drawPoints(sf::RenderWindow &);

  void clearPoints();
};
