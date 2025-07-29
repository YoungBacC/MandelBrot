#include "headers/graph.h"

// constants
const unsigned AXIS_WIDTH = 2;
const sf::Color AXIS_COLOR = sf::Color::White;
const double POINT_RADIUS = 0.5;
const sf::Color POINT_COLOR = sf::Color::Red;

Graph::Graph(const sf::RenderWindow &win) {
  origin = sf::Vector2f(win.getSize().x / 2.0, win.getSize().y / 2.0);
  scale = 1;
}

Graph::Graph(const sf::RenderWindow &win, const double s) {
  origin = sf::Vector2f(win.getSize().x / 2.0, win.getSize().y / 2.0);
  scale = s;
}

Graph::Graph(const sf::RenderWindow &win, const sf::Vector2f &o,
             const double s) {
  origin =
      sf::Vector2f(win.getSize().x / 2.0 + o.x, win.getSize().y / 2.0 - o.y);
  scale = s;
}

void Graph::drawAxes(sf::RenderWindow &win) {
  // create graph
  complexAxis.setPosition({origin.x - AXIS_WIDTH / 2.f, 0});
  complexAxis.setFillColor(AXIS_COLOR);
  complexAxis.setSize(sf::Vector2f(AXIS_WIDTH, win.getSize().y));

  realAxis.setPosition({0, origin.y - AXIS_WIDTH / 2.f});
  realAxis.setFillColor(AXIS_COLOR);
  realAxis.setSize(sf::Vector2f(win.getSize().x, AXIS_WIDTH));

  win.draw(complexAxis);
  win.draw(realAxis);
}

void Graph::setOrigin(const sf::RenderWindow &win, const sf::Vector2f &o) {
  origin =
      sf::Vector2f(win.getSize().x / 2.0 + o.x, win.getSize().y / 2.0 - o.y);

  complexAxis.setPosition({origin.x - AXIS_WIDTH / 2.f, 0});
  complexAxis.setFillColor(AXIS_COLOR);
  complexAxis.setSize(sf::Vector2f(AXIS_WIDTH, win.getSize().y));

  realAxis.setPosition({0, origin.y - AXIS_WIDTH / 2.f});
  realAxis.setFillColor(AXIS_COLOR);
  realAxis.setSize(sf::Vector2f(win.getSize().x, AXIS_WIDTH));
}

void Graph::setScale(const double s) { scale = s; }

sf::Vector2f Graph::getOrigin() { return origin; }

double Graph::getScale() { return scale; }

std::vector<Point *> Graph::getPoints() { return points; }

void Graph::addPoint(const sf::Vector2f &pos, const sf::RenderWindow &win) {
  Point *point =
      new Point(pos, positionPoint(pos, win), POINT_RADIUS, POINT_COLOR);
  points.push_back(point);
}

void Graph::drawPoints(sf::RenderWindow &win) {
  for (auto i : points) {
    sf::Vector2f pos = i->getPos();
    sf::Vector2f newPos = positionPoint(pos, win);
    i->setRenderPos(newPos);
    win.draw(i->getPoint());
  }
}

sf::Vector2f Graph::positionPoint(const sf::Vector2f &pos,
                                  const sf::RenderWindow &win) {
  float tick = win.getSize().y / scale;
  float posX = (origin.x + pos.x - POINT_RADIUS) + pos.x * tick;
  float posY = (origin.y - pos.y - POINT_RADIUS) - pos.y * tick;
  return sf::Vector2f(posX, posY);
}

void Graph::clearPoints() {
  for (auto i : points) {
    delete i;
  }
  points.clear();
}
