#include "headers/graph.h"
#include <iostream>

// constructor
Graph::Graph(const sf::RenderWindow &win)
    : canvas(win.getSize(), sf::Color::White), canvasTexture(canvas),
      canvasSprite(canvasTexture) {
  sf::Image image(win.getSize(), sf::Color::White);
  origin = sf::Vector2f(win.getSize().x / 2.0, win.getSize().y / 2.0);
  center = origin;
  scale = 1;
}

// setters
void Graph::setOrigin(const sf::RenderWindow &win, const sf::Vector2f &o) {
  float newX = win.getSize().x / 2.0 + o.x;
  float newY = win.getSize().y / 2.0 - o.y;
  origin = sf::Vector2f(newX, newY);
}

void Graph::setScale(const double s) { scale = s; }

void Graph::setCenter(const sf::Vector2f &c) { center = c; }

// getters
sf::Vector2f Graph::getOrigin() { return origin; }
double Graph::getScale() { return scale; }
sf::Sprite Graph::getCanvas() { return canvasSprite; }
sf::Vector2f Graph::getCenter() { return center; }

// other functions

void Graph::drawPoint(const sf::Vector2u &pos) {
  canvas.setPixel(pos, sf::Color::Black);
}

void Graph::drawPointIt(const sf::Vector2u &pos, unsigned it, unsigned maxIt) {
  sf::Color color;
  float t = it / float(maxIt); // normalized 0..1
  std::uint8_t r = static_cast<std::uint8_t>(15 * (1 - t) * t * t * t * 255);
  std::uint8_t g =
      static_cast<std::uint8_t>(10 * (1 - t) * (1 - t) * t * t * 255);
  std::uint8_t b = 128;

  canvas.setPixel(pos, sf::Color(r, g, b));
}

void Graph::updateTexture() { canvasTexture.update(canvas); }

sf::Vector2f Graph::convertWinToComplex(const sf::Vector2u &winCoord,
                                        const sf::RenderWindow &win) {
  float newX = (2 * scale / win.getSize().y) * (winCoord.x) - scale;
  float newY = (2 * scale / win.getSize().y) * (winCoord.y) - scale;

  return sf::Vector2f(newX, newY);
}
