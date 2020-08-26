#include "Tile.hpp"

Tile::Tile(float x, float y, float gridSize)
{
  this->shape.setFillColor(sf::Color::Green);
  this->shape.setPosition(x, y);
  this->shape.setSize(sf::Vector2f(gridSize, gridSize));
}

Tile::~Tile() {}
void Tile::update() {}
void Tile::render(sf::RenderTarget* target)
{
  target->draw(shape);
}