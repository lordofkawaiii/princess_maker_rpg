#pragma once

#include "Entity.hpp"

class Player : public Entity
{
private:
  //variables
public:
  Player(float x, float y, sf::Texture* texture);
  ~Player();
  void initVariables();
  void initComponents();
};
