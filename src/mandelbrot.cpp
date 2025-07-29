#include "headers/mandelbrot.h"

MandelBrot::MandelBrot() { init = ComplexNumber(0, 0); }

ComplexNumber MandelBrot::getInit() const { return init; }

void MandelBrot::setInit(const ComplexNumber &c) { init = c; }

ComplexNumber MandelBrot::function(const ComplexNumber &z,
                                   const ComplexNumber &c) {
  return (z.square() + c);
}

bool MandelBrot::calculate(const ComplexNumber &c) {
  ComplexNumber z = init;
  for (int i = 0; i < 100; i++) {
    z = function(z, c);

    if (z.mag() > 2.0) {
      return false;
    }
  }
  return true;
}

void MandelBrot::loop(Graph &g, sf::RenderWindow &win) {
  g.clearPoints();
  for (double r = -2; r <= 2; r += 0.01) {
    for (double c = -2; c <= 2; c += 0.01) {
      if (calculate(ComplexNumber(r, c))) {
        g.addPoint(sf::Vector2f(r, c), win);
      }
    }
  }
}
