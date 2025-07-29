#include "headers/point.h"

Point::Point(const sf::Vector2f &p, const sf::Vector2f &rp, double r,
             const sf::Color &c) {
  pos = p;
  sprite.setPosition(rp);
  sprite.setRadius(r);
  sprite.setFillColor(c);
}

sf::Vector2f Point::getPos() { return pos; }

void Point::setPos(const sf::Vector2f &p) { pos = p; }

void Point::setRenderPos(const sf::Vector2f p) { sprite.setPosition(p); }

sf::CircleShape Point::getPoint() { return sprite; }
