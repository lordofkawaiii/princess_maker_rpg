#pragma once

#include "states/GameState.hpp"
#include "states/MainMenuState.hpp"

class Game
{
private:
  //variables
  sf::RenderWindow* renderWindow;
  sf::Event         event;
  Settings          graphicsSettings;
  //delta time
  sf::Clock dtClock;
  float     dt;

  std::map<std::string, int> supportedKeys;

  //states to handle menus
  std::stack<State*> states;

  //initializer
  void initWindow();
  void initState();
  void initKeys();
  void initSettings();

public:
  Game();
  ~Game();
  void updateDt();
  void updateSFMLevents();
  void update();
  void render();
  void run();
  void endApp();
};
