#include <visualization.hpp>
#include <annealing.hpp>
Visualization::Visualization() :
  main_window(sf::VideoMode::getDesktopMode(), "Salesman problem visualization", sf::Style::Default),
  kPointColor(sf::Color::Red), kPointRadius(10), kMaxPoints(1000) {}

void Visualization::run() {
  bool annealing_start = false;
  while (main_window.isOpen()) {
    sf::Event event;

    while (main_window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          main_window.close();
        break;

        case sf::Event::MouseButtonPressed:
          points.push_back(sf::CircleShape(kPointRadius));
          points.back().setPosition(event.mouseButton.x, event.mouseButton.y);
          points.back().setFillColor(kPointColor);
        break;

        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Enter) {
            annealing_start = true;
          }
        break;

      }
    }

    if (annealing_start || points.size() >= kMaxPoints) {
        annealing_start = true;
        Annealing anneal_proc;
        anneal_proc.run(main_window, points);
    }
    main_window.clear();

    for (auto cur_point : points) main_window.draw(cur_point);

    for (size_t i = 0; i + 1 < points.size(); i++) {
      auto prev_point = points[i].getPosition();
      auto next_point = points[i + 1].getPosition();
      sf::Vertex line[] = {sf::Vertex(prev_point), sf::Vertex(next_point)};

      main_window.draw(line, 2, sf::Lines);
    }
    main_window.display();
  }
}
