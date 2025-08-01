#include "headers/mandelbrot.h"
#include <math.h>

void handleKeyInputs(sf::RenderWindow &, Graph &, MandelBrot &);
//  define constants here
int main() {
  // window
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "my window");
  Graph graph(window);
  graph.setScale(2);
  MandelBrot set;
  set.loop(graph, window);

  // main loop
  while (window.isOpen()) {
    // define events here
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    handleKeyInputs(window, graph, set);

    window.clear();

    // draw here
    window.draw(graph.getCanvas());

    window.display();
  }
}

void handleKeyInputs(sf::RenderWindow &window, Graph &graph, MandelBrot &set) {
  double moveAmount = 0.05;
  double real = set.getInit().getReal();
  double imag = set.getInit().getImaginary();
  bool moved = false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && imag < 1.5) {
    imag += moveAmount;
    moved = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && real < 1.5) {
    real += moveAmount;
    moved = true;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && imag > -1.5) {
    imag -= moveAmount;
    moved = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && real > -1.5) {
    real -= moveAmount;
    moved = true;
  }

  if (moved) {
    set.setInit(ComplexNumber(real, imag));
    set.loop(graph, window);
  }
}
