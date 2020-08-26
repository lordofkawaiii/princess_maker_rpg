#include "TileMap.hpp"
TileMap::TileMap(/* args */)
{
  this->gridSize = 50;
  this->maxSize.x = 100;
  this->maxSize.y = 100;
  this->layers = 5;
  for (size_t i = 0; i < maxSize.x; i++)
  {
    map.push_back(std::vector<std::vector<Tile>>());
    for (size_t j = 0; j < maxSize.y; j++)
    {
      map.at(i).push_back(std::vector<Tile>());
      for (size_t k = 0; k < layers; k++)
      {
        map.at(i).at(j).push_back(Tile(i * gridSize, j * gridSize, gridSize));
      }
    }
  }
}

TileMap::~TileMap() {}

void TileMap::update() {}
void TileMap::render(sf::RenderTarget* target)
{
  for (auto&& i : map)
  {
    for (auto&& j : i)
    {
      for (auto&& k : j)
      {
        k.render(target);
      }
    }
  }
}