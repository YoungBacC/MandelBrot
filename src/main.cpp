#include "headers/mandelbrot.h"
#include <filesystem>
#include <string>

void handleResize(sf::RenderWindow &, sf::View &, Graph &);
void handleKeyInputs(sf::RenderWindow &, Graph &, MandelBrot &);
// define constants here
int main() {
  // window
  sf::RenderWindow window(sf::VideoMode({800, 600}), "my window");

  // path to project for fonts
  std::filesystem::current_path(
      "/Users/jackolson/Documents/Dev/C++/MandelBrot/build");

  // in order to rescale and not change the orientation
  sf::View view;
  view.setSize({float(window.getSize().x), float(window.getSize().y)});
  view.setCenter({window.getSize().x / 2.f, window.getSize().y / 2.f});
  window.setView(view);

  Graph graph(window, 4);

  MandelBrot set;
  set.loop(graph, window);

  const sf::Font font("../fonts/Ancient.ttf");
  sf::Text numText(font);
  numText.setFillColor(sf::Color::White);
  numText.setCharacterSize(30);
  numText.setPosition({0, 0});

  // main loop
  while (window.isOpen()) {
    numText.setString(std::to_string(set.getInit().getReal()) + " + i" +
                      std::to_string(set.getInit().getImaginary()));

    // define events here
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (event->is<sf::Event::Resized>()) {
        handleResize(window, view, graph);
      }
      handleKeyInputs(window, graph, set);

      window.clear();

      // draw here
      graph.drawAxes(window);
      graph.drawPoints(window);
      window.draw(numText);

      window.display();
    }
  }
}

void handleResize(sf::RenderWindow &win, sf::View &view, Graph &graph) {
  sf::Vector2u currWinSize = win.getSize();

  view.setSize({float(currWinSize.x), float(currWinSize.y)});
  view.setCenter({currWinSize.x / 2.f, currWinSize.y / 2.f});

  sf::Vector2f oldOrigin = graph.getOrigin();

  graph.setOrigin(win, {0, 0});

  win.setView(view);
}

void handleKeyInputs(sf::RenderWindow &window, Graph &graph, MandelBrot &set) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    set.setInit(ComplexNumber(set.getInit().getReal(),
                              set.getInit().getImaginary() + 0.1));
    set.loop(graph, window);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    set.setInit(ComplexNumber(set.getInit().getReal() + 0.1,
                              set.getInit().getImaginary()));
    set.loop(graph, window);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
    set.setInit(ComplexNumber(set.getInit().getReal(),
                              set.getInit().getImaginary() - 0.1));
    set.loop(graph, window);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    set.setInit(ComplexNumber(set.getInit().getReal() - 0.1,
                              set.getInit().getImaginary()));
    set.loop(graph, window);
  }
}
