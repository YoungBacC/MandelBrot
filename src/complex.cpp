#include "headers/complex.h"
#include <math.h>

ComplexNumber::ComplexNumber() {
  real = 0;
  imaginary = 0;
}

ComplexNumber::ComplexNumber(const double r, const double i) {
  real = r;
  imaginary = i;
}

void ComplexNumber::setReal(double r) { real = r; }

void ComplexNumber::setImaginary(double i) { imaginary = i; }

double ComplexNumber::getReal() const { return real; }

double ComplexNumber::getImaginary() const { return imaginary; }

sf::Vector2f ComplexNumber::getCoords() {
  return sf::Vector2f(real, imaginary);
}

ComplexNumber ComplexNumber::square() const {
  return ComplexNumber(pow(real, 2) - pow(imaginary, 2), 2 * real * imaginary);
}

double ComplexNumber::mag() const {
  return sqrt(pow(real, 2) + pow(imaginary, 2));
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) {
  return ComplexNumber(this->real + other.real,
                       this->imaginary + other.imaginary);
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &c) {
  if (this != &c) {
    real = c.real;
    imaginary = c.imaginary;
  }

  return *this;
}
