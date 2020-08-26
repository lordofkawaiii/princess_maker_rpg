#pragma once

#include "Button.hpp"
#include "PCH.hpp"
#include "states/SettingState.hpp"
#include "states/State.hpp"

class PauseMenu
{
protected:
  sf::RectangleShape             bckground;
  sf::RectangleShape             container;
  std::map<std::string, Button*> buttons;
  std::vector<std::string>       button_order;
  sf::Font                       font;
  sf::Text                       pauseText;
  State*                         origin;

public:
  PauseMenu(State* state);
  ~PauseMenu();
  void update();
  void initFont();
  void addButton(float x, float y, float width, float height, std::string text,
                 sf::Font* font, unsigned int charSize, sf::Color idleText,
                 sf::Color hoverText, sf::Color activeText, sf::Color idleColor,
                 sf::Color hoverColor, sf::Color activeColor);
  void updateButtons();
  void initPlayer();
  void render(sf::RenderTarget* target);
  std::map<std::string, Button*> getButtons();
};
