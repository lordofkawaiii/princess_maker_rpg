#pragma once
#include "State.hpp"

class SettingState : public State
{
private:
  /* data */
public:
  SettingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
               std::stack<State*>* states);
  ~SettingState();
};
