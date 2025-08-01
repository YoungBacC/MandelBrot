// #pragma once
#include <SFML/Graphics.hpp>

class Graph {
private:
  sf::Vector2f origin;
  double scale;
  sf::Image canvas;
  sf::Texture canvasTexture;
  sf::Sprite canvasSprite;
  ;

public:
  // constructors:
  // 1: will create a graph for a real axis and imaginary axis at the origin
  // 2. will create a graph for a real axis and imaginary axis with specified
  //	 scale and origin relative to the window's middle.
  Graph(const sf::RenderWindow &);

  // setter
  void setOrigin(const sf::RenderWindow &, const sf::Vector2f &);
  void setScale(const double);

  // getter
  sf::Vector2f getOrigin();
  double getScale();
  sf::Sprite getCanvas();

  // public methods
  void drawPoint(const sf::Vector2u &);

  void drawPointIt(const sf::Vector2u &, unsigned);

  void updateTexture();

  // function to convert window coords to complex coords according to scale
  sf::Vector2f convertWinToComplex(const sf::Vector2u &,
                                   const sf::RenderWindow &);
};
