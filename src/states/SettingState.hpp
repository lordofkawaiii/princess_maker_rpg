#pragma once
#include "StateWButtons.hpp"
#include "UI/Button.hpp"

class SettingState : public StateWButtons
{
private:
  std::map<std::string, DropDown*> dropDownLists;

public:
  SettingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
               std::stack<State*>* states);
  ~SettingState();
  void update(float dt);
  void updateGeneralInput(float dt);
  void initKeyBinds();
  void render(sf::RenderTarget* target);
};
