#pragma once
#include "PCH.hpp"
class Settings
{
private:
  /* data */
public:
  sf::VideoMode              resolution;
  bool                       fullscreen;
  bool                       vSync;
  unsigned                   frameRateLimit;
  sf::ContextSettings        context;
  std::vector<sf::VideoMode> videoModes;
  std::string                title;
  Settings();
  ~Settings();
  void saveToFile(std::string path);
  void loadFromFile(std::string path);
};