#ifndef __ANNEALING_HPP__
#define __ANNEALING_HPP__

#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Annealing {
  private:
    double_t temperature;
    double_t energy(std::vector<sf::CircleShape>&);
    std::pair<size_t, size_t> change_state(std::vector<sf::CircleShape>&);

  public:
    Annealing();
    void run(sf::RenderWindow&, std::vector<sf::CircleShape>&);
};

#endif
