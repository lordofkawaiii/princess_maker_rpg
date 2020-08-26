#pragma once
#include "State.hpp"
#include "UI/PauseMenu.hpp"

class StateWPause : public State
{
protected:
  PauseMenu* pauseMenu;

public:
  StateWPause(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
              std::stack<State*>* states);
  ~StateWPause();
  bool                 hasButtons();
  std::vector<Button*> getButtons();
  void                 resizeAll();
};