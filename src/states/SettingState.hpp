#pragma once
#include "StateWButtons.hpp"
#include "UI/Button.hpp"
#include "utilities/Settings.hpp"

class SettingState : public StateWButtons
{
private:
  std::map<std::string, DropDown*> dropDownLists;
  std::vector<sf::Text>            optionTexts;
  std::vector<sf::VideoMode>       modes;
  Settings                         settings;

public:
  SettingState(sf::RenderWindow* window, Settings settings,
               std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
  ~SettingState();
  void update(float dt);
  void updateGeneralInput(float dt);
  void initKeyBinds();
  void initText();
  void render(sf::RenderTarget* target);
  void resizeAll();
  void init();
};
