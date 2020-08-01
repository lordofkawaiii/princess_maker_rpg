#pragma once

#include "Entity.hpp"

class Player : public Entity
{
private:
  std::string dir;

public:
  Player(float x, float y, sf::Texture* texture);
  ~Player();
  void initVariables();
  void initComponents();
  void update(float dt);
};
