#include "headers/mandelbrot.h"
#include <iostream>

// Constants
unsigned NUM_OF_IT = 100;

MandelBrot::MandelBrot() { init = ComplexNumber(0, 0); }

ComplexNumber MandelBrot::getInit() const { return init; }

void MandelBrot::setInit(const ComplexNumber &c) { init = c; }

ComplexNumber MandelBrot::function(const ComplexNumber &z,
                                   const ComplexNumber &c) {
  return (z.square() + c);
}

bool MandelBrot::calculate(const ComplexNumber &c, int &numIt) {
  ComplexNumber z = init;
  for (int i = 0; i < NUM_OF_IT; i++) {
    z = function(z, c);

    if (z.mag() > 2.0) {
      return false;
    }
    numIt++;
  }
  return true;
}

void MandelBrot::loop(Graph &g, sf::RenderWindow &win) {
  float scale = g.getScale();
  unsigned winX = win.getSize().x;
  unsigned winY = win.getSize().y;
  sf::Vector2f center = g.getCenter();
  sf::Vector2f origin = g.getOrigin();
  float diff = ((winX - winY) / 2.f) * (2.f * scale / winY);
  std::cout << diff << std::endl;
  for (unsigned r = 0; r < win.getSize().x; r++) {
    for (unsigned c = 0; c < win.getSize().y; c++) {
      int numOfIt = 0;
      float newReal = (2 * (scale + diff) * r / winX) - scale - diff -
                      (origin.x - center.x) / winY;
      float newImag =
          -1 * (2 * scale * c / winY) + scale + (origin.y - center.y) / winY;
      sf::Color pointColor;
      if (calculate(ComplexNumber(newReal, newImag), numOfIt)) {
        g.drawPoint(sf::Vector2u(r, c));
      } else {
        g.drawPointIt(sf::Vector2u(r, c), numOfIt, NUM_OF_IT);
      }
    }
  }
  g.updateTexture();
}
