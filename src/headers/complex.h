#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class ComplexNumber {
private:
  double real;
  double imaginary;

public:
  // constructor
  ComplexNumber();
  ComplexNumber(const double, const double);

  // setters
  void setReal(const double);
  void setImaginary(const double);

  // getters
  double getReal() const;
  double getImaginary() const;

  // public methods

  // returns the coordinates of the
  // imaginary number in the complex plane
  sf::Vector2f getCoords();

  ComplexNumber square() const;

  double mag() const;

  // operator overload
  ComplexNumber operator+(const ComplexNumber &);

  ComplexNumber &operator=(const ComplexNumber &);
};
