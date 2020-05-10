#ifndef __VISUALIZATION__HPP__
#define __VISUALIZATION__HPP__

#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

class Visualization {
  private:
    const size_t kMaxPoints;
    const sf::Color kPointColor;
    const float_t kPointRadius;
    std::vector<sf::CircleShape> points;
    sf::RenderWindow main_window;
  public:
    Visualization();
    void run();
};

#endif
