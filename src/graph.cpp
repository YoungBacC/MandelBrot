#include "headers/graph.h"

// constructor
Graph::Graph(const sf::RenderWindow &win)
    : canvas(win.getSize(), sf::Color::White), canvasTexture(canvas),
      canvasSprite(canvasTexture) {
  sf::Image image(win.getSize(), sf::Color::White);
  origin = sf::Vector2f(win.getSize().x / 2.0, win.getSize().y / 2.0);
  scale = 1;
}

// setters
void Graph::setOrigin(const sf::RenderWindow &win, const sf::Vector2f &o) {
  float newX = win.getSize().x / 2.0 + o.x;
  float newY = win.getSize().y / 2.0 - o.y;
  origin = sf::Vector2f(newX, newY);
}

void Graph::setScale(const double s) { scale = s; }

// getters
sf::Vector2f Graph::getOrigin() { return origin; }
double Graph::getScale() { return scale; }
sf::Sprite Graph::getCanvas() { return canvasSprite; }

// other functions

void Graph::drawPoint(const sf::Vector2u &pos) {
  canvas.setPixel(pos, sf::Color::Black);
}

void Graph::drawPointIt(const sf::Vector2u &pos, unsigned it) {
  sf::Color color;
  if (it > 35) {
    color = sf::Color::Red;
  } else if (it > 25) {
    color = sf::Color::Yellow;
  } else if (it > 15) {
    color = sf::Color::White;
  } else {
    color = sf::Color::Blue;
  }

  canvas.setPixel(pos, color);
}

void Graph::updateTexture() { canvasTexture.update(canvas); }

sf::Vector2f Graph::convertWinToComplex(const sf::Vector2u &winCoord,
                                        const sf::RenderWindow &win) {
  float newX = (2 * scale / win.getSize().y) * (winCoord.x) - scale;
  float newY = (2 * scale / win.getSize().y) * (winCoord.y) - scale;

  return sf::Vector2f(newX, newY);
}
