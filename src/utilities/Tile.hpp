#pragma once
#include "PCH.hpp"
class Tile
{
private:
  sf::RectangleShape shape;

public:
  Tile(float x, float y, float gridSize);
  ~Tile();
  void update();
  void render(sf::RenderTarget* target);
};
