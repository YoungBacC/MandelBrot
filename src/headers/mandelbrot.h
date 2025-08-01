#pragma once
#include "complex.h"
#include "graph.h"
#include <math.h>
#include <vector>

class MandelBrot {
private:
  std::vector<ComplexNumber> set;
  ComplexNumber init;

public:
  MandelBrot();

  ComplexNumber getInit() const;

  void setInit(const ComplexNumber &);

  ComplexNumber function(const ComplexNumber &, const ComplexNumber &);

  bool calculate(const ComplexNumber &, int &);

  void loop(Graph &, sf::RenderWindow &win);
};
