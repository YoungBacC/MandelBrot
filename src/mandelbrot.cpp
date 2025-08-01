#include "headers/mandelbrot.h"
#include <iostream>

MandelBrot::MandelBrot() { init = ComplexNumber(0, 0); }

ComplexNumber MandelBrot::getInit() const { return init; }

void MandelBrot::setInit(const ComplexNumber &c) { init = c; }

ComplexNumber MandelBrot::function(const ComplexNumber &z,
                                   const ComplexNumber &c) {
  return (z.square() + c);
}

bool MandelBrot::calculate(const ComplexNumber &c, int &numIt) {
  ComplexNumber z = init;
  for (int i = 0; i < 100; i++) {
    z = function(z, c);

    if (z.mag() > 2.0) {
      numIt = i;
      return false;
    }
  }
  return true;
}

void MandelBrot::loop(Graph &g, sf::RenderWindow &win) {
  float scale = g.getScale();
  unsigned winX = win.getSize().x;
  unsigned winY = win.getSize().y;
  float diff = float(winX) / float(winY);
  std::cout << diff << std::endl;
  for (unsigned r = 0; r < win.getSize().x; r++) {
    for (unsigned c = 0; c < win.getSize().y; c++) {
      int numOfIt = 0;
      float newReal = (2 * (scale + diff) * r / winX) - scale - diff;
      float newImag = -1 * (2 * scale * c / winY) + scale;
      sf::Color pointColor;
      if (calculate(ComplexNumber(newReal, newImag), numOfIt)) {
        g.drawPoint(sf::Vector2u(r, c));
      } else {
        g.drawPointIt(sf::Vector2u(r, c), numOfIt);
      }
    }
  }
  g.updateTexture();
}
