#include "Tile.hpp"

class TileMap
{
private:
  std::vector<std::vector<std::vector<Tile>>> map;
  //      x            y          z
  sf::Vector2u maxSize;
  unsigned     gridSize;
  unsigned     layers;

public:
  TileMap();
  ~TileMap();
};