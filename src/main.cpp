#include "headers/mandelbrot.h"
#include <math.h>
#include <string>

void handleKeyInputs(sf::RenderWindow &, Graph &, MandelBrot &);
void saveScreenshot(sf::RenderWindow &, int &);
//  define constants here
int main() {
  // window
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "my window");
  Graph graph(window);
  graph.setScale(1);
  graph.setCenter({136.57, 247.83});
  MandelBrot set;
  set.loop(graph, window);
  int ssCount = 0;
  // main loop
  while (window.isOpen()) {
    // define events here
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    bool scaled = false;
    handleKeyInputs(window, graph, set);

    if (graph.getScale() > 0.0001) {
      float currScale = graph.getScale();
      float inverseScale = 1 / currScale;
      float logScale = std::log(inverseScale);
      logScale += 0.5;
      graph.setScale(std::exp(-logScale));
      set.loop(graph, window);
      scaled = true;
    }

    window.clear();

    // draw here
    window.draw(graph.getCanvas());

    if (scaled) {
      saveScreenshot(window, ssCount);
    }

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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    float currScale = graph.getScale();
    float inverseScale = 1 / currScale;
    float logScale = std::log(inverseScale);
    logScale++;
    graph.setScale(std::exp(-logScale));
    moved = true;
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    graph.setCenter(sf::Vector2f(mousePos.x, mousePos.y));
    moved = true;
  }

  if (moved) {
    set.setInit(ComplexNumber(real, imag));
    set.loop(graph, window);
  }
}

void saveScreenshot(sf::RenderWindow &win, int &count) {
  sf::Texture texture(win.getSize());
  texture.update(win);

  sf::Image screenshot = texture.copyToImage();

  std::string fileName = "ss" + std::to_string(count) + ".png";

  (void)screenshot.saveToFile(fileName);

  count += 1;
}
