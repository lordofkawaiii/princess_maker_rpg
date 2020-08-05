#pragma once

#include "State.hpp"
#include "UI/PauseMenu.hpp"
#include "entities/Player.hpp"

class GameState : public State
{
private:
  void initKeyBinds();

protected:
  Player*            player;
  sf::RectangleShape background;
  PauseMenu*         pauseMenu;

public:
  GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
            std::stack<State*>* states);
  ~GameState();

  void update(float dt);
  void updatePlayerInput(float dt);
  void updateGeneralInput(float dt);
  void render(sf::RenderTarget* target = nullptr);
  void initTextures();
  void initPlayer();
  void setBackground();
};
