#include <annealing.hpp>

Annealing::Annealing() : temperature(100)
{
  srand(time(NULL));
}

double_t Annealing::energy(std::vector<sf::CircleShape>& points) {
  double_t _energy = 0;
  for (size_t i = 0; i + 1 < points.size(); i++) {
    auto prev_point = points[i].getPosition();
    auto next_point = points[i + 1].getPosition();
    _energy +=  sqrt((prev_point.x - next_point.x) * (prev_point.x - next_point.x) +
                  (prev_point.y - next_point.y) * (prev_point.y - next_point.y));
  }
  return _energy;
}

std::pair<size_t, size_t> Annealing::change_state(std::vector<sf::CircleShape>& points) {
  size_t i = 0;
  size_t j = 0;
  while (i == j) {
    i = rand() % points.size();
    j = rand() % points.size();
  }
  return {i, j};
}

void Annealing::run(sf::RenderWindow& window, std::vector<sf::CircleShape>& points) {
  double_t current_energy = energy(points);
  while (temperature > 1) {
    temperature *= 0.99;
    auto [index1, index2] = change_state(points);
    std::swap(points[index1], points[index2]);

    auto delta = energy(points) - current_energy;

    if (delta < 0) {
      current_energy += delta;
    }
    else {
      double_t probability = 1.0 / (1.0 + exp(delta / temperature));
      if (probability > 0.5) {
        current_energy += delta;
      }
      else {
        std::swap(points[index1], points[index2]);
      }
    }
    window.clear();

    for (auto cur_point : points) window.draw(cur_point);

    for (size_t i = 0; i + 1 < points.size(); i++) {
      auto prev_point = points[i].getPosition();
      auto next_point = points[i + 1].getPosition();
      sf::Vertex line[] = {sf::Vertex(prev_point), sf::Vertex(next_point)};

      window.draw(line, 2, sf::Lines);
    }
    window.display();


  }
}
